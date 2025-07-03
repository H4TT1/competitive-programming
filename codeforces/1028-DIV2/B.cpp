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

ll pow2[MAX5 + 1];

ll answer(int a, int b, int c, int d){
  if(max(a,b) > max(c, d)) return (pow2[a] + pow2[b]) % MOD2;
  else if(max(a, b) < max(c, d)) return (pow2[c] + pow2[d]) % MOD2;
  else if(min(a, b) > min(c, d)) return (pow2[a] + pow2[b]) % MOD2;
  else return (pow2[c] + pow2[d]) % MOD2;
}

void solve()
{
  int n; cin >> n;
  int p[n], q[n];

  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) cin >> q[i];

  // we could do that in the input loop (not a big diff)
  int maxpref_p[n], maxpref_q[n];
  maxpref_p[0] = 0;
  maxpref_q[0] = 0;

  for(int i = 1; i < n; i++){
    maxpref_p[i] = (p[maxpref_p[i-1]] > p[i]) ? maxpref_p[i-1] : i;
    maxpref_q[i] = (q[maxpref_q[i-1]] > q[i]) ? maxpref_q[i-1] : i;
  }

  for(int i = 0; i < n; i++){
    cout << answer(p[maxpref_p[i]], q[i - maxpref_p[i]],
                   q[maxpref_q[i]], p[i - maxpref_q[i]]) << " ";
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

  // precompute the powers of 2
  pow2[0] = 1;
  for(int i = 1; i <= MAX5; i++) pow2[i] = (pow2[i-1] * 2) % MOD2;
 
// testcases
  int t = 1;  cin >> t;
  while(t--){
    solve();
  }
  return 0;
 
}