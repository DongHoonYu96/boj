#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dp[504][504],a[504][504]; //dp[i][j] : (i,j)~(n,m)까지 경로의 수
int n,m;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int dfs(int y, int x) {
	//1. 메모가 있으면 메모활용
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	//2. 최초방문인경우 초기화(경로가 0개로)후 자식탐색
	dp[y][x] = 0;
	for (int k = 0; k < 4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[y][x] <= a[ny][nx]) continue;
		dp[y][x] += dfs(ny, nx);
		//(y,x)~(n,m)까지의 경로의 수 == '시그마' 내 상하좌우 자식~(n,m)까지의 경로의수
	}
	return dp[y][x]; //그렇게 만들어진 결과 결과 리턴
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>m;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	fill(&dp[0][0], &dp[0][0] + 504 * 504, -1);
	dp[n-1][m-1] = 1;
	
	dfs(0, 0);
	cout << dp[0][0];

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/

	return 0;
}