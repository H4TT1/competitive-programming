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

int vis[2 * MAX5 + 1];
ll dpmin[MAX5 + 1], dpmax[MAX5 + 1];

void dfs(int u, int p, ll* a, vector<int>* tree){
  if(vis[u]) return;
  vis[u] = true;

  if(u != 0){
    dpmin[u] = min(a[u], a[u] - dpmax[p]);
    dpmax[u] = max(a[u], a[u] - dpmin[p]);
  }

  for(auto v : tree[u]) dfs(v, u, a, tree);
}

void solve(){
  int n; cin >> n;
  ll a[n]; for(int i = 0; i < n; i++){cin >> a[i]; vis[i] = false;}

  vector<int> tree[n];

  for(int i = 0; i < n-1; i++){
    int c, d; cin >> c >> d;
    c--, d--;
    tree[c].pb(d);
    tree[d].pb(c);    
  }

  dpmin[0] = dpmax[0] = a[0];
  dfs(0, 0, a, tree);

  for(int i = 0; i < n; i++) cout << dpmax[i] << " ";
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
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}