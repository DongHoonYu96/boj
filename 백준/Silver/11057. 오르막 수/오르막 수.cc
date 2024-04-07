#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int d[1004][10]; //오큰수의 갯수 [길이][시작숫자]
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	fill(&d[0][0], &d[0][0] + 1000 * 10, 1);
	for (int i = 2; i <= 1001; ++i) {
		for (int j = 0; j <= 9; ++j) {
			ll sum = 0;
			for (int k = j; k <= 9; ++k) {
				sum += d[i - 1][k]%10007;
			}
			d[i][j] = sum;
		}
	}

	cout << d[n + 1][0]%10007;

	return 0;
}