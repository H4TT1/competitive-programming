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
  vector<int> a1(n), a2(n);

  vector<vector<int>> indices1(2 * n + 1);
  vector<vector<int>> indices2(2 * n + 1);

  for(int i = 0; i < n; i++) cin >> a1[i], indices1[a1[i]].pb(i);
  for(int i = 0; i < n; i++) cin >> a2[i], indices2[a2[i]].pb(i);

  set<int> s1, s2; // deactivated values in row 1 , 2 resp.

  int l = 1, r = 1;

  // sentinels prevent empty-set dereference:
  // s1: first blocked index in top row, defaults to n (no blocked cell).
  // s2: last blocked index in bottom row, defaults to -1 (no blocked cell).
  s1.insert(n);
  s2.insert(-1);

  for(int i = 0; i < n; i++){
    if(a1[i] != 1) s1.insert(i);
    if(a2[i] != 1) s2.insert(i);
  }

  ll ans = 0;
  while(l <= 2 * n){
    int off1 = *s1.begin();
    int off2 = *prev(s2.end());

    if(off1-1 > off2){
      ans += (2 * n - r + 1);
      for(auto x : indices1[l]) s1.insert(x);
      for(auto x : indices2[l]) s2.insert(x);
      l++;
      if(r == l-1 && r < 2 * n){
        r++;
        for(auto x : indices1[r]) s1.erase(x);
        for(auto x : indices2[r]) s2.erase(x);
      }

    }
    else{
      if(r == 2 * n) break;
      r++;
      for(auto x : indices1[r]) s1.erase(x);
      for(auto x : indices2[r]) s2.erase(x);
    }
  }

  cout << ans << endl;

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
