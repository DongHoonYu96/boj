#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 1. 테이블정의
* 2. 점화식 for문
*/

/*
* 1. 테이블정의
* d[i] : d[1]~d[i]번째까지의 누적합
* 

2.점화식
d[k] = d[k-1]+num

3.초기값 정하기


*/

int d[100004];
int n,m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>m;
	int num;

	for (int i = 1; i <= n; ++i) {
		cin >> num;
		d[i] = d[i - 1] + num;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a-1] << "\n";
	}


	return 0;

}