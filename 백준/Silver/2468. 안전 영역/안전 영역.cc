#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, ny, nx, ret, ans, a[max_n][max_n], visited[max_n][max_n];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

/*
* dfs
* 1.방문처리
* 2.for(dy,dx)
* 3.방문가능 and 미방문 -> dfs(there)
*
*/
void dfs(int y, int x, int h)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (a[ny][nx] >h && visited[ny][nx] == 0)
			dfs(ny, nx,h);

	}
	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin >> temp;
			a[i][j] = temp;
		}
	}
	//입력끝

	int h = 100;//최대높이~0까지
	while (h--)
	{
		/*
		* 초기화 "fill(시작,끝,값)"
		*/
		//fill(&a[0][0], &a[0][0] + max_n * max_n, 0);
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
		ret = 0;


		//0,0부터 구역탐색은 dfs
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] >h && visited[i][j] == 0) {
					dfs(i, j,h); ret++;
				}
			}
		}

		
		if (ans < ret) ans = ret;
	}


	cout << ans << "\n";


}