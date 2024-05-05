#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[10001]; //i노드의 인접노드들
int deg[1001]; // i노드의 차수
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m; //가수의수, pd의수
    for (int i = 0; i < m; ++i) {
        int num,a, b;
        cin >> num;
        if (num <= 1) continue; //담당한가수가 1명이하
        vector<int> tmp;
        for (int j = 0; j < num; ++j) {
            cin >> a;
            tmp.push_back(a);
        }
        for (int k = 0; k < num-1; ++k) {
            adj[tmp[k]].push_back(tmp[k + 1]);
            deg[tmp[k + 1]]++;
        }
        
    }
    //*사이클검사, 사이클이있으면 순서정하기 불가능함
    vector<int> result;

    queue<int> q;
    //*위상정렬 
    //1. 차수가 0인애 -> 맨앞에 와도됨 -> 큐에넣기
    for (int i = 1; i <= n; ++i) { //! 1-idx임에 주의!
        if (deg[i] == 0) q.push(i);
    }
    while (q.size()) {
        int cur = q.front(); q.pop(); //차수가 0인애를 정답에넣기
        result.push_back(cur); //사이클검사용
        //cout << cur << "\n";
        for (int nxt : adj[cur]) {
            deg[nxt]--; 
            //차수가 0인 애를 그래프에서 제거 -> 연결된 노드들의 deg -1헤주기.
            if (deg[nxt] == 0) q.push(nxt); //차수가 0인애 -> 정답후보
        }
    }
    if (result.size() != n) {
        cout << 0;
    }
    else {
        for (auto i : result) cout << i << "\n";
    }
    return 0;

}