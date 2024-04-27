#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int n, w[16][16],dp[16][1<<16]; 
//[현재위치][방문한비트] : [방문비트]방문시 최소비용

int dfs(int here, int visited) {
	//모든지점을 방문한경우
	// ex ) 도시4개 : 1111
	// 10000(1<<4) 에서 -1 하면 1111이 된다!
	if (visited == (1 << n) - 1) {
		//다시 출발점(0번도시)로 갈수있으면 간다.
		if (w[here][0]) {
			return w[here][0];
		} //갈수없는 경로이면 배제시킴
		else return 987654321;
	}
	//계산된값이 있는경우 그거리턴
	if (dp[here][visited] != -1) return dp[here][visited];

	//초기값 = 최대로설정 (최소값 구하기니까)
	dp[here][visited] = 987654321;
	//모든도시를 돌며, 방문안한곳으로 들어감!
	//i번째 도시로 갈 예정임.
	for (int i = 0; i < n; ++i) {
		//i번째 도시를 이미 방문했으면 탐색안함
		if (visited & (1 << i)) continue;
		if (w[here][i] == 0) continue; //갈수없는경우
		//i번째 도시 방문체크후, 그 비용을 더함
		dp[here][visited] = min(dp[here][visited], 
			dfs(i, visited | (1 << i)) + w[here][i]);
	}
	return dp[here][visited];


}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> w[i][j];
		}
	}
	//memset(dp, -1, sizeof(dp));
	fill(&dp[0][0], &dp[0][0] + 16 * (1 << 16), -1);
	//[현재 : 0번도시] [0번도시 방문표시 비트키기]
	cout << dfs(0, 1);

	return 0;
}