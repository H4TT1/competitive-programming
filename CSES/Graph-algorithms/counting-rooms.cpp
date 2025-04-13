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
int vis[1001][1001];
int n, m;
 
bool isFloor(int x, int y, string grid[]){
  return grid[x][y] == '.';
}
 
void dfs(int x, int y, string grid[]){
  if(x < 0 || x >= n || y < 0 || y >= m) return;
  if(vis[x][y]) return;
  vis[x][y] = 1;
  if(x + 1 < n && isFloor(x+1, y, grid)) dfs(x + 1, y, grid);
  if(y + 1 < m && isFloor(x, y+1, grid)) dfs(x, y + 1, grid);
  if(x - 1 >= 0 && isFloor(x-1, y, grid)) dfs(x - 1, y, grid);
  if(y - 1 >= 0 && isFloor(x, y-1, grid)) dfs(x, y - 1, grid); 
}
 
 
void solve(){
  cin >> n >> m;
  string grid[n];
  for(int i = 0; i < n; i++)
    cin >> grid[i];
  
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(isFloor(i, j, grid) && !vis[i][j]){
        cnt++;
        dfs(i, j, grid);
      }
    }
  }
 
  cout << cnt << endl;
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