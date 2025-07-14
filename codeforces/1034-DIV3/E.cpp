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
  set<int> excl;
  map<int, int> freq;
  vector<int> invfreq[n + 1];
  int a[n];

  for(int i = 0; i <= n; i++) excl.insert(i);

  for(int i = 0; i < n; i++){
    cin >> a[i];
    freq[a[i]]++;
    excl.erase(a[i]);
  }

  for(pair<int,int> f : freq){
    invfreq[f.second].pb(f.first);
  }
  int mex = *excl.begin();
  set<int> vals;
  vals.insert(mex);

  for(int k = 0; k <= n; k++){
    vals.erase(n - k + 1);
    for(int i : invfreq[k]){
      if(i <= min(mex, n-k)){
        vals.insert(i);
      }
    }
    cout << vals.size() << " ";
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