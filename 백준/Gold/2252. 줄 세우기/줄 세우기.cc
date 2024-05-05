#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[32001]; //i노드의 인접노드들
int deg[32001]; // i노드의 차수
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); //b를 인접리스트로추가
        deg[b]++; 
        //학생 a가 먼저와야함 == a->b 이런모양임
        //b의 차수를 +1.
    }
    queue<int> q;
    //*위상정렬 
    //1. 차수가 0인애 -> 맨앞에 와도됨 -> 큐에넣기
    for (int i = 1; i <= n; ++i) { //! 1-idx임에 주의!
        if (deg[i] == 0) q.push(i);
    }
    while (q.size()) {
        int cur = q.front(); q.pop(); //차수가 0인애를 정답에넣기
        cout << cur << " ";
        for (int nxt : adj[cur]) {
            deg[nxt]--; 
            //차수가 0인 애를 그래프에서 제거 -> 연결된 노드들의 deg -1헤주기.
            if (deg[nxt] == 0) q.push(nxt); //차수가 0인애 -> 정답후보
        }
    }
    return 0;

}