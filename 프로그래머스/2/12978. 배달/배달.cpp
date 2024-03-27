#include <bits/stdc++.h>
using namespace std;

int d[54]; //1번정점에서 i번 정점까지 최단거리
int INF=987654321;
//{비용, 대상정점}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int,int>> adj[54]; //adj[1]:{2,3} 1->2로가는비용이 3임

int go(int st, int en) {
	fill(d, d + 54, INF);
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
				//pre[next.second] = cur.second;
				//경로복원 : (이전정점을 기록만하면된다)
				//pre[next.정점]=cur.정점 
			}
		}
	}
	return d[en];
}
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    fill(d, d + 54, INF);
    for(auto v : road){
        adj[v[0]].push_back({v[2],v[1]});
        adj[v[1]].push_back({v[2],v[0]});
    }
    
    
    go(1,5);
    sort(d,d+54);
    
    return upper_bound(d,d+54,K)-d ;

    return answer;
}