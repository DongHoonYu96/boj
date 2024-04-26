#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int t, w, dp[1004][3][34]; //idx, 위치, 제한
vector<int> v;

//인덱스, 위치, !남은!이동횟수
int dfs(int idx, int where, int cnt) {
	if (cnt < 0) {
		return -987654321;
	}
	if (idx == t) return 0;

	if (dp[idx][where][cnt]!=-1) return dp[idx][where][cnt];

	//이동 or 안이동
	//dfs(비트바꾸는경우 == 이동하는경우) , dfs(안이동) 중 큰값
	// + table값과 현재 위치가 같으면 +1
	// (뒤에 -1하는 이유는 1,2나무위치를 0,1로 바꾸기 위함!)
	dp[idx][where][cnt] = max(dfs(idx + 1, where ^ 1, cnt - 1), dfs(idx + 1, where, cnt))
		+ (where == v[idx] - 1); 

	return dp[idx][where][cnt];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp)); //3차원배열 초기화시 유용 0, -1로만 초기화가능
	// -1이면 최초방문임!

	cin >> t>>w;
	for (int i = 0; i < t; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	

	// 0,1 로 나무위치 변경시 장점 : 비트연산자로 간단한 코드가능!
	// ex) n^1 -> 0,1 서로변경 / if(value)로 간단한 코드가능
	// 
	//후다닥움직여서 1로이동 or 그대로 0에 있는경우
	cout << max(dfs(0, 1, w - 1), dfs(0, 0, w));
	

	return 0;
}