#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[34][34];

//큰알약남은갯수, 반알약남은갯수 : 그상태일때, 경우의수
ll dfs(int a, int b) {
    if (a==0 && b==0) return 1;
    if (dp[a][b] != -1) return dp[a][b];

    dp[a][b] = 0;
    if (a > 0)
        dp[a][b] += dfs(a - 1, b + 1);
    if (b > 0)
        dp[a][b] += dfs(a, b - 1);
    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int tc;
        cin >> tc;
        if (tc == 0) break;

        memset(dp, -1, sizeof(dp));
        cout << dfs(tc,0)<<"\n";
    }


    return 0;
}