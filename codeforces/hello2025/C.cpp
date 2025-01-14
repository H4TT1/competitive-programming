#include <bits/stdc++.h>
#include <cassert>
 
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define vi vector<int>
#define pi pair<int,int>
 
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000;

void Solution(){
  int l, r; cin >> l >> r;
  if(r-l == 2)
    cout << l << " " << l+1 << " " << l+2 << endl;
  else{
    //cout << l << " " << r << endl;
    int k = log2(l ^ r);
    // cout << (l^r) << endl;
    int powk = pow(2, k);
    //cout << k << "haah" << endl;
    int m = (r / powk) * powk;
    cout << m << " " << m-1 << " " << (m-1 == l ? r : l) << endl;
  } 

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
