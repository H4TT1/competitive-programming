#include <bits/stdc++.h>
#include <cstring>
 
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

void solve(){
  int n, m, k; cin >> n >> m >> k;
  /*
    finding if exists a binary string with n 0s , m 1s and
    max balance value among the substrings = k

    observations: 
      len(s) = n + m
      if k < abs(m - n) impossible (subs = s)
      else ? (always possible?) (no if max(m, n) < k) then no substring is possible
       but else 
       )

  */

  // UGLY code alert!
  if(abs(m - n) > k || max(m, n) < k) {
    cout << -1 << endl;
    return;
  }
  vector<char> ans;
  if (n > m) {
    ans.insert(ans.end(), k, '0'); 
    n -= k;
        while (m && n) {
            ans.push_back('1');
            ans.push_back('0');
            m--; n--;
        }
        if (n == 0) {
            if (m > k) {
                cout << -1 << '\n';
                return;
            }
            ans.insert(ans.end(), m, '1');
        } else {
            if (n > k) {
                cout << -1 << '\n';
                return;
            }
            ans.insert(ans.end(), n, '0');
        }
    } 
    else {
        ans.insert(ans.end(), k, '1'); 
        m -= k;
        while (m && n) {
            ans.push_back('0');
            ans.push_back('1');
            m--; n--;
        }
        if (n == 0) {
            if (m > k) {
                cout << -1 << '\n';
                return;
            }
            ans.insert(ans.end(), m, '1');
        } else {
            if (n > k) {
                cout << -1 << '\n';
                return;
            }
            ans.insert(ans.end(), n, '0');
        }
    }

    cout << string(ans.begin(), ans.end()) << '\n';
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
    solve();
  return 0;

}


