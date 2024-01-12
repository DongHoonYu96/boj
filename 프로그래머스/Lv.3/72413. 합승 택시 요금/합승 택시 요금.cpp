#include <bits/stdc++.h>

using namespace std;
 
int d[3][204]; 
//[0][node] : 시작~해당정점까지 최단거리
//[1][node] : a~해당정점까지 최단거리
//[2][node] : b~해당정점까지 최단거리
//미리 테이블을 완성후, 쿼리에서는 조회만 하도록!

int INF = 70000000;
vector<pair<int,int>> adj[204]; //adj[1]:{2,3} 1->3로가는비용이 2임

void go(int st, int idx) {
	fill(d[idx], d[idx] + 204, INF);
	//{비용, 대상정점}
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	d[idx][st] = 0;
	pq.push({ d[idx][st],st });
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		//2. 해당 거리가 최단거리테이블값과 다르면
		//더짧은경로가 있음 -> 무쓸모 -> pass
		if (d[idx][cur.second] != cur.first) continue;
		//3. 이웃한 정점들에대해 직진보다 현재정점을 거치는게 더 싸면 
		//d갱신, 큐에추가
		for (auto next : adj[cur.second]) {
			if (d[idx][next.second] > d[idx][cur.second] + next.first) {
				d[idx][next.second] = d[idx][cur.second] + next.first;
				pq.push({ d[idx][next.second] ,next.second });
				//pre[next.second] = cur.second;
				//경로복원 : (이전정점을 기록만하면된다)
				//pre[next.정점]=cur.정점 
			}
		}
	}
	//return d[idx][en];
}

//문풀전략 :  미리 d테이블을 채워놓고
//조회만 하도록 구현하자!!
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(auto fare: fares){
        adj[fare[0]].push_back({fare[2],fare[1]});
        adj[fare[1]].push_back({fare[2],fare[0]}); //양방향임
    }
    
    //s~i(i : all정점) table완성
    go(s,0);
    //a~i(i : all정점) table완성
    go(a,1);
    //b~i(i : all정점) table완성
    go(b,2);

    for(int i=1;i<=n;++i){
        //s~i -> a~i, b~i
        answer=min(answer,d[0][i]+d[1][i]+d[2][i]);
    }
    
    return answer;
}