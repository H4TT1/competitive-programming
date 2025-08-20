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

void solve(){
  int n; cin >> n;
  vector<pair<pair<int,int>,int>> a(n);

  for(int i = 0; i < n; i++) {
    cin >> a[i].F.F >> a[i].F.S;
    a[i].S = i + 1;
  }

  sort(a.begin(), a.end());

  if(n == 1){
    cout << 1 << endl;
    cout << 1 << endl;
    return;
  }

  vector<int> ans;
  int step = 1;
  for(int i = 0; i < n;){
    int j;
    for(j = i; j < n && a[j].F.F == a[i].F.F;){j++;}
    j--;
    ans.pb(a[j].S);
    i = j+1;
  }
  cout << ans.size() << endl;
  for(auto x : ans) cout << x << " ";
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