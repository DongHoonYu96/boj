#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 1. 테이블정의
* 2. 점화식 for문
*/

//1. d[i] : i를 1로 만드는데 필요한 연산수
//2. d[12] = d[4]+1 or d[6]+1 or d[11]+1
int d[1000004];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;


	for (int i = 4; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) {
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0) {
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}


	cout << d[n];
}