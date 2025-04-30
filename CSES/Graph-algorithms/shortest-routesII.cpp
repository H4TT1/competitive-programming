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
vector<vector<pair<int, int>>> adj(100001);
int n;


bool spfa(int s, vector<ll>& d) {
    d.assign(n + 1, INF);
    // vector<int> cnt(n + 1, 0);
    vector<bool> inqueue(n + 1, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                // cout << d[v] + len << " lmml" << d[to] << endl; 
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    //cnt[to]++;
                    //if (cnt[to] > n)
                        //return false;  // negative cycle (in our case never happens!)
                }
            }
        }
    }
    return true;
}

int query(int a, int b){
  vector<ll> d;
  spfa(a, d);
  return d[b] == INF ? -1 : d[b];
}

void solve(){
  int m, q; cin >> n >> m >> q;
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    adj[a].pb({b, c});
    adj[b].pb({a, c});
  }

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    cout << query(a, b) << endl;
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