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
ll const INF = 1e15;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
int n;
int bestPartner(vector<long>& v, long x){
  int pos = 0, best = abs(x - v[0]);
  for(int i = 1; i < n; i++){
    if(best > abs(x - v[i])){
      pos = i;
      best = abs(x - v[i]);
    }
  }
  return pos;
}


void solve(){
  cin >> n;
  vector<long> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  vector<int> poss1 = {0, bestPartner(b, a[0]), n-1};
  vector<int> poss2 = {0, bestPartner(b, a[n-1]), n-1};

  ll ans = INF;
  for(auto p : poss1){
    for(auto q : poss2){
      ll cost = abs(a[0] - b[p]) + abs(a[n-1] - b[q]);
      if(p > 0 && q > 0) cost += abs(a[bestPartner(a, b[0])] - b[0]);
      if(p < n-1 && q < n-1) cost += abs(a[bestPartner(a, b[n-1])] - b[n-1]);

      ans = min(ans, cost);
    }
  }

  cout << ans << endl;

  /*
    let s call that netwrok an FTN:
      - 2 connected rows, if u connect only one pair, it s not enough (u can disconnect a pair element).
      2 pairs? enough? not if corners are not connected
      so we connect all the corners to their opposite row!!! we can try kolchi (bruteforce)

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