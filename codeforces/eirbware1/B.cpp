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
  int m,s; cin >> m >> s;
  int b[m];
  int freq[51] = {0};
  int mx = 0;
  bool bad = false;
  for(int i = 0; i < m; i++){
    cin >> b[i];
    freq[b[i]]++;
    mx = max(b[i], mx);
    if(freq[b[i]] >= 2){
      bad = true;
    }
     }
  if(bad){
    cout << "NO" << endl;
    return;
  }

  for(int i = 1; i <= mx;i++){
    if(freq[i] == 0){
      if(s >= i) s -= i;
      else{
        cout << "NO" << endl;
        return;
      }
    }
  }

  int cur = mx+1;
  while(s > 0){
    s -= cur;
    cur++;
  }

  if(s == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" <<endl;
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
