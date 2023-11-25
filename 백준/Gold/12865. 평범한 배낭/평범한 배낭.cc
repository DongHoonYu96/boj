#include <bits/stdc++.h>
using namespace std;

int n, k,ret;
int d[104][100000+4]; // i번째 물건까지 왔을때 최대가치, 제한무개 j
int weight[100 + 4];
int value[100 + 4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			//i번째 물건을 넣을수 없는경우
			if (j < weight[i]) {
				d[i][j] = d[i - 1][j]; 
				//기존에 탐색했던 물건들을 이용해서 무게 j를 만든 최대가치와 동일
			}
			//i번째 물건을 넣을수 있는경우
			else {
				//기존에 탐색했던 물건들로 무게j를 만드는경우
				//기존에 탐색했던 물건들로 무게 j-weight[i]를 만들고, 넣기
				//중 가치가큰값
				d[i][j] = max(d[i - 1][j], d[i - 1][j - weight[i]] + value[i]);
			}
				
		}
	}
	cout << d[n][k];
	
	return 0;
}