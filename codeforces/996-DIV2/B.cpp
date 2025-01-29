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
/*
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


void Solution(){
  int n; cin >> n;
  int a[n], b[n];
  int found = 0, idx = -1;

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  for(int i = 0; i < n; i++){
    if(a[i] < b[i] && !found){found = 1;
     idx = i;}
    else if(a[i] < b[i] && found){
      cout << "NO" << endl;
      return;
    }
  }

  if(idx == -1){
    cout << "YES" << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    if(i == idx){continue;}
    if(a[i] - b[i] < b[idx] - a[idx]){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;



  /*
  algo = op1 op2
  can we swap op1 and op2
  yes because  op1 op2 = -2 to non concerned , concerned stay (if equal ofc we can swap)
  we assume 2 ai are less than their bi we cant make them increase both! case closed!

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
    Solution();
  return 0;

}
