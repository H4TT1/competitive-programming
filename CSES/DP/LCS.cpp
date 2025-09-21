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


int a[1001], b[1001];
vector<vector<int>> cache(1001, vector<int>(1001, -1));
vector<int> ans;
map<pair<int, int>, pair<int, int>> succ;

int dp(int i, int j){
  // non wanted cases
  if(i < 0 or j < 0) return 0;
  
  // there is cache => use it
  if(cache[i][j] != -1) return cache[i][j];
  
  // cases
  if(a[i] == b[j]){
    succ[{i, j}] = {i-1, j-1};
    return cache[i][j] = dp(i-1, j-1) + 1;
  }

  int tmp1 = dp(i-1, j);
  int tmp2 = dp(i, j-1);

  if(tmp1 > tmp2){
    succ[{i, j}] = {i-1, j};
  }
  else{
    succ[{i, j}] = {i, j-1};
  }
  
  return cache[i][j] = max(tmp1, tmp2);
}
 

void solve(){
  int n, m; cin >> n >> m;

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  int ans = dp(n-1, m-1);

  vector<int> seq;

  pair<int, int> ij = {n-1, m-1};
  while(seq.size() != ans){
    if(a[ij.F] == b[ij.S]) seq.pb(a[ij.F]);
    ij = succ[ij];
  }

  reverse(seq.begin(), seq.end());

  cout << ans << endl;
  for(int i = 0; i < ans; i++) cout << seq[i] << " ";
  cout << endl;


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