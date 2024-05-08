#include <bits/stdc++.h>

using namespace std;

int n,m,a[504][504];
int dp[504][504];

//상태 : 좌표 : 그때 합 최대값
int dfs(int y, int x) {
    if (y >= n) {
        return 0;
    }
    if (x > y) { //정상경로가 아닌경우 배제
        return -1e9;
    }
    if (dp[y][x]!=-1) return dp[y][x];

    dp[y][x] = 0;
    dp[y][x] = max(dfs(y + 1, x)+a[y+1][x], dfs(y + 1, x + 1) + a[y + 1][x+1]);

    return dp[y][x];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    m = 1;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m && m<=n; ++j) {
            cin >> a[i][j];
        }
        m++;
    }

   /* for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }cout << "\n";
    }*/

    cout << dfs(0, 0) + a[0][0];

    return 0;

}