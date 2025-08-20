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

void solve(){
  int n; cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  int ans = 0;

  for(int i = 0; i < n; i++){
    int lbig = 0, rbig = 0;
    for(int j = 0; j < i; j++){
      if(p[j] > p[i]) lbig++;
    }

    for(int j = i+1; j < n; j++){
      if(p[j] > p[i]) rbig++;
    }
    ans += min(lbig, rbig);
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