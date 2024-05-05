#include<bits/stdc++.h>
using namespace std;
map<string, int> idx;
vector<vector<int>> G(1005);
vector<string> v;
vector<vector<int>> children(1005);
int N, M;
int indegree[1005];
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;++i) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<N;++i) idx[v[i]] = i;
    cin >> M;
    for(int i=0;i<M;++i) {
        string a, b;
        cin >> a >> b;
        int u = idx[a];
        int v = idx[b];
        G[v].push_back(u);
        indegree[u]++;
    }
    queue<int> q;
    vector<int> super_father;
    for(int i=0;i<N;++i) {
        if(indegree[i] == 0) {
            super_father.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt : G[cur]) {
            indegree[nxt]--;
            if(indegree[nxt] == 0) {
                children[cur].push_back(nxt);
                q.push(nxt);
            }
        }
    }
    cout << super_father.size() << '\n';
    for(int i : super_father) cout << v[i] << ' ';
    cout << '\n';
    for(int i=0;i<N;++i) {
        cout << v[i] << ' ' << children[i].size() << ' ';
        sort(children[i].begin(), children[i].end());
        for(int j : children[i]) cout << v[j] << ' ';
        cout << '\n';
    }
    return 0;
}