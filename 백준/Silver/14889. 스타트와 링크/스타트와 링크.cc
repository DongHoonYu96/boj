#include <bits/stdc++.h>

using namespace std;

int N,M,arr[24][24];
int ret = 987654321;

//n번째사람이 1팀으로감or2팀으로감
void dfs(int n, vector<int> a,vector<int> b) {
	if (n == N) {
		//팀원숫자가 같은경우만 정답갱신
		if (a.size() == b.size()) {
			int asum = 0, bsum = 0;
			for (int i = 0; i < M; ++i) {
				for (int j = 0; j < M; ++j) {
					asum += arr[a[i]][a[j]];
					bsum += arr[b[i]][b[j]];
				}
			}
			ret = min(ret, abs(asum - bsum));
		}
		return;
	}
	//1팀으로가는경우
	a.push_back(n);
	dfs(n + 1, a, b);
	a.pop_back();

	//2팀으로가는경우
	b.push_back(n);
	dfs(n + 1, a, b);
	b.pop_back();
}
int main() {
	cin.tie(0);

	cin >> N;
	M = N / 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	vector<int> v1, v2;
	dfs(0, v1,v2);
	cout << ret;
	return 0;
}