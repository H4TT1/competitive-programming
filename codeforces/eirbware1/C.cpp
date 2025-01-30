#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, k;
    cin >> n >> k;

    int n2[n],n3[n],n4[n],n5[n];
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        n2[i]=a%2;
        n3[i]=a%3;
        n4[i]=a%4;
        n5[i]=a%5;
    }

    sort(n2,n2+n);
    sort(n3,n3+n);
    sort(n4,n4+n);
    sort(n5,n5+n);

    if(k == 2) cout << n2[0] << "\n";
    else if(k == 3) {
        if(n3[0]==0) cout << "0\n";
        else if(n3[n-1]==2) cout << "1\n";
        else cout << "2\n";
    } else if(k == 4) {
        if(n2[0] == 0) {
            if(n4[0] == 0) cout << "0\n";
            else cout << n2[1] << "\n";
        } else {
            if(n4[n-1]==3) cout << "1\n";
            else cout << "2\n"; // 2 odd numbers
        }
    } else if(k == 5) {
        if(n5[0]==0) cout << "0\n";
        else if(n5[n-1]==4) cout << "1\n";
        else if(n5[n-1]==3) cout << "2\n";
        else if(n5[n-1]==2) cout << "3\n";
        else cout << "4\n";
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t; 

    while(t--) solve();

    return 0;

}