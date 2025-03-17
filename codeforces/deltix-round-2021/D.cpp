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

- leafs have deg = 1 => they can be defined by their neighbor
- the last node(s) ??


 jsut implemented te solution for this one even though it was Ez (sad noises)
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
int parent[1001];
int size[1001];
void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
      return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b){
      parent[b] = a;
      size[a] += size[b];
  }
}

int calc_size(int a){
  a = find_set(a);
  return size[a];
}


void solve(){
  int n, d; cin >> n >> d;
  vector<pair<int,int>> conds;
  int x, y; 
  // memset(size, 0, sizeof(size));
  for(int i = 0; i < d; i++){
    cin >> x >> y;
    make_set(x);
    make_set(y);
    conds.pb({x, y});
    union_sets(x, y);

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


