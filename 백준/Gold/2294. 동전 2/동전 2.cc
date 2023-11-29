#include <bits/stdc++.h>
using namespace std;

int n, k,coin;
int dp[10000 + 4]; //dp[i] : i원을 만들수있는 경우의수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dp, dp + 10000 + 4, 10004); //최소값구해야함 -> 최대값으로 초기화

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) { //동전만큼 회차
		cin >> coin;
		for (int j = coin; j <= k; ++j) {
			dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}
	if (dp[k] == 10004) cout << -1;
	else cout << dp[k];

	return 0;
}