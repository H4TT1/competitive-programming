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
  ll n, k; cin >> n >> k;
  string s, t; cin >> s >> t;

  ll freq[26] = {0};
  // int freq_t[26] = {0};

  for(int i = 0; i < n; i++){
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }
  for(int i = 0; i < 26; i++){
    if(freq[i] != 0){
      cout << "NO" << endl;
      return;
    }
  }
  if(n >= 2*k) cout << "YES" << endl;
  else{
    for(int i = n-k; i < k; i++){
      if(s[i] != t[i]){
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
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
