#include <bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
 
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000, MAXN = 1000000000;
const int INF = 1000000000;
const int MAXB = 8005;
int n;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  cin >> n;
  vector<bitset<MAXB>> reach(n + 1);
  for(int i = 1; i <= n; i++){
    string s; cin >> s;
    for(int j = 1; j <= n; j++){
      if(s[j - 1] == '1') reach[i].set(j);
    }
  }

  for(int i = 1; i <= n; i++){
    if(!reach[i].test(i)){
      cout << "NO\n";
      return;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(reach[i].test(j) && reach[j].test(i)){
        cout << "NO\n";
        return;
      }
    }
  }

  vector<int> sz(n + 1, 0);
  for(int i = 1; i <= n; i++) sz[i] = (int)reach[i].count();

  vector<int> order(n);
  iota(order.begin(), order.end(), 1);
  sort(order.begin(), order.end(), [&](int a, int b){
    if(sz[a] != sz[b]) return sz[a] > sz[b];
    return a < b;
  });

  vector<pi> edges;
  edges.reserve(n - 1);

  for(int u = 1; u <= n; u++){
    bitset<MAXB> covered;
    for(int v : order){
      if(v == u) continue;
      if(!reach[u].test(v)) continue;
      if(covered.test(v)) continue;
      edges.pb({u, v});
      if((int)edges.size() > n - 1){
        cout << "NO\n";
        return;
      }
      covered |= reach[v];
    }
  }

  if((int)edges.size() != n - 1){
    cout << "NO\n";
    return;
  }

  vector<vi> und(n + 1), out(n + 1);
  for(auto &e : edges){
    und[e.F].pb(e.S);
    und[e.S].pb(e.F);
    out[e.F].pb(e.S);
  }

  vector<int> vis(n + 1, 0);
  queue<int> q;
  q.push(1); vis[1] = 1;
  int cnt = 1;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int nxt : und[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      cnt++;
      q.push(nxt);
    }
  }
  if(cnt != n){
    cout << "NO\n";
    return;
  }

  for(int s = 1; s <= n; s++){
    bitset<MAXB> got;
    stack<int> st;
    st.push(s);
    got.set(s);
    while(!st.empty()){
      int cur = st.top(); st.pop();
      for(int nxt : out[cur]){
        if(got.test(nxt)) continue;
        got.set(nxt);
        st.push(nxt);
      }
    }
    if(got != reach[s]){
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  for(auto &e : edges){
    cout << e.F << " " << e.S << "\n";
  }
}
 
int main(){
  // in & out files
  /*
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
*/
  // fast and furious io
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

// testcases
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}
