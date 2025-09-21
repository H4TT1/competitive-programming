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
 

string a, b;
vector<vector<int>> cache(5001, vector<int>(5001, -1));

int dp(int i, int j){
  if(j < 0 or i < 0) return max(i+1, j+1);
  if(cache[i][j] != -1) return cache[i][j];
  int tmp = MAX6;
  if(a[i] == b[j]) tmp = dp(i-1, j-1);

  tmp = min(tmp, dp(i-1, j) + 1);
  tmp = min(tmp, dp(i, j-1) + 1);
  tmp = min(tmp, dp(i-1, j-1) + 1);

  return cache[i][j] = tmp;
}


void solve(){
  cin >> a >> b;

  int n = a.length(), m = b.length();
  cout << dp(n-1, m-1) << endl;

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
  int t = 1; // cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}