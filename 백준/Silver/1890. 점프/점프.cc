#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[104][104],a[104][104]; //오큰수의 갯수 [길이][시작숫자]
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (a[i][j] == 0) continue;
			if (dp[i][j] == 0) continue;
			int jump = a[i][j];
			if (i + jump <= 100) dp[i + jump][j] += dp[i][j];
			if (j + jump <= 100) dp[i][j + jump] += dp[i][j];
		}
	}

	cout << dp[n-1][n-1];

	return 0;
}