#include <bits/stdc++.h>
#include <cassert>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define vi vector<int>
#define pi pair<int,int>
 
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000;
/*
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


void Solution(){
  string a, b, c; cin >> a >> b >> c;

  int lena = a.length(), lenb = b.length();
  // dp idea

  int dp[lena + 1][lenb + 1];
  dp[0][0] = 0;
  memset(dp, 1e9, sizeof(dp));
  // trivial states
  for(int i = 1; i <= lena; i++){
    dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1]);
  }

  for(int i = 1; i <= lenb; i++){
    dp[0][i] = dp[0][i-1] + (b[i-1] != c[i-1]);
  }

  //assert(dp[1][0] <= 1);
  //assert(dp[0][1] <= 1);
  //a[0], b[0], c[0]c[1]
  // cout << dp[1][1] << "< dp 1 1 " << endl;
  for(int i = 1; i <= lena; i++){
    for(int j = 1; j <= lenb; j++){
      if(c[i+j - 1] == a[i-1]){
        dp[i][j] = dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j] + 1;
      }
      if(c[i+j - 1] == b[j-1]){
        dp[i][j] = min(dp[i][j-1], dp[i][j]);
      }
      else{
        dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
      }
    }
  }
/*
  for(int i = 0; i <= lena; i++){
    for(int j = 0; j <= lenb; j++){
      printf("(%d,%d) => %d\n", i, j, dp[i][j]);
    }
  }

  */
  cout << dp[lena][lenb] << endl;
  // cout << "OK!" << endl;

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
  int t = 1; cin >> t; 
  while(t--)
    Solution();
  return 0;

}
