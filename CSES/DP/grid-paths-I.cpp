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
  int n; cin >> n;
  string grid[n];

  for(int i = 0; i < n; i++) cin >> grid[i];

  int dp[n][n];
  if(grid[0][0] == '*'){
    cout << 0 << endl;
    return;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1; i < n; i++){
    if(grid[i-1][0] == '*') dp[i][0] = 0;
    else dp[i][0] = dp[i-1][0];

    if(grid[0][i-1] == '*') dp[0][i] = 0;
    else dp[0][i] = dp[0][i-1];
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      if(grid[i][j] == '.'){
        if(grid[i-1][j] == '.') dp[i][j] += dp[i-1][j], dp[i][j] %= MOD;
        if(grid[i][j-1] == '.') dp[i][j] += dp[i][j-1], dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[n-1][n-1] << endl;

  /*
  */



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