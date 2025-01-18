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
  int n; cin >> n;
  /*
  n => a n-sized array 1 <= ai <= n and g(a) > n
  n = 6 => 1 1 2 3 1 2 (f(a) = 3)
  planidrome subseq = 1 1 1, 1 2 1, 1 3 1, 1 2 1, 1 3 1, 2 1 2, 2 3 2 => g(a) = 7
  idea : force f(a) = 3 and somehow make g(a) > n
  1 1 2 3 1 2 2 3 4 3 pttern?
  1, 2, 3, ..., n-2, 1, 2 => 2*(n-3) > n for n > 6
  */

  if(n == 6)
    cout << "1 1 2 3 1 2" << endl;
  else{
    for(int i = 1; i <= n-2; i++){
      cout << i << " ";
    }
    cout << "1 2" << endl;
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
