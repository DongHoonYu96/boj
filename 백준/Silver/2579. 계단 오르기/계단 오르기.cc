#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 1. 테이블정의
* 2. 점화식 for문
*/

/*
* 
* 1. 테이블정의
* d[i][j] : 현재까지 j개의 계단연속 밟음, 
i번째 계단까지 왔을때 점수합의 최대값
i번째 계단을 꼭 밟아야함.

2.점화식
d[k][1] : k번째 계단까지왓는데 "연속" 1개밟음->자기자신임->d[k-1]은 안밟
->d[k-2]만 밟 -> max(d[k-2][1], d[k-2][2]) + score[k]
d[k][2] : k번째 계단왓는데 "연속" 2개밟음 -> 자기자신+d[k-1]밟 ->d[k-2]는 불가
->d[k-1][1]+score[k]

3.초기값 정하기

*/

int d[304][3], score[304];
int tc,n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> score[i];
	}
	d[0][1] = 0;
	d[1][1] = score[1];
	d[2][1] = score[2];
	d[2][2] = score[1]+score[2];

	for (int i = 3; i <= n; ++i) {
		d[i][1] = max(d[i-2][1],d[i-2][2])+score[i];
		d[i][2] = d[i-1][1]+score[i];
	}

	cout << max(d[n][1],d[n][2]) << "\n";

	return 0;

}