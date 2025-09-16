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
int const MAX5 = 100000, MAX6 = 1000000, MAXN = 1000000000;
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
 
 
/*
*/
vector<int> dig;
void get_digits(int x){
  dig.clear();
  while(x != 0){
    dig.pb(x % 10);
    x -= x % 10;
    x /= 10;
  }
}

void solve(){
  int n; cin >> n;

  int dp[MAX6 + 1];
  for(int i = 1; i <= 9; i++){
    dp[i] = 1;
  }

  for(int i = 10; i <= n; i++){
    dp[i] = MAX6 + 1;
    get_digits(i);
    for(auto d : dig){
      dp[i] = min(dp[i], dp[i - d] + 1);
    }
  }


  cout << dp[n] << endl;
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
  int t = 1; // cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}