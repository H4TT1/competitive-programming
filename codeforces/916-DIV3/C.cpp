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

void solve(){
  int n; cin >> n;
  vector<pair<int,pair<int, int>>> v(n);

  for(int i = 0; i < n; i++) cin >> v[i].S.F;
  for(int i = 0; i < n; i++){
    cin >> v[i].S.S;
    v[i].F = v[i].S.S + v[i].S.F;
  }

  sort(v.begin(), v.end());

  ll ans = 0;

  for(int i = n-1; i >= 0; i--){
    if((n - i - 1)%2 == 0) ans += v[i].S.F-1;
    else ans -= v[i].S.S-1;
  }

  cout << ans << endl;
  /*
  1
  -9
  2999999997
  8
  -6
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