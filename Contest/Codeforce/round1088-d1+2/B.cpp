#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 676767677;

// 计算绝对值差的约数个数
ll count_divisors(ll n) {
    if (n == 0) return 1;
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) {
                cnt++;
            }
        }
    }
    return cnt;
}

void Srend() {
    ll x, y;
    cin >> x >> y;
    
    // 方案数即为 |x-y| 的约数个数
    ll diff = abs(x - y);
    ll ans = count_divisors(diff);
    
    cout << ans % mod << '\n';
    
    // 完美构造：所有 1 放前面，所有 -1 放后面
    for (int i = 0; i < x; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < y; i++) {
        cout << -1 << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) Srend();
    return 0;
}