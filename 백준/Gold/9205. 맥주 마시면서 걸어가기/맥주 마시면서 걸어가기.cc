#include <bits/stdc++.h>

using namespace std;

int t,n,sy,sx,ey,ex,cy,cx;
vector<pair<int, int>> v; //편의점들의 좌표저장
int vis[104];

string bfs() {
    queue<pair<int, int>> q;
    fill(vis, vis + 104, 0);

    q.push({ sy, sx });

    while (q.size()) {
        tie(cy,cx) = q.front(); q.pop();
        if (abs(cy - ey) + abs(cx - ex) <= 1000) return "happy\n";

        for (int i = 0; i < v.size(); ++i) {
            if (vis[i]) continue;
            int ny = v[i].first; int nx = v[i].second;
            if (abs(cy - ny) + abs(cx - nx) > 1000) continue;
            q.push({ ny,nx });
            vis[i] = 1;
        }
    }

    //큐가 다 비었는데 해피가아닌경우
    return "sad\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        //1. 1000미터 이내->인접
        v.clear();

        cin >> n;

        cin >> sy >> sx;
        for (int i = 0; i < n; ++i) {
            int y, x;
            cin >> y >> x;
            v.push_back({ y,x });
        }
        cin >> ey >> ex;

        //bfs
        cout << bfs();
        
    }
    return 0;
}