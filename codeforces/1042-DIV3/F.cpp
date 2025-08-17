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
  // just implemented the editorial solution (without looking or copying the code)
  ll n; cin >> n;
  string a, b; cin >> a >> b;

  ll prea[n], preb[n];
  prea[0] = (a[0] == '0') - (a[0] == '1');
  preb[0] = (b[0] == '1') - (b[0] == '0');

  for(int i = 1; i < n; i++){
    prea[i] = prea[i-1] + (a[i] == '0') - (a[i] == '1');
    preb[i] = preb[i-1] + (b[i] == '1') - (b[i] == '0');
  }

  sort(prea, prea + n);
  sort(preb, preb + n);

  int y = 0;
  ll ans = 0;

  for(int x = 0; x < n; x++){
    while(y < n && preb[y] < prea[x]){
      y++;
    }
    ans += (2*y - n)*prea[x];
  }

  y = 0;
  for(int x = 0; x < n; x++){
    while(y < n && prea[y] <= preb[x]){
      y++;
    }
    ans += (2*y - n)*preb[x];
  }
  assert(ans % 2 == 0);

  ans = (n*n*(n + 1))/2  - ans/2;
  cout << ans << endl;
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