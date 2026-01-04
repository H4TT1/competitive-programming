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
  int s1 = 0, s2 = 0, ones = 0, seno = 0;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  int b[n]; for(int i = 0; i < n; i++){
    cin >> b[i];
    if(a[i] > b[i]) s1 += a[i];
    else if(a[i] < b[i]) s2 += b[i];
    else{
      if(a[i] == 1) ones++;
      else if(a[i] == -1) seno++;
    }
  }
  while(ones--){
    if(s1 < s2) s1++;
    else s2++;
  }
  while(seno--){
    if(s1 > s2) s1--;
    else s2--;
  }

  cout << min(s1, s2) << endl;
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