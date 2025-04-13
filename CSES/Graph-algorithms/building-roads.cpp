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
int const MAX5 = 100000, MAX6 = 1000000;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
 
 
/*
  10110 => 11001
        => 00101
  01010 => 00101
 
  answer <= n
 
  if we perform k operations 
*/
vector<int> adj[MAX5 + 1];
int visited[MAX5 + 1];
 
void dfs(int u){
  if(visited[u]) return;
  visited[u] = 1;
  for(auto v : adj[u]){
    dfs(v);
  }
}
 
 
void solve(){
  int n, m; cin >> n >> m;
  
  memset(visited, 0, sizeof(visited));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  vector<int> boss;
  int ans = -1;
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      dfs(i);
      boss.pb(i);
      ans++;
    }
  }
  cout << ans << endl;
  for(int i = 0; i < boss.size() - 1; i++){
    cout << boss[i] << " " << boss[i+1] << endl;
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
  int t = 1; // cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}