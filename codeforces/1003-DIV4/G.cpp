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
int sieve[2 * MAX5 + 1];
int prime_freq[2 * MAX5 + 1];
vector<int> primes;

void make_sieve(){
  memset(sieve, 0, sizeof(sieve));
  sieve[1] = 1;
  for(int i = 2; i <= 2 * MAX5; i++){
    if(sieve[i] == 0){
      primes.pb(i);
      for(int j = 2*i; j <= 2 * MAX5; j += i){
        if(sieve[j] == 0)
          sieve[j] = i;
      }
    }
  }
}

void solve(){

  /*
    sieve => O(n)
    t <= 10^4
    there is approx 2 * 10^4 prime in the given interval


  */
  int n; cin >> n;
  int a[n];
  ll ans = 0;
  int acc = 0;
  map<int, int> freq;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++){
    if(sieve[a[i]]){
      if(sieve[a[i]] * sieve[a[i]] == a[i]){
        // cout << "ha" << a[i] << endl;
        freq[a[i]]++;
        // cout << freq[a[i]] + freq[sieve[a[i]]] << " dadded for " << a[i] << endl;
        ans += freq[a[i]] + freq[sieve[a[i]]];
      }
      else if(sieve[a[i]] * (sieve[a[i]/sieve[a[i]]] == 0 ? a[i]/sieve[a[i]] : 0) == a[i]){
        freq[a[i]]++;
        // cout << freq[sieve[a[i]]] + freq[a[i]/sieve[a[i]]] + freq[a[i]] << " added for " << a[i] << endl;
        ans += freq[sieve[a[i]]] + freq[a[i]/sieve[a[i]]] + freq[a[i]];
      }
      
      /*if(a[i] == 4){
        cout << "hah " << sieve[a[i]] << " " << sieve[a[i]] << endl;
      }*/
      
    }
    else{
      ans += acc - freq[a[i]];
      // cout << acc - freq[a[i]] << " added for " << a[i] << endl;
      freq[a[i]]++;
      acc++;
    }
  }
  freq.clear();
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
  int t = 1; cin >> t;
  make_sieve();
  while(t--){
    solve();
  }
  return 0;

}


