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
#define vll vector<ll>

using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000;

void Solution(){
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vii Ans;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            Ans.pb({i, j});

    vi a;
    for(int i = n; i >= 1; i--)
        a.pb(i);

    for(int i = 0; i < n; i++){
        int in = -1;
        for(int j = i + 1; j < n; j++){
            if(v[i] == a[j]){
                in = j;
                break;
            }
        }

        for(int j = in; j > i; j--){
            Ans.pb({v[i], a[j - 1]});
            a[j] = a[j - 1];
        }

        a[i] = v[i];
    }

    cout << Ans.size() << endl;
    for(auto i : Ans)
        cout << i.F << " " << i.S << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--)
        Solution();
    return 0;
}