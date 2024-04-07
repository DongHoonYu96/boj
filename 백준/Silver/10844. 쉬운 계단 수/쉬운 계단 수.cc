#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d[104][12]; //오큰수의 갯수 [길이][시작숫자]
ll n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int j = 2; j <= 10; ++j) d[1][j] = 1;

	for (int i = 2; i <= 100; ++i) {
		for (int j = 1; j <= 10; ++j) {
			d[i][j] = (d[i-1][j-1] % 1000000000 +d[i-1][j+1] % 1000000000)%1000000000;
		}
	}

	ll ret = 0;
	for (int j = 0; j <= 10; ++j) ret = (ret % 1000000000 + d[n][j] % 1000000000)% 1000000000;
	cout << ret;

	return 0;
}