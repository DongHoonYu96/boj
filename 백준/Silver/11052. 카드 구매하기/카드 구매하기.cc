#include <bits/stdc++.h>
using namespace std;

int n,a[1004],dp[1004][1004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	//dp[i][j] : i번째 주머니 !!추가!!시, j개카드를 만드는데 드는 최대비용

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j - i >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j-i]+a[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
				
		}
	}
	
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cout << dp[i][j]<<" ";
		}
		cout << "\n";
	}*/

	cout << dp[n][n];

	return 0;
}