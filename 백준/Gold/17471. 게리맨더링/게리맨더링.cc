#include <bits/stdc++.h>

using namespace std;

int n, people[11],vis[11], ret=987654321;
vector<int> adj[11]; //adj[1]:[2,4] / 1번노드는 2,4와 연결됨
int gu[11];//구역정보

//구역이다르면 리턴 ,(노드n, 구역k)
void dfs(int n, int k) {
    if (vis[n]) return;
    if (gu[n] != k) return;
    vis[n] = 1;
    for (auto nxt : adj[n]) {
        dfs(nxt,k);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> people[i];
    int a,b;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        for (int j = 0; j < a; ++j) {
            cin >> b;
            adj[i].push_back(b);
        } 
    }
    for (int subset = 0; subset < (1 << n); ++subset) {
        vector<int> v1, v2;
        int fail = 0;
        fill(gu, gu + 11, 0);
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                v1.push_back(i + 1); //구역1
                gu[i + 1] = 1;
            }
            else {
                v2.push_back(i + 1); //구역2
                gu[i + 1] = 2;
            }
        }
        if (v1.size() == 0 || v2.size() == 0) continue; //구역은 나눠저야한다.

        fill(vis, vis + 11, 0);
        dfs(v1[0],1);
        for (auto i : v1) {
            if (vis[i] == 0) {
                fail = 1;
                break;
            }
        }
        fill(vis, vis + 11, 0);
        dfs(v2[0],2);
        for (auto i : v2) {
            if (vis[i] == 0) {
                fail = 1;
                break;
            }
        }
        if (fail) continue;

        int a = 0, b = 0;
        for (auto i : v1) {
            a += people[i];
        }
        for (auto i : v2) {
            b += people[i];
        }

        ret = min(ret, abs(a - b));
    }
    
    if (ret == 987654321) {
        cout << -1;
        return 0;
    }
    cout << ret;
    return 0;
}