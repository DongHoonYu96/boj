#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, ny, nx, ret1,ret2;
int a[504][504], v[504][504];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};


void bfs(int y, int x) {

	//cout << "bfs ; " << y << " " << x << "\n";

	int cnt = 1;
	queue<pair<int, int>> q;
	v[y][x] = 1;
	q.push({ y,x });

	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (v[ny][nx]) continue;
			if (a[ny][nx] == 0) continue;

			q.push({ ny,nx });
			v[ny][nx] = v[y][x] + 1;
			cnt++;
			//ret2 = max(ret2, v[ny][nx]);
		}
	}

	ret2 = max(ret2, cnt);
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}*/
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}*/
	//queue<pair<int,int>> q;


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue;
			if (a[i][j] == 0) continue;
			ret1++;
			bfs(i, j);
		}
	}

	cout << ret1 << "\n" << ret2;


}