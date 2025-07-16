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
  vector<int> deg(n + 1, 0);
  int leafs = 0;

  for(int i = 0; i < n - 1 ; i++){
    int u, v; cin >> u >> v;
    deg[u]++, deg[v]++;
    leafs += (deg[u] == 1) - (deg[u] == 2) + (deg[v] == 1) - (deg[v] == 2);
  }
  if(leafs == 2) cout << 2 * n - 1 << endl;
  else{
    cout << n + 1 << endl;
  }
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