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
  int n, m, l; cin >> n >> m >> l;
  int a[n]; 
  for(int i = 0; i < n; i++) cin >> a[i];
  int d[m];
  memset(d, 0, sizeof(d));
  int flash = n;

  for(int i = 0; i < l; i++){
    d[min(m, flash+1) - 1]++;
    sort(d, d+m);
    reverse(d, d+m);
    if(flash > 0 && a[n-flash] - 1 == i){
      d[0] = 0;
      sort(d, d+m);
      reverse(d, d+m);
      flash--;
    }
  }
  cout << d[0] << endl;
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