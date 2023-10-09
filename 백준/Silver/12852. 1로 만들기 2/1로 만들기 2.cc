#include <bits/stdc++.h>
using namespace std;

/*
* DP
* 1. 테이블정의
* 2. 점화식 for문
*/

/*
* 1. 테이블정의
* d[i][j] : i를 1로만드는데 필요한 연산의 최소값 
/ 그때사용한 연산 j(1:-1 , 2:/2 , 3:*3)
* 

2.점화식
d[k] = 
3로 나누어떨어지는 경우 : d[k/3]+1
2로 나누어떨어지는 경우 : d[k/2]+1
d[k-1]+1 
중 최소값


3.초기값 정하기
d[1] = 0
d[2] = 1
d[3] = 1

*/

int d[1000004] , d2[1000004][4];
int n;
int ret = 10000009;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;

	d2[1][0] = 0;
	d2[2][2] = 1;
	d2[3][3] = 1;



	for (int i = 4; i <= n; ++i) {
		int op = 1;
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1) {
				op = 3;
				d[i] = d[i / 3] + 1;
			}

		}
		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1) {
				op = 2;
				d[i] = d[i / 2] + 1;
			}
		}

		if (op == 1) {
			d2[i][1] = 1;
		}
		else if (op == 2) {
			d2[i][2] = 1;

		}
		else if(op==3){
			d2[i][3] = 1;

		}

	}
	
	cout << d[n]<<"\n";
	cout << n << " ";
	while (n != 1) {
		if (d2[n][1]) {
			n--;
			cout << n << " ";
		}
		else if (d2[n][2]) {
			n/=2;
			cout << n << " ";
		}
		else if (d2[n][3]) {
			n/=3;
			cout << n << " ";
		}
	}	

	return 0;

}