#include <bits/stdc++.h>
 
using namespace std;
#define ll long long

void Solution(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    ll mat[n][m];
    ll srow[n] = {0}, scol[m] = {0};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            srow[i] += mat[i][j];
            scol[j] += mat[i][j];
        }
    }

    ll rem_row[n], rem_col[m];
    for(int i = 0; i < n; i++) rem_row[i] = -srow[i];
    for(int j = 0; j < m; j++) rem_col[j] = -scol[j];

    int curr_row = 0, curr_col = 0;

    for(char dir : s){
        if(dir == 'R'){
            ll x = rem_col[curr_col];
            mat[curr_row][curr_col] = x;
            rem_row[curr_row] -= x;
            rem_col[curr_col] = 0;
            curr_col++;
        } else {
            ll x = rem_row[curr_row];
            mat[curr_row][curr_col] = x;
            rem_col[curr_col] -= x;
            rem_row[curr_row] = 0;
            curr_row++;
        }
    }

    mat[curr_row][curr_col] = rem_row[curr_row];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; cin >> t; 
    while(t--) Solution();
    return 0;
}