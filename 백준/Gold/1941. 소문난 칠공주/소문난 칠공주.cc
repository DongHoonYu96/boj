#include <bits/stdc++.h>
using namespace std;

char a[5][5];
int v[5][5],ny, nx, ret,arr[25], isused[25],visited[5][5];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

////현재 k명 뽑았음, 좌표 , 뽑은사람카운팅
//void dfs2(int k, int y ,int x, int Y, int S) {
//	cout << "dfs :" <<k<<"/ " << y << " " << x << "\n";
//
//
//	//v[y][x] = 1;
//
//	//임도연파가 4명이상 -> 가지치기
//	if (Y >= 4) {
//		return;
//	}
//
//	if (k >= 6) {
//		cout << "kkkkkkkkkkkkkkkkkk\n";
//
//		ret++;
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i) {
//		ny = y + dy[i];
//		nx = x + dx[i];
//		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
//		if (v[ny][nx]) continue;
//		v[ny][nx] = 1;
//		if (a[ny][nx] == 'Y') {
//			dfs(k + 1, ny, nx, Y + 1, S);
//		}
//		if (a[ny][nx] == 'S') {
//			dfs(k + 1, ny, nx, Y, S + 1);
//
//		}
//		v[ny][nx] = 0;
//
//
//	}
//}

void dfs(int y, int x) {
	visited[y][x] = 1;


	for (int i = 0; i < 4; ++i) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		if (visited[ny][nx]) continue;
		if (v[ny][nx] == 0) continue;	//방문대상이 아니면 pass
		
		dfs(ny, nx);
	}
	return;

}

//현재까지 k개 뽑음
//25C7 구현
//i = 0 ~ 24 
// n/5==y좌표 , n%5==x좌표로 사용하면 된다,
void go(int k) {
	if (k >= 7) {
		fill(&v[0][0], &v[0][0] + 5 * 5, 0);
		fill(&visited[0][0], &visited[0][0] + 5 * 5, 0);

		int y_cnt=0;
		int s_cnt = 0;
		for (int i = 0; i < 7; ++i) {
			//cout << arr[i] << " ";
			int y = arr[i] / 5;
			int x = arr[i] % 5;

			v[y][x] = 1;	//방문해야할곳 체크

			if (a[y][x] == 'Y') y_cnt++;
			if (a[y][x] == 'S') s_cnt++;

		}
		bool s_many = false;
		if (s_cnt >= 4) s_many = true;

		/////////////////////////////////////
		dfs(arr[0] / 5, arr[0] % 5);

		//for (int i = 0; i < 5; ++i) {
		//	for (int j = 0; j < 5; ++j) {
		//		cout << v[i][j];
		//	}
		//	cout << "\n";
		//}
		//cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

		//for (int i = 0; i < 5; ++i) {
		//	for (int j = 0; j < 5; ++j) {
		//		cout << visited[i][j];
		//	}
		//	cout << "\n";
		//}
		//cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

		bool all_adj = true;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (visited[i][j] != v[i][j]) {
					all_adj = false;
					break;
				}
			}
		}		

		//cout << s_many << " " << all_adj<<"\n";
		if (s_many && all_adj) ret++;
		//cout << "\n";
		return;
	}

	int st = 0;
	if (k != 0) st = arr[k - 1]+1;

	for (int i = st; i < 25; ++i) {
		if (isused[i]) continue;
		arr[k] = i;
		isused[i] = 1;
		go(k + 1);
		isused[i] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 5; ++j) {
			a[i][j]= temp[j];
		}
	}

	go(0);

	//for (int i = 0; i < 5; ++i) {
	//	for (int j = 0; j < 5; ++j) {
	//		cout << a[i][j];
	//	}
	//	cout << "\n";
	//}


	//for (int i = 0; i < 5; ++i) {
	//	for (int j = 0; j < 5; ++j) {
	//		fill(&v[0][0], &v[0][0] + 5*5, 0);
	//		if (v[i][j]) continue;
	//		v[i][j] = 1;
	//		if (a[i][j] == 'Y') {
	//			dfs(0, i, j, 1, 0);
	//		}
	//		if (a[i][j] == 'S') {
	//			dfs(0, i, j, 0, 1);

	//		}
	//		//v[i][j] = 0;

	//		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
	//	}
	//}



	cout << ret;
}