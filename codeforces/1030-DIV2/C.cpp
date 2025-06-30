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
 idea : greedily make the minimum sufficient number of operation to increase the beauty of an element
*/

ll pow2[80];

void solve()
{
  ll n, k; cin >> n >> k;
  ll a[n]; for(int i = 0; i < n; i++) cin >> a[i];


  while(true){
    int mino = 79, min_idx = -1;
    for(int i = 0; i < n; i++){
      int tmp = __countr_one(a[i]);
      if(tmp < mino){
        mino = tmp;
        min_idx = i;
      }
    }
    if(k >= pow2[mino]){
      a[min_idx] += pow2[mino];
      k -= pow2[mino];
    }
    else break;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) ans += __popcount(a[i]);
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

  // precomputing powers of 2

  pow2[0] = 1;
  for(int i = 1; i < 80; i++) pow2[i] = pow2[i-1]*2;


 
// testcases
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}