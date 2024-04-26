#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

//dp[i] : i날짜일때 최대수익
int n, dp[1500000+4],t[1500000 + 4],p[1500000 + 4]; //idx==day
vector<int> v;

//인덱스==현재날짜
int dfs(int idx) {
	//조건을 벗어난경로에는 -큰값배정 => 정답후보에서 배제하기 위함
	if (idx > n) {
		return -987654321;
	}
	// 노드뒤에서부터 시작값
	if (idx == n) return 0;

	//메모이제이션, 기존계산된값이 있다면 그거사용
	if (dp[idx]!=-1) return dp[idx];

	//상담함 or 상담안함
	//dfs(비트바꾸는경우 == 이동하는경우) , dfs(안이동) 중 큰값
	// + table값과 현재 위치가 같으면 +1
	// (뒤에 -1하는 이유는 1,2나무위치를 0,1로 바꾸기 위함!)
	dp[idx] = max(dfs(idx + t[idx]) + p[idx], dfs(idx + 1));

	return dp[idx];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp)); //3차원배열 초기화시 유용 0, -1로만 초기화가능
	// -1이면 최초방문임!

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a,b;
		cin >> a>>b;
		t[i] = a;
		p[i] = b;
	}
	

	// 0,1 로 나무위치 변경시 장점 : 비트연산자로 간단한 코드가능!
	// ex) n xor 1 -> 0,1 위치변경 / if(value)로 간단한 코드가능
	// 
	// level0 부터 바로 분기시작함.
	//후다닥움직여서 1로이동 or 그대로 0에 있는경우
	cout << dfs(0);
	

	return 0;
}