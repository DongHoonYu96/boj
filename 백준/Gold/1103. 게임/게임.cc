#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m, a[54][54], dp[54][54], vis[54][54];

//좌표 : 그상태일때, 움직인 최대 횟수
ll dfs(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return 0;
    if (a[y][x] == -1) return 0;

    //사이클검사방법
    //방문한곳을 재방문했다면 사이클임!
    if (vis[y][x]) {
       cout << -1;
       exit(0);
   }
    if (dp[y][x] != -1) return dp[y][x];
    //if (dp[y][x][cnt] >= 1e9) {
    //    cout << -1;
    //    exit(0);
    //}

    //방문걸고
    vis[y][x] = 1;
    //cout << y << " " << x << " \n";
    dp[y][x] = 0;
    ll a1 = dfs(y + a[y][x], x) + 1;
    ll b = dfs(y , x+ a[y][x] ) + 1;
    ll c = dfs(y - a[y][x], x)  + 1;
    ll d = dfs(y, x- a[y][x] ) + 1;
    vis[y][x] = 0; //방문풀기 (원복해야 다른 결과에 영향을 안미침)

    vector<int> v;
    v.push_back(a1); v.push_back(b); v.push_back(c); v.push_back(d);
    dp[y][x] += *max_element(v.begin(), v.end());
    return dp[y][x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'H') a[i][j] = -1;
            else a[i][j] = s[j] - '0';
        }
    }

    ll ret= dfs(0, 0);


    cout << ret;
    return 0;
}