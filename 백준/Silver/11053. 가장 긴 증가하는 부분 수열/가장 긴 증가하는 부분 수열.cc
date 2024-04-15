#include <bits/stdc++.h>
using namespace std;

int n,a[1004],dp[1004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	//dp[i] : i포함시 최장수열의 길이
	// == 이전애들중 나보다작은애들중 제일큰값+1
	dp[0] = 1;

	for (int i = 1; i < n; ++i) {
		int mx = 0;
		for (int j = 0; j < i; ++j) {
			if (a[i] > a[j])
				mx = max(mx, dp[j]);
		}
		dp[i] = mx + 1;
	}
	
	//for (int i = 0; i < n; ++i) cout << dp[i] << " ";

	cout << *max_element(dp, dp + 1004);

	return 0;
}