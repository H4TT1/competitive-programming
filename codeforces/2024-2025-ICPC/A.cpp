#include <bits/stdc++.h>
#include <cassert>
#include <cstring>
#include <utility>
 
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
  // O(n²) is possible
  int a[n + 1], c[n + 1];
  for(int i = 1; i <= n; i++) cin >> c[i], a[i] = i;
  bool overtaked[n+1][n+1];
  memset(overtaked, 0, sizeof(overtaked));

  vii overtakes;

  for(int i = n; i >= 1; i--){
    for(int j = 1; j <= n; j++){
      if(c[i] == a[j]){
        while(j+1 <= n && j != i){
          overtaked[a[j+1]][a[j]] = true;
          swap(a[j], a[j+1]);
          overtakes.pb(make_pair(a[j], a[j+1]));
          j++;
        }
        vii tmp;
        
        while(j != n  && !overtaked[a[j+1]][a[j]] && !overtaked[a[j]][a[j+1]]){
          overtakes.pb(make_pair(a[j+1], a[j]));
          tmp.pb(make_pair(a[j], a[j+1]));
          j++;
        }
        
        
        for(int k = tmp.size()-1; k >= 0; k--){
          overtakes.pb(tmp[k]);
        }
        
        break;
      }
    }
  }

  cout << overtakes.size() << endl;
  for(auto p : overtakes){
    cout << p.F << " " << p.S << endl;
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
  int t = 1; // cin >> t; 
  while(t--)
    Solution();
  return 0;

}
