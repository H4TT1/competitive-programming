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
int n;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  cin >> n;
  vector<bitset<505>> reach(n + 1), pred(n + 1);
  for(int i = 1; i <= n; i++){
    string s; cin >> s;
    for(int j = 1; j <= n; j++){
      if(s[j - 1] == '1') reach[i].set(j);
    }
  }

  bitset<505> valid;
  for(int i = 1; i <= n; i++) valid.set(i);

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

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(!reach[i].test(j)) continue;
      bitset<505> diff = reach[j] & (~reach[i]) & valid;
      if(diff.any()){
        cout << "NO\n";
        return;
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(reach[i].test(j)) pred[j].set(i);
    }
  }

  vector<pi> edges;
  for(int u = 1; u <= n; u++){
    for(int v = 1; v <= n; v++){
      if(u == v) continue;
      if(!reach[u].test(v)) continue;
      bitset<505> inter = reach[u] & pred[v];
      inter.reset(u);
      inter.reset(v);
      if(!inter.any()){
        edges.pb({u, v});
      }
    }
  }

  if((int)edges.size() != n - 1){
    cout << "NO\n";
    return;
  }

  vector<vi> und(n + 1);
  for(auto &e : edges){
    und[e.F].pb(e.S);
    und[e.S].pb(e.F);
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
