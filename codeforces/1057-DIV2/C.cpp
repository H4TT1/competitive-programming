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
  int n; cin >> n;
  ll a[n]; for(int i = 0; i < n; i++) cin >> a[i];

  sort(a, a+n);

  ll ans = 0;
  int chosen = 0;
  ll perim = 0;
  bool lonely[n];
  memset(lonely, true, sizeof(lonely));
  int nlonelycnt = 0;

  // only pairs
  for(int i = 0; i < n-1; i++){
    if(a[i] == a[i+1]) perim += 2 * a[i], lonely[i] = lonely[i+1] = false, i++, nlonelycnt += 2;
  } 

  if(nlonelycnt > 2) ans = max(ans, perim);

  // cout << perim << " hi" << endl;

  // one side intersection
  for(int i = n-1; i >= 0; i--){
    if(lonely[i] && a[i] < perim){
      ans = perim + a[i];
      break;
    }
  }

  // 2 sides intersection 
  ll smol = -1, big;
  for(int i = 0; i < n; i++){
    if(lonely[i]){
      if(smol == -1) smol = a[i], big = a[i];
      else{
        smol = big, big = a[i];
        if(big - smol < perim) ans = max(ans, perim + big + smol);
      }
    }
  }

  cout << ans << endl;

  /*
  goal : max perimeter of a polygon (symm, non degen, str conv)

  symm axis : line between 2 points of the polygon | 
              line between a pt and middle (milieu) of a side |
              line between 2 middles
  
  hmm sensing a dp, 

  given that a is sorted,
  if we set dp[i] = the solution for suffix [i, n],
  if ai == ai+1 then 
  dp[i] = dp[i+1] ...

  maybe not dp

  let s consider parallel bases of the polygon , eventually with 0 length
  if a side is lonely (has no brother) we can put it as a base, and since we
  we want to maximize the perimeter then we pick the big lonelies
  , wait is it not always good to choose all the brothers (one from each side of the symm axis) and pick 
  the largest 2 lonelies? hmm is it that ez tho ? 

  lets try this and then see (convex constraint is intimidating )
  

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