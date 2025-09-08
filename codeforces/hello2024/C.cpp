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
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  
  vector<int> s, t;

  if(n <= 2){
    cout << 0 << endl;
    return;
  }

  s.pb(a[0]);
  t.pb(20000001);

  int ans = 0;

  for(int i = 1; i < n; i++){
    if(a[i] <= min(s.back(),t.back())){
      if(s.back() <= t.back()) s.pb(a[i]);
      else t.pb(a[i]);
    }
    else if(a[i] > max(s.back(), t.back())){
      if(s.back() > t.back()) s.pb(a[i]), ans++;
      else t.pb(a[i]), ans++;
    }
    else if(a[i] <= s.back()) s.pb(a[i]);
    else t.pb(a[i]); 
  }

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
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}