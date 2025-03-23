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

- leafs have deg = 1 => they can be defined by their neighbor
- the last node(s) ??


 jsut implemented te solution for this one even though it was Ez (sad noises)
 
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long


/*
  BRBR
  9 3 5 4
  prefix on penality => 9 

*/

void solve(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int A = 1;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i], A = max(A, a[i]);
  // bin search on the final penality
  int l = 0, r = A;
  char last;
  int best = -1;

  while(l <= r){
    int mid = (l + r)/2;
    // cout << l << " " << r << endl;
    // cout << mid << endl;
    // cout << best << endl;
    int b_segments = 0; // counter for the blue segements
    last = 'R';
    for(int i = 0; i < n; i++){
      if(a[i] > mid){
        if(s[i] == 'B' && last != 'B')
          b_segments++;
        last = s[i];
      }
    }
    if(b_segments > k){
      l = mid+1;
    }
    else{
      best = mid;
      r = mid-1;
    }
  }

  cout << best << endl; 

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
  while(t--){
    solve();
  }
  return 0;

}


