#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 1. 테이블정의
* 2. 점화식 for문
*/

//1. d[i] : i를 1,2,3의 합으로 나타내는 방법의 수
/*
* d[1]=1
* d[2]=1+1 d[1] / 2 /
* d[3]=1+1+1 d[1] / 1+2 d[2]+1 / 2+1 d[2]+1 / 3 /
* 기준 : 맨뒤에 더하는 숫자
* d[4]=1+1+1+1, 3+1, 2+1+1, 1+2+1 : d[3]뒤에 +1 붙인것과 같음
* 1+1+2, 2+2 : d[2]뒤에 +2 붙인것과 같음
* 1+3 : d[1]뒤에 +3 붙인것과 같음
* d[i]=d[i-1]+d[i-2]+d[i-3]
*/
int d[12];
int tc,n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	d[4] = 7;

	for (int i = 5; i < 12; ++i) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	while (tc--) {

		cin >> n;
		cout << d[n] << "\n";
	}

	return 0;

}