#include <bits/stdc++.h>
#include <cstring>
 
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

void solve(){
  // cout << "new tc" << endl;
  int n; cin >> n;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  
  set<int> tree[n];
  int  u, v;
  char ans[n];
  memset(ans, (int) '0', n);
  assert(ans[0] == '0'); // don t trust memset

  for(int i = 0; i < n - 1; i++){
    cin >> u >> v;
    u--, v--;
    if(a[u] == a[v]) ans[a[u]-1] = '1';
    else{
      if(tree[u].find(a[v]-1) != tree[u].end()) ans[a[v]-1] = '1'; // cout << "haha" << a[v] << endl;
      if(tree[v].find(a[u]-1) != tree[v].end()) ans[a[u]-1] = '1'; // cout << "hihi" << a[u] << endl;
    }
    
    tree[u].insert(a[v]-1);
    tree[v].insert(a[u]-1);
  }

  for(int i = 0; i < n; i++) cout << ans[i];
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
  int t = 1; cin >> t;
  while(t--){
    solve();
  }
  return 0;

}


