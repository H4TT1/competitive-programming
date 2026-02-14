#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    
    auto check = [&](auto&& self, int v, int x) -> bool {
      if (x > INF) return false;
      bool isLeaf = true;
      if (v) x += max(0, x - a[v]);
      for (auto u : g[v]) {
        isLeaf = false;
        if (!self(self, u, x)) return false;
      }
      return (!isLeaf || x <= a[v]);
    };
    
    int l = 1, r = INF;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(check, 0, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    
    cout << a[0] + l - 1 << '\n';
  }
}