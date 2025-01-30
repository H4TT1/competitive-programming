
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+1;

int n, m;
bool v[MAXN][MAXN];
int g[MAXN][MAXN];

vector<pair<int, int>> ma;

int sumg = 0;

// int dfs(int y, int x) {
//     cout << y << " " << x << endl;
//     v[y][x]=true;
//     for(int i = 0; i < 4; i++) {
//         int ny = y+ma[i].first;
//         int nx = x+ma[i].second;
//         if((ny >= 0 && ny < n && nx >= 0 && nx < m) && (g[ny][nx]>0) && !v[ny][nx]) {
//             return g[y][x] + dfs(ny, nx);
//         }
//     }
//     return g[y][x];
// }

void dfs(int y, int x) {
    //cout << y << " " << x << endl;
    v[y][x]=true;
    sumg += g[y][x];
    for(int i = 0; i < 4; i++) {
        int ny = y+ma[i].first;
        int nx = x+ma[i].second;
        if((ny >= 0 && ny < n && nx >= 0 && nx < m) && (g[ny][nx]>0) && !v[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

void solve() {

    memset(v, false, sizeof(v));
    memset(g, 0, sizeof(g));
    sumg = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] > 0 && !v[i][j]) {
                //printf("in dfs(%d,%d)\n", i, j);
                sumg = 0;
                dfs(i, j);
                sum = max(sum, sumg);
                //printf("sum: %d\n", sum);
            }
        }
    }

    cout << sum << "\n";

}

int main() {

    ma.push_back({0,1});
    ma.push_back({-1,0});
    ma.push_back({0,-1});
    ma.push_back({1,0});

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t = 1;
    cin >> t; 

    while(t--) solve();

    return 0;

}