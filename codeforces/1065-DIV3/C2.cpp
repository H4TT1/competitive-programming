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


int highestBit(int n)
{
    if (n <= 0) return 0;

    int bit = 1;
    while (bit <= n)
        bit <<= 1;

    return bit >> 1;
}


void solve(){
  int n; cin >> n;
  int a[n], b[n];

  int xor_ = 0;
  for(int i = 0; i < n; i++) cin >> a[i], xor_ ^= a[i];
  for(int i = 0; i < n; i++) cin >> b[i], xor_ ^= b[i];


  int highestBit_ = highestBit(xor_);

  // cout << "highest bit " << highestBit_ << endl; 

  if(xor_ == 0) {
    cout << "Tie" << endl;
    return;
  }

  for(int i = n-1; i >= 0; i--){

    if(((a[i] ^ b[i]) & highestBit_)){
      if((i + 1) % 2 == 0){
        cout << "Mai" << endl;
      }
      else{
        cout << "Ajisai" << endl;
      }
      return;
    } 
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
  while(t--){
    solve();
  }
  return 0;
 
}