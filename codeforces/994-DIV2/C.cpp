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
/*
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


void Solution(){

  int n, x, y; cin >> n >> x >> y;

  int a[n+1];

  for(int i = 0; i < n; i++) a[(i+x) >= n+1 ? i+x-n : i+x] = i % 2;
  //for(int i = 1; i <= n; i++) cout << a[i] << " ";
  //cout << endl; 
  if(n % 2 or (y-x) % 2 == 0) a[x] = 2;

  for(int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl; 
  // cout << "OK!" << endl;

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
