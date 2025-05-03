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

struct myInt{
  ll i = -1;
};

map<pair<int,int>, myInt> ans;
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
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                // cout << d[v] + len << " lmml" << d[to] << endl; 
                d[to] = d[v] + len;
                ans[{s, to}].i = d[to];
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

ll query(int a, int b){
  vector<ll> d;
  ll answer = -1;
  if(ans[{a, b}].i != -1) answer = (answer == -1 ? ans[{a, b}].i : min(answer, ans[{a, b}].i));
  if(ans[{b, a}].i != -1) answer = (answer == -1 ? ans[{b, a}].i : min(answer, ans[{b, a}].i));
  if(answer != -1){
    assert(answer >= 0);
    //cout << "returned " << answer << endl;
    //cout << answer << endl;
    return answer;
  }
  spfa(a, d);

  assert((ans[{a, b}].i) >= -1);

  return ans[{a, b}].i;
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
    cout << (a == b ? 0 : query(a, b)) << endl;
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
