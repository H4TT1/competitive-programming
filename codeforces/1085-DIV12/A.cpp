#include <bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define WTFMOD 676767677
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
 
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000, MAXN = 1000000000;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long



void solve(){
  int n; cin >> n;
  string s;  cin >> s;
  for(int i = 1; i < n - 1; i++){
    if(s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
  }
  for(int i = 1; i < n - 1; i++){
    if(s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
  }

  int mx = count(s.begin(), s.end(), '1');
  for(int i = 1; i < n - 1; i++){
    if(s[i-1] == '1' && s[i+1] == '1') s[i] = '0';
  }
  for(int i = 1; i < n - 1; i++){
    if(s[i-1] == '1' && s[i+1] == '1') s[i] = '0';
  }
  int mn = count(s.begin(), s.end(), '1');

  cout << mn << " " << mx << endl;
  /*

  */

  
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