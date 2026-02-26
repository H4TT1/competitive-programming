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

void solve(){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  int assign[n];

  auto bad_case = [&](int start)->bool{
    memset(assign, -1, sizeof(assign));
    assign[0] = start;
    bool bad = false;

    for(int i = 1; i < n; i++){
      if(a[i] == a[i-1] + 1){
        if(assign[i-1] != 0) bad = true;
        assign[i] = 0;
      }
      else if(a[i] == a[i-1] - 1){
        if(assign[i-1] != 1) bad = true;
        assign[i] = 1;
      }
      else if(a[i] == a[i-1]){
        if(assign[i-1] == -1) bad = true;
        else assign[i] = 1 - assign[i-1];
      }
      else{
        bad = true; // |a[i]-a[i-1]| > 1
      }
    }

    // End verification for this case (assign[0] = start):
    // compare reconstructed visible counts with input a[]
    int totalR = 0;
    for(int i = 0; i < n; i++){
      if(assign[i] == -1) bad = true;
      totalR += (assign[i] == 1);
    }

    int prefL = 0, prefR = 0;
    for(int i = 0; i < n; i++){
      prefL += (assign[i] == 0);
      prefR += (assign[i] == 1);
      int suffR = totalR - prefR + (assign[i] == 1);
      int visible = prefL + suffR;
      if(visible != a[i]) bad = true;
    }

    return bad;
  };

  bool bad1 = bad_case(0);
  bool bad2 = bad_case(1);

  cout << (!bad1) + (!bad2) << endl;

  /*
  abs(ai - ai+1) > 1 => impossible

  if (ai+1 = ai + 1) => (l, l)
  else if (ai+1 = ai - 1 ) => (r, r)
  if equal => (l, r) or (r, l)
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
