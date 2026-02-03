#include <bits/stdc++.h>
using namespace std;

long long gcdll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    const long long MOD = 1000000007LL;

    long long g = gcdll(a, b);
    long long l = a / g * b;

    long long low = min(a, b), high = low * n;
    auto count = [&](long long x) {
        return x / a + x / b - x / l;
    };

    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (count(mid) >= n) high = mid;
        else low = mid + 1;
    }

    cout << (low % MOD) << '\n';
    return 0;
}
