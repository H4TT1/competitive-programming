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
int n;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  cin >> n;
  vector<int> c(n + 1), p(n + 1);
  for(int i = 1; i <= n; i++) cin >> c[i] >> p[i];
  double g = 0.0;
  for(int i = n; i >= 1; i--){
    double q = 1.0 - p[i] / 100.0;
    double take = c[i] + q * g;
    if(take > g) g = take;
  }
  cout << fixed << setprecision(10) << g << "\n";
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
