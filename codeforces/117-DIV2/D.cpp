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
/*

- leafs have deg = 1 => they can be defined by their neighbor
- the last node(s) ??


 jsut implemented te solution for this one even though it was Ez (sad noises)
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


/*
  BRBR
  9 3 5 4
  prefix on penality => 9 

*/

bool check(ll a, ll b, ll x){
  if(a == x or b == x) return true;
  if(a < b) swap(a, b);
  if(b > a - b) b = a - b;
  if(x > max(a, b) or a == 0 or b == 0) return false;
  ll cnt = max(1ll, (a - max(x, b)) / (2 * b));
  return check(a - b * cnt, b, x);
}

void solve(){

  ll a, b, x; cin >> a >> b >> x;
  cout << (check(a, b, x) ? "YES" : "NO") << endl; 

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


