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
vector<int> adj[MAX5 + 1];
int visited[MAX5 + 1];
vector<int> order;
vector<int> ans;
int parent[MAX5 + 1];
int cycle_start = -1, cycle_end;

bool detect_cycle(int u, int prev){
  // cout << u << " " << prev << endl;
  visited[u] = 1;
  for(auto v : adj[u]){
    if(v != prev){
      if(visited[v]){
        cycle_end = u;
        cycle_start = v;
        return true;
      }
      parent[v] = u;
      if(detect_cycle(v, parent[v]))
        return true;
    }
  }
  return false;
}

void solve(){
  int n, m; cin >> n >> m;
  
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  for(int i = 1; i <= n; i++){
    if(!visited[i] && detect_cycle(i, parent[i])){
      // cout << cycle_start << " " << cycle_end << endl;
      // return;
      vector<int> cycle;
      // for(int i = 1; i <= n; i++) cout << parent[i] << " ";
      // cout << endl;
      cycle.push_back(cycle_start);
      for (int v = cycle_end; v != cycle_start; v = parent[v]){
            //cout << v << " " << parent[v] << endl; 
            cycle.push_back(v);
            //cout << "hihi" << endl;
      }
      cycle.push_back(cycle_start);

      cout << cycle.size() << endl;
      for(auto x : cycle) cout << x << " ";
      cout << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
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


