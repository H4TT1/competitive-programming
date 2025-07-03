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
  int n, x; cin >> n >> x;
  int nbits = __popcount(x);

  if(n <= nbits){cout << x << endl; return;}
  if((n - nbits) % 2 == 0) cout << x + n - nbits;
  else{
    if(x > 1) cout << x + n - nbits + 1;
    else if(x == 1) cout << n + 3;
    else{
      if(n == 1) cout << -1;
      else cout << n + 3;
    }
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