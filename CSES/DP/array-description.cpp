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
  int n, m; cin >> n >> m;
  vector<int> x(n);

  for(int i = 0; i < n; i++) cin >> x[i];

  int dp[n][m + 1]; // dp[i][j] = solution for ith prefix s.t : last element is j
  memset(dp, 0, sizeof(dp));

  if(x[0] == 0){
    for(int i = 1; i <= m; i++) dp[0][i] = 1;
  }
  else{
    dp[0][x[0]] = 1;
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j <= m; j++){
      if(x[i] == 0 or x[i] == j){
        dp[i][j] = dp[i-1][j];
        if(j + 1 <= m) dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
        if(j - 1 >= 1) dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
      }
    }
  }

  // for(int i = 0; i < n; i++){
  //   for(int j = 1; j <= m; j++){
  //     cout << "(" << i << "," << j << ") = " << dp[i][j] << endl;
  //   }
  // }
  ll ans = 0;
  for(int i = 1; i <= m; i++) ans += dp[n-1][i], ans %= MOD;

  cout << ans << endl;
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