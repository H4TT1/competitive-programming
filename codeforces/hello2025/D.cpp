#include <bits/stdc++.h>
#include <cassert>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define MOD 1000000007
#define MOD2 998244353
#define vi vector<int>
#define pi pair<int,int>
using namespace std;
#define ll long long
int const MAX5 = 100000, MAX6 = 1000000;

/**
*/
//printf("%.10lf\n",ans);
//cout<<fixed<<setprecision(20)<<ans<<endl;
//stoll string -> long long
struct node {
    int min1, min2, max1, max2, ans1, ans2;
};
const int N = 200005;  
struct node seggy[4 * N]; 

// in this case it's the merge function
void recalc(int node) {
    struct node n1 = seggy[2 * node + 1];
    struct node n2 = seggy[2 * node + 2];
    seggy[node].min1 = min(n1.min1, n2.min1);
    seggy[node].min2 = min(n1.min2, n2.min2);
    seggy[node].max1 = max(n1.max1, n2.max1);
    seggy[node].max2 = max(n1.max2, n2.max2);
    seggy[node].ans1 = max({n1.ans1, n2.ans1, n2.max1 - n1.min1});
    seggy[node].ans2 = max({n1.ans2, n2.ans2, n1.max2 - n2.min2});
}

void build(int node, int l, int r, const vector<pair<int, int>>& t) {
    if (l == r) {
        seggy[node].min1 = t[l].F;
        seggy[node].min2 = t[l].S;
        seggy[node].max1 = t[l].F;
        seggy[node].max2 = t[l].S;
        seggy[node].ans1 = 0;
        seggy[node].ans2 = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node + 1, l, mid, t);
    build(2 * node + 2, mid + 1, r, t);
    recalc(node);
}

void update(int node, int l, int r, int index, pair<int, int> value) {
    if (l == r) {
        seggy[node].min1 = value.F;
        seggy[node].min2 = value.S;
        seggy[node].max1 = value.F;
        seggy[node].max2 = value.S;
        seggy[node].ans1 = 0;
        seggy[node].ans2 = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (index <= mid) {
        update(2 * node + 1, l, mid, index, value);
    } else {
        update(2 * node + 2, mid + 1, r, index, value);
    }
    recalc(node);
}

void Solution() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> t(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = {a[i] - i, a[i] + i - n + 1};
    }
    
    build(1, 0, n-1, t);
    
    auto query = [&]() {
        return max(seggy[1].ans1, seggy[1].ans2);
    };
    
    cout << query() << "\n";
    
    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        t[p] = {x - p, x + p - n + 1};
        update(1, 0, n-1, p, t[p]);
        cout << query() << "\n";
    }
}

int main() {
    // in & out files
    /**
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