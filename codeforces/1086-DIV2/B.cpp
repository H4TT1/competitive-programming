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
const int INF = 1000000000;
int n, k, p, m;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  cin >> n >> k >> p >> m;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  int w = a[p];

  int need_before = max(0, p - k);
  ll sum_before = 0;
  if(need_before > 0){
    vector<int> before;
    before.reserve(p - 1);
    for(int i = 1; i < p; i++) before.pb(a[i]);
    sort(before.begin(), before.end());
    for(int i = 0; i < need_before; i++) sum_before += before[i];
  }

  ll cost_first = sum_before + w;
  if(cost_first > m){
    cout << 0 << '\n';
    return;
  }

  int need_cycle = max(0, n - k);
  ll sum_cycle = 0;
  if(need_cycle > 0){
    vector<int> others;
    others.reserve(n - 1);
    for(int i = 1; i <= n; i++) if(i != p) others.pb(a[i]);
    sort(others.begin(), others.end());
    for(int i = 0; i < need_cycle; i++) sum_cycle += others[i];
  }

  ll cycle_cost = sum_cycle + w;
  ll rem = m - cost_first;
  ll ans = 1 + rem / cycle_cost;
  cout << ans << '\n';
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
