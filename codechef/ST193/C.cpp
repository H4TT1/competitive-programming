#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i = n - k + 1; i >= 1; i--) cout << i << " ";
        for(int i = n - k + 2; i <= n; i++) cout << i << " ";
        cout << endl;
    }
}