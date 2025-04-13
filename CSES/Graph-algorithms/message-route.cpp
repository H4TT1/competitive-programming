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
*/
vector<int> adj[MAX5 + 1];
int visited[MAX5 + 1];
 
void solve(){
  int n, m; cin >> n >> m;
  
  memset(visited, 0, sizeof(visited));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
 
  queue<int> q;
  int parent[n + 1];
  int d[n + 1];
  memset(d, -1, sizeof(d));
  d[1] = 0;
  q.push(1);
  visited[1] = 1;
  
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto v : adj[curr]){
      if(!visited[v]){
        visited[v] = 1;
        q.push(v);
        parent[v] = curr;
        d[v] = d[curr] + 1;
      }
    }
  }
 
  if(d[n] == -1){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << d[n] + 1 << endl;
    vector<int> path;
    int curr = n;
    path.pb(curr);
    for(int i = 0; i < d[n]-1; i++){
      curr = parent[curr];
      path.pb(curr);
    }
    cout << 1 << " ";
    for(int i = d[n]-1; i >= 0; i--){
      cout << path[i] << " ";
    }
    cout << endl;
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