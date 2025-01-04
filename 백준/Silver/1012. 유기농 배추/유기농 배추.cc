#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;
int t, n, m, k, ny,nx,ret, a[max_n][max_n], visited[max_n][max_n];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

/*
* dfs
* 1.방문처리
* 2.for(dy,dx)
* 3.방문가능 and 미방문 -> dfs(there)
* 
*/
void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		if (a[ny][nx] == 1 && visited[ny][nx] == 0)
			dfs(ny,nx);

	}
	return;
}

int main()
{
	cin >> t ;

	for (int test_t = 0; test_t < t; ++test_t)
	{
		/*
		* tc문제는 초기화 "fill(시작,끝,값)"
		*/
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;

		cin>> m >> n >> k;
		for (int b = 0; b < k; ++b)
		{
			int x=0;
			int y = 0;
			cin >> x >> y;
			a[y][x] = 1;
		}
		//입력끝

		//0,0부터 구역탐색은 dfs
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && visited[i][j]==0) {
					dfs(i, j); ret++;
				}
			}
		}
		
		cout << ret<<"\n";
		
	}
}