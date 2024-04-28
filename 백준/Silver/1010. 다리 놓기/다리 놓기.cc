#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll tc, n,m, dp[34];

//n!의 값
ll dfs(int n) {
	//기저사례
	//!조건불만족하면 리턴! 이 return이 먼저와야함!! -> 그래야 배제가능.
	// 안그러면, 조건불만족 인데 idx==n인 경우도 유효한 경우로 카운팅됨.
	if (n==0) {
		return 1;
	}
	
	if (dp[n]!= -1) return dp[n];

	dp[n] = dfs(n - 1)*n;

	return dp[n];
}
ll fac(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * fac(n - 1);

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	//dfs(30);
	//cout << dp[5];
	//return 0;
	//for (int i = 0; i < 30; ++i) cout << "dp"<<i<<": "<<dp[i] << "\n";
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		ll result = 1;
		int r = 1;
		for (int i = m; i > m - n; i--) {
			result = result * i;
			result = result / r;
			++r;
		}
		cout << result<<"\n";
	}
	return 0;
}