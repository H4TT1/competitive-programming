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
/*
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

vector<pair<int, int>> ans;

void rec_solve(int k, int x0, int y0){
  if(k == 0) return;
  int sup = 0;
  while(sup * (sup - 1) <= 2 * k) sup++;
  sup--;
  for(int i = 0; i < sup; i++) ans.pb({x0 + i, y0});
  rec_solve(k - ((sup-1)*sup)/2, x0 + sup, y0 + 1);
}

void solve(){
  int k; cin >> k;
  /*
    p(i,j) = d(i,j) <=> xa = xb or ya = yb
  */
  rec_solve(k, 0, 0);
  int n = ans.size();
  cout << n << endl;
  for(auto u : ans) cout << u.F << " " << u.S << endl;
  ans.clear();
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
  while(t--)
    solve();
  return 0;

}
