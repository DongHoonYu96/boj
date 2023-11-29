#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[204];
int divd = 1000000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dp, dp + 204, 1);

    for (int i = 1; i < k; ++i) { //회차
        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j]%divd + dp[j - 1]%divd;
            //cout << dp[j] << " ";
        }
    }

    //for (int i = 0; i <= n; ++i) cout << dp[i] << " ";
    cout << dp[n] % divd;

    return 0;
}