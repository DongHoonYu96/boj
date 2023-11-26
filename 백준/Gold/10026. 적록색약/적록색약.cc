#include <bits/stdc++.h>
using namespace std;

int n,vis[104][104],ret1,ret2;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
char a[104][104];

void dfs(char st, int y, int x) {
	vis[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (vis[ny][nx]) continue;
		if (a[ny][nx] != st) continue;
		dfs(st, ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j]) continue;
			dfs(a[i][j], i, j);
			ret1++;
		}
	}
	cout << ret1 << "\n";

	fill(&vis[0][0], &vis[0][0] + 104 * 104, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 'R') a[i][j] = 'G';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j]) continue;
			dfs(a[i][j], i, j);
			ret2++;
		}
	}
	cout << ret2;

	return 0;
}