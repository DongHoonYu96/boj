#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, x, st, en,ret,v1,v2;
vector<pair<int, int>> adj[1004];	//adj[1]:{2,3} 1->2로가는비용이 3임
int d[1004], pre[1004]; //시작~해당정점까지 최단거리
int INF = 666666666;

int go(int st, int en) {
	fill(d, d + 1004, INF);
	//{비용, 대상정점}
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st],st });
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		//2. 해당 거리가 최단거리테이블값과 다르면
		//더짧은경로가 있음 -> 무쓸모 -> pass
		if (d[cur.second] != cur.first) continue;
		//3. 이웃한 정점들에대해 직진보다 현재정점을 거치는게 더 싸면 
		//d갱신, 큐에추가
		for (auto next : adj[cur.second]) {
			if (d[next.second] > d[cur.second] + next.first) {
				d[next.second] = d[cur.second] + next.first;
				pq.push({ d[next.second] ,next.second });
				pre[next.second] = cur.second;
				//경로복원 : (이전정점을 기록만하면된다)
				//pre[next.정점]=cur.정점 
			}
		}
	}
	return d[en];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
		adj[v].push_back({ w,u }); //양방향
	}
	cin >> v1 >> v2;

	en = n;
	int a= go(1, v1) + go(v1, v2) + go(v2, en);
	int b = go(1, v2) + go(v2, v1) + go(v1, en);
	int ret = min(a, b);

	if (ret >= 666666666) cout << -1;
	else cout << ret;

	return 0;
}
