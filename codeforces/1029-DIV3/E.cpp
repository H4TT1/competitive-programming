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
  int a[n], b[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  if(a[n - 1] == b[n - 1]){
    cout << n << endl;
    return;
  }

  vector<bool> seen(n+1);
  int ans = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || seen[a[i]] || seen[b[i]]) {
            ans = i;
            break;
        }
        seen[a[i + 1]] = seen[b[i + 1]] = true;
    }

  cout << ans + 1 << endl;
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