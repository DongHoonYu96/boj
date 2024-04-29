#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[17][17],dp[17][17][3];

//우측좌표, 상태 0 1 2(가로 세로 대각) : 그 좌표로오는 경우의수
int dfs(int y, int x, int state) {
    if (y < 0 || x < 0 || y >= n || x >= n) return 0;
    if (a[y][x] == 1) return 0;
    if (state == 2) {
        if(a[y-1][x]==1) return 0;
        if (a[y][x-1] == 1) return 0;
    }

    if (y == n - 1 && x == n - 1) return 1;
    if (dp[y][x][state] != -1) return dp[y][x][state];

    dp[y][x][state] = 0;
    if (state == 0) {
        dp[y][x][state] += dfs(y, x + 1, 0);
        dp[y][x][state] += dfs(y+1, x + 1, 2);
    }
    else if (state == 1) {
        dp[y][x][state] += dfs(y+1, x , 1);
        dp[y][x][state] += dfs(y + 1, x + 1, 2);
    }
    else if (state == 2) {
        dp[y][x][state] += dfs(y, x + 1, 0);
        dp[y][x][state] += dfs(y+1, x, 1);
        dp[y][x][state] += dfs(y + 1, x + 1, 2);
    }
    return dp[y][x][state];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 1, 0);
    return 0;
}