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
struct Edge {
  int a, b, cost;
};

vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++){
    int a, b, x; cin >> a >> b >> x;
    struct Edge e = {.a = a, .b = b, .cost = -x};
    edges.pb(e);
  }
  vector<int> d(n + 1, INF);
  d[1] = 0;
  // Bellman-Ford + if there is a relaxation at n-th phase => negative cycle
  int x;
  for (int i = 0; i < n; ++i){
    x = -1;
    for (Edge e : edges)
        if (d[e.a] < INF){
          if (d[e.b] > d[e.a] + e.cost) {
            d[e.b] = max(-INF, d[e.a] + e.cost);
            x = e.b;
        }
      }
    cout << "x after " << i+1 << " = " << x << endl;
  }
  cout << ((x != -1) ? -1 : -d[n])<< endl;
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