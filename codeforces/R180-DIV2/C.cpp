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
void solve()
{
  int n; cin >> n;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n);

  ll ans = 0;
  for(int z = 0; z < n; z++){
    for(int y = 1; y < z; y++){

      int l = 0, r = y - 1, x = -1;
      while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] + a[y] + a[z] > max(2 * a[z], a[n-1])){
          r = mid-1;
          x = mid;
        }
        else{
          l = mid + 1;
        }
      }

      if(x != -1) ans += (y - x);
    }
  }

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