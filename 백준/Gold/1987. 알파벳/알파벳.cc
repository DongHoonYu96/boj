#include <bits/stdc++.h> 
#define MAX 100000
#define y1 aaaaa

using namespace std;
int ret, cnt;
int n, m,  y1, x1, y2, x2, ny, nx,
dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int visited[404];
char a[24][24];
queue<pair<int, int>> swanQ,waterQ,swanTemp,waterTemp;

bool in(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}
void dfs(int y, int x, int cnt)
{
	ret = max(ret, cnt);
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!in(ny, nx)) continue;
		if (visited[a[ny][nx] - 'A']) continue;
		visited[a[ny][nx] - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[a[ny][nx] - 'A'] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret;

}
/*
5 17
 */