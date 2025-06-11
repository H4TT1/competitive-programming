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

void print_set(set<int> s){
  for(auto sa : s) cout << sa << " ";
  cout << endl;
}

void solve()
{
 int n; cin >> n;
 int a[n];
 for(int i = 0; i < n; i++) cin >> a[i];
 bool yes1 = true, yes2 = (2*a[0] - a[1] >= 0 && (2*a[0] - a[1]) % (n+1) == 0 && a[1] - a[0] + (2*a[0] - a[1]) / (n+1) >= 0);

 for(int i = 2; i < n; i++) if((a[i] - a[i-1]) != a[1] - a[0]) yes1 = false;

 cout << ((yes1 and yes2) ? "YES" : "NO") << endl;

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