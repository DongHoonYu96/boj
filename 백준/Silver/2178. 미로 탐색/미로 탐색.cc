#include <bits/stdc++.h>
using namespace std;

#define max_n 104
int n, m, x,y, visited[max_n][max_n], a[max_n][max_n];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};



int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &a[i][j]);	//따닥따닥 붙어잇는거 입력받기 "%1d"
		}
	}

	/*
	* bfs
	* 1.q메이커
	* 2.비짓=true
	* 3.q.push
	*/
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });

	/*
	* -1.while(q.size())
	* 0.y,x값 = 큐팝
	* 1.탐색범위만큼 for
	* 2.국룰범위체크, 갈수없는곳, 이미방문 -> 컨틴뉴
	* 3.갈수있는경우 : 이전거리+1
	*/
	while (q.size())
	{
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
		

	printf("%d", visited[n - 1][m - 1]);
}