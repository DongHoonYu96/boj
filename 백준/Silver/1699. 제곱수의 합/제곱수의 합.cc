#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int n,dp[100004];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	

	//dp[i][j] : i자연수 추가시 j를만드는 행의 최소갯수
	for (int j = 1; j < 100000; ++j) dp[j] = j;

	for (ll i = 2; i*i <= n; ++i) {
		ll a = i * i;
		for (int j = 1; j <= n; ++j) {
			if (j - a >= 0) {
				dp[j] = min(dp[j], dp[j - a] + 1);
			}
			/*else
				dp[j] = dp[j];*/

		}
	}
	
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cout << dp[i][j]<<" ";
		}
		cout << "\n";
	}*/

	cout << dp[n];

	return 0;
}