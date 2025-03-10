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
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long

void solve(){
  int n; cin >> n;
  int p[n + 1], d[n + 1];
  vi layers[n + 1];

  p[1] = 1;
  d[1] = 1;
  layers[1].pb(1);
  ll prev_tot = 1;
  ll new_tot = 0;

  for(int i = 2; i <= n; i++){
    cin >> p[i];
    d[i] = d[p[i]] + 1;
    layers[d[i]].pb(i);
  }

  ll dp[n + 1];
  dp[1] = 1;

  for(int l = 2; l <= n; l++){
    for(auto v : layers[l]){
      if(p[v] == 1){
        dp[v] = 1;
        new_tot ++;
      }
      else{
        dp[v] = (prev_tot - dp[p[v]] + MOD2) % MOD2;
        new_tot += dp[v];
        new_tot %= MOD2;
      }
    }
    prev_tot = new_tot;
    new_tot = 0;
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) ans = (ans + dp[i]) % MOD2;

  cout << ans << endl;



  /*
  cout << "debug" << endl;
  for(int i = 1; i <= n; i++){
    cout << "layer " << i << endl; 
    for(auto j : layers[i]) cout << j << " ";
    cout << endl;
  }
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
  int t = 1; cin >> t; 
  while(t--)
    solve();
  return 0;

}
