#include <bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define WTFMOD 676767677
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
  int dp[4] = {0, 0, 0, 0};
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  dp[0] = 1;

  for(int i = 0; i < n; i++){
    if(a[i] == 2) dp[2] = (2 * dp[2]) % MOD2;
    dp[a[i]] = (dp[a[i]] + dp[a[i]-1]) % MOD2;
  }

  cout << dp[3] << endl;

  /*
  given a, we want the nbr of btfl subsequences.
  - observations:
    * btfl => not start with 3 or end with 1
      general pattern?
      if there is 3 it should be only one at the end and the form is 12...23
      if there is no 3, ooo impossible
    
      clc : 12...23 is the only btfl

      we clculate prefs of 1s freqs, and suffs of 3s freqs
      then the sol is the sum of res for each succession of 2s,
      contribution(l, r) = (2^(r-l+1) - 1) * pref[l-1] * suff[r+1]  
    
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
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}