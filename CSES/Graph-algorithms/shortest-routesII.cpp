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

const ll INF = 10000000000000;

void solve(){
  int n, m, q; cin >> n >> m >> q;
  ll dist[n+1][n+1];
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dist[i][j] = ((i == j) ? 0 : INF);
    }
  }

  for(int i = 0; i < m; i++){
    ll a, b, c; cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = dist[a][b];
  }

  // floyd-warshall
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    }
  }

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    cout << ((dist[a][b] == INF) ? -1 : dist[a][b]) << endl;
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
  int t = 1; // cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}