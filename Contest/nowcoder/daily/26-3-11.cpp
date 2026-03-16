#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxPieces(ll n) {
    return (n * n + 1) / 2;
}

ll minPieces(ll n) {
    return n * n / 2;
}

bool check(ll n, ll a, ll b) {
    // 总棋子数限制
    if (a + b > n * n) return false;

    // 单个颜色数量限制
    if (a > maxPieces(n) || b > maxPieces(n)) return false;

    // 检查两种可能的分配方案
    if ((a <= maxPieces(n) && b <= minPieces(n)) ||
        (a <= minPieces(n) && b <= maxPieces(n))) {
        return true;
    }

    return false;
}

ll findMinN(ll a, ll b) {
    ll left = 1;
    ll right = 2;
    // 找一个足够大的右边界
    while (!check(right, a, b)) {
        right *= 2;
    }

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (check(mid, a, b)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        cout << findMinN(a, b) << '\n';
    }

    return 0;
}