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
int vis[1001][1001];
int n, m;
 
bool isMonster(int x, int y, string grid[]){
  return grid[x][y] == 'M';
}

bool isFloor(int x, int y, string grid[]){
  return grid[x][y] == '.';
}
 
void solve(){
  cin >> n >> m;
  string grid[n];
  for(int i = 0; i < n; i++)
    cin >> grid[i];
 
  int d[n][m];
  memset(d, -1, sizeof(d));
  char pred[n][m];
  queue<pair<int, int>> q;
  vector<pair<int,int>> monsters;
  pair<int, int> start, end;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'A'){
        start = {i, j};
      }
      if(grid[i][j] == 'M'){
        monsters.pb({i, j});
      }
    }
  }

  int cnt_monsters = monsters.size();
 
  q.push(start);
  d[start.F][start.S] = 0;
  pair<int, int> moves[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  char ch_moves[4] = {'R', 'D', 'U', 'L'};
  int x, y;
  int monsters_in_q = 0;
  while(!q.empty()){
    pair<int, int> curr = q.front();
    x = curr.F;
    y = curr.S;
    q.pop();
    for(int i = 0; i < 4; i++){
      int dx = moves[i].F;
      int dy = moves[i].S;
      if(x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && (isFloor(x + dx, y + dy, grid) || grid[x+dx][y+dy] == 'M') && !vis[x+dx][y+dy]){
        if(!isMonster(x+dx, y+dy, grid))
          q.push({x+dx, y+dy});
        vis[x+dx][y+dy] = 1;
        d[x+dx][y+dy] = d[x][y] + 1;
        //if(x+dx == n-1 or y+dy == m-1 or x+dx == 0 or y+dy == 0)
        pred[x+dx][y+dy] = ch_moves[i];
      }
    }
  }

  bool good = false;
  int ans;
  for(int i = 0; i < n && !good; i++){
    if(d[i][0] != -1){
      end = {i, 0};
      ans = d[i][0];
      good = true;
    } 
    if(d[i][m-1] !=-1){
      end = {i, m-1};
      ans = d[i][m-1];
      good = true;
    }
  }
  for(int j = 0; j < m && !good; j++){
    if(d[0][j] != -1){
      end = {0, j};
      ans = d[0][j];
      good = true;
    }
    if(d[n-1][j] != -1){
      end = {n-1, j};
      ans = d[n-1][j];
      good = true;
    }
  }
  if(!good){
    cout << "NO" << endl;
    return;
  }

  vector<char> path;
  int currx = end.F, curry = end.S;
  for(int i = 0; i < ans; i++){
    path.pb(pred[currx][curry]);
    if(pred[currx][curry] == 'L'){
      curry++;
    }
    else if(pred[currx][curry] == 'R'){
      curry--;
    }
    else if(pred[currx][curry] == 'U'){
      currx++;
    }
    else{
      currx--;
    }
  } 
  cout << "YES" << endl;
  cout << ans << endl;
  // cout << path.size() << endl;
  for(int i = ans-1; i >= 0; i--) cout << path[i];
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