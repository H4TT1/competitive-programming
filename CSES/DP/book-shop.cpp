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
  int n, x; cin >> n >> x;
  int prices[n], pages[n];

  for(int i = 0; i < n; i++) cin >> prices[i];
  for(int i = 0; i < n; i++) cin >> pages[i];

  int dp[n + 1][x + 1]; // dp[i][j] = max number of pages for i first with a j budget
  memset(dp, 0, sizeof(dp)); // could have done better
  
  for(int i = 1; i <= n; i++){
    int p = pages[i - 1];
    int c = prices[i - 1];

    for(int j = 1; j <= x; j++){
      dp[i][j] = dp[i-1][j];
      if(c <= j){
        dp[i][j] = max(dp[i][j], dp[i-1][j - c] + p);
      }
    }
  }

  cout << dp[n][x] << endl;
  
  
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