#include <bits/stdc++.h>

using namespace std;

int n,m;
int sa[101], snake[101],vis[101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n>>m;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a>>b;
        sa[a] = b;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        snake[a] = b;
    }
   
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        int cur = q.front(); q.pop();
        if (cur == 100) { //!bfs특 : 첫도착이 최적값임!
            cout << vis[cur]-1; //초기값을 1로뒀기땜에 -1해야함
            return 0;
        }

        for (int i = 1; i <= 6; ++i) {
            int nxt = cur + i;
            if (vis[nxt]) continue;
            if (nxt > 100) continue;
            if (sa[nxt]) {
                nxt = sa[nxt];
            }
            if (snake[nxt]) {
                nxt = snake[nxt];
            }
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }

    return 0;

}