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

void solve()
{
  int n; cin >> n;
  int p[n + 1]; for(int i = 1; i <= n; i++) cin >> p[i];
  int d[n + 1]; for(int i = 1; i <= n; i++) cin >> d[i];

  vector<bool> vis(n + 1, false);
  int parent[n + 1];
  int size[n + 1];

  for(int i = 1; i <= n; i++){
    int curr = p[i], sz = 0;
    if(!vis[curr]){
      parent[curr] = curr;
      while(!vis[curr]){
        vis[curr] = true;
        sz++;
        parent[p[curr]] = parent[curr];
        curr = p[curr];
      }
      size[parent[curr]] = sz;
    }
  }

  //cout << "size ! \n";
  //for(int i = 1; i <= n; i++) cout << size[parent[i]] << " ";
  //cout << endl; 
  vector<bool> processed(n + 1, false);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(!processed[parent[p[d[i]]]]){
      processed[parent[p[d[i]]]] = true;
      ans += size[parent[p[d[i]]]];
    }
    cout << ans << " ";
  }
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