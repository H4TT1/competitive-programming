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
 
vector<ll> dp1(MAX6 + 1, -1);
vector<ll> dp2(MAX6 + 1, -1);


void solve(){
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

  dp1[1] = 1;
  dp2[1] = 1;

  for(int i = 2; i <= MAX6; i++){
    dp1[i] = (2 * dp1[i - 1] + dp2[i - 1]) % MOD;
    dp2[i] = (4 * dp2[i - 1] + dp1[i - 1]) % MOD;
  }

// testcases
  int t = 1; cin >> t;
  while(t--){
    int n; cin >> n;

    cout << (dp1[n] + dp2[n]) % MOD << endl;
    //solve();
  }
  return 0;
 
}