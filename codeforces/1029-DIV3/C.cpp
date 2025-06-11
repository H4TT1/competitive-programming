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

void print_set(set<int> s){
  for(auto sa : s) cout << sa << " ";
  cout << endl;
}

void solve()
{
 int n; cin >> n;
 int freq[n+1], old_uniq, new_uniq = 0;
 memset(freq, 0, sizeof(freq));
 
 int a[n]; 
 for(int i = 0; i < n; i++){
  cin >> a[i], freq[a[i]]++;
  if(freq[a[i]] == 1) new_uniq++;
 }

 int ans = 0;
 set<int> segment;
 old_uniq = new_uniq;
 for(int i = n-1; i >= 0; i--){
  // cout << "uniq = " << old_uniq << endl;
  freq[a[i]]--;
  segment.insert(a[i]);
  //print_set(segment);
  if(freq[a[i]] == 0) new_uniq--;
  if(segment.size() == old_uniq){
    //cout << old_uniq << endl;
    ans++;
    segment.clear();
    old_uniq = new_uniq;
  }
 }
 // cout << "uniqlk" << " " << new_uniq << endl;
 // print_set(segment);

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