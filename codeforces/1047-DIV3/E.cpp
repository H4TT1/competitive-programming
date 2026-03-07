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
const int MAXA = 200100;
int n, k, a[MAXA], freq[MAXA];
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  cin >> n >> k;
  if(k >= 2){
    k -= 2;
    k %= 2;
    k += 2;
  }

  for(int i = 1; i <= n; i++) cin >> a[i];

  int l = n + 2;
  while(k--){
    for(int i = 0; i <= l; i++) freq[i] = 0;
    for(int i = 1; i <= n; i++) freq[a[i]]++;

    int mex = 0;
    while(freq[mex]) mex++;

    for(int i = 1; i <= n; i++){
      if(freq[a[i]] == 1) a[i] = min(a[i], mex);
      else a[i] = mex;
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) ans += a[i];
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
