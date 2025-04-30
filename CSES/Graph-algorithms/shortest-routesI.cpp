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
/**
*/
const ll INF = 1000000000000000;
vector<vector<pair<int, int>>> adj(100001);
int n;

void solve() {
    int m; cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    
    vector<ll> distances(n + 1, INF);
    distances[1] = 0; 
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1}); 
    
    // Dijkstra algorithm
    while (!pq.empty()) {
        ll current_distance = pq.top().first;
        int current_city = pq.top().second;
        pq.pop();
        

        if (current_distance > distances[current_city]) {
            continue;
        }
        
        for (auto &edge : adj[current_city]) {
            int neighbor = edge.first;
            ll flight_length = edge.second;
            
            if (distances[current_city] + flight_length < distances[neighbor]) {
                distances[neighbor] = distances[current_city] + flight_length;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << distances[i] << (i < n ? " " : "");
    }
    cout << endl;
}

int main() {
    // in & out files
    /**
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    */
    // fast and furious io
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // testcases
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}