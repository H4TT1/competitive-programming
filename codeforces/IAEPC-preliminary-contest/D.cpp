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


void Solution(){
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n),b(m);
        map<ll,ll>freq_a,freq_b;
        set<ll>set_a,set_b;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            freq_a[a[i]]++;
            set_a.insert(a[i]);
        }
        for(ll i=0;i<m;i++){
            cin>>b[i];
            freq_b[b[i]]++;
            set_b.insert(b[i]);
        }
        while(true){
            if(set_a.empty() && set_b.empty()){
                cout<<"YES"<<endl;
                break;
            }
            if(set_a.empty() || set_b.empty()){
                cout<<"NO"<<endl;
                break;
            }
            ll maximum_element_a=*prev(set_a.end());
            ll maximum_element_b=*prev(set_b.end());
            if(maximum_element_a>maximum_element_b){
                cout<<"NO"<<endl;
                break;
            }
            if(freq_a[maximum_element_b]){
                ll minimum_element=min(freq_a[maximum_element_b],freq_b[maximum_element_b]);   
                freq_a[maximum_element_b]-=minimum_element;
                freq_b[maximum_element_b]-=minimum_element;
                if(freq_a[maximum_element_b]==0){
                    set_a.erase(maximum_element_b);
                }
                if(freq_b[maximum_element_b]==0){
                    set_b.erase(maximum_element_b);
                }
            }
            else{
                ll floor_value=maximum_element_b/2;
                ll ceil_value=(maximum_element_b+1)/2;
                freq_b[floor_value]+=freq_b[maximum_element_b];
                freq_b[ceil_value]+=freq_b[maximum_element_b];
                set_b.insert(floor_value);
                set_b.insert(ceil_value);
                freq_b[maximum_element_b]=0;
                set_b.erase(maximum_element_b);

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
  while(t--)
    Solution();
  return 0;

}
