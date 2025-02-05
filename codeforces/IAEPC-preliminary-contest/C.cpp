#include <bits/stdc++.h>
#include <cstring>
 
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
/*
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


void Solution(){
  int n; cin >> n;
  int a[n + 1]; for(int i = 1; i <= n; i++) cin >> a[i];


  // smelling dp hmm
  // dp[i] = solution for prefix i asssuming ith guy is honest
  ll dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  a[0] = 0;
  dp[1] = (a[1] == 0);

  for(int i = 2; i <= n; i++){
    if(a[i] == a[i-1])
      dp[i] = (dp[i] + dp[i-1]) % MOD2;
    if(a[i] == (a[i-2] + 1))
      dp[i] = (dp[i] + dp[i-2]) % MOD2;
  }
  //for(int i = 1; i <= n; i++) cout << dp[i] << " ";
  //cout << endl;
  cout << (dp[n] + dp[n-1]) % MOD2 << endl;
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
