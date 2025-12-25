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
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long



void solve(){
  int n, m, k; cin >> n >> m >> k;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
  vector<int> adj[n];
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  queue<int> q;
  int d[n], ans[k];
  int visited[n];
  memset(visited, 0, sizeof(visited));
  memset(ans, 0, sizeof(ans));
  d[0] = 0;
  visited[0] = 1;
  q.push(0);
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto curr_v : adj[curr]){
      if(!visited[curr_v]){
        visited[curr_v] = 1;
        q.push(curr_v);
        d[curr_v] = d[curr] + 1;
        ans[a[curr_v]] = max(ans[a[curr_v]], d[curr_v]);
      }
    }
  }

  for (int i = 0; i < k; i++) cout << ans[i] << " ";
  cout << endl;
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
  int t = 1; // cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}