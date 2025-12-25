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
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long



void solve(){
  int n; cin >> n;
  int minpref[n], maxsuff[n];
  int p[n]; for(int i = 0; i < n; i++) cin >> p[i];

  minpref[0] = p[0];
  maxsuff[n-1] = p[n-1];

  for(int i = 1; i < n; i++) minpref[i] = min(minpref[i-1], p[i]);
  for(int i = n-2; i >= 0; i--) maxsuff[i] = max(maxsuff[i+1], p[i]);

  for(int i = 1; i < n-1; i++){
    if(minpref[i-1] > maxsuff[i+1]){
      cout << "no" << endl;
      return;
    }
  }


  if(p[0] == n or p[n-1] == 1){
    cout << "no" << endl;
  }
  else
    cout << "yes" << endl;

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
  int t = 1; cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}