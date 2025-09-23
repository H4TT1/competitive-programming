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
  int a, b; cin >> a >> b;

  int dp[501][501];

  for(int i = 1; i <= 500; i++){
    for(int j = 1; j <= 500; j++){
      dp[i][j] = MAX6;
    }
  }

  for(int i = 1; i <= a; i++){
    for(int j = 1; j <= b; j++){
      if(i == j) dp[i][j] = 0;
      else{
        // vertical cut
        for(int v = 1; v < i; v++){
          dp[i][j] = min(dp[i][j], 1 + dp[i-v][j] + dp[v][j]);
        }

        // horizontal cut
        for(int h = 1; h < j; h++){
          dp[i][j] = min(dp[i][j], 1 + dp[i][j-h] + dp[i][h]);
        }
      }
    }
  }

  cout << dp[a][b] << endl;
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