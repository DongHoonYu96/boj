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
* d[i]: 2*i크기의 직사각형을 채우는 방법의 수
* ||||||||||
* ||||||||||
* 
* d[k] : 첫사각형을 |로 두는경우 -> (맨앞줄제거한)d[k-1]과 같음
* 첫사각형을 ㅡ 로 두는경우-> 밑에도 ㅡ로 둬야함 -> (두줄제거한)d[k-2]와 같음.

2.점화식
d[k] = d[k-1]+d[k-2]

3.초기값 정하기
d[1]=1
d[2]=2

*/

int d[1004], score[304];
int tc,n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	d[1] = 1;
	d[2] = 2;


	for (int i = 3; i <= n; ++i) {
		d[i] = (d[i - 1] + d[i - 2])%10007;
	}

	cout << d[n] << "\n";

	return 0;

}