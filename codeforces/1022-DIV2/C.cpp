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
 
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
 
 
/*
*/
void solve()
{
  int n; cin >> n;
  // vector<pair<int,int>> a(n);
  vector<int> a;
  int ele; cin >> ele;
  a.pb(ele);
  for(int i = 1; i < n; i++){
    cin >> ele;
    if(ele != a.back()) a.pb(ele);
  }
  int ans = 0;

  if(a.size() == 1){
    cout << 1 << endl;
    return;
  }

  for(int i = 1; i < a.size() - 1; i++){
    if(a[i] > a[i-1] && a[i] > a[i+1]) ans++;
  }

  ans += (a[0] > a[1]) + (a[a.size()-1] > a[a.size()-2]);
  /* my first idea who complicated the problem (it works but there is a hidden edge case i didn t find)*/
  // // current borders
  // set<int> borders;
  // bool pressed[n];
  // memset(pressed, false, sizeof(pressed));
  // int ans = 0;

  // sort(a.begin(), a.end());

  // for(int i = n-1; i >= 0; i--){
  //   int cnt = borders.count(a[i].S);
  //   if(!cnt){
  //     ans++;
  //     pressed[a[i].S] = true;  
  //     if(a[i].S > 0) borders.insert(a[i].S - 1);
  //     if(a[i].S < n-1) borders.insert(a[i].S + 1);
  //   }
  //   else{
  //     pressed[a[i].S] = true;
  //     borders.erase(a[i].S);
  //     if(a[i].S > 0 && !pressed[a[i].S - 1]) borders.insert(a[i].S - 1);
  //     if(a[i].S < n-1 && !pressed[a[i].S + 1]) borders.insert(a[i].S + 1);
  //   }
  // }

  cout << ans << endl;

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