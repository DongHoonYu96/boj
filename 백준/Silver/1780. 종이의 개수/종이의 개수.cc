#include <bits/stdc++.h>
using namespace std;

int n,ret1,ret2,ret3, a[2200][2200];

bool all_same(int n, int y, int x) {

	int first = a[y][x];
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (a[i][j] != first) {
				return false;
			}
		}
	}

	return true;

}

//함수정의 : 크기n*n, 시작좌표 
void go(int n, int y, int x) {
	//기저사례
	if (all_same(n,y,x)) {

		if (a[y][x] == -1) {
			ret1++;
		}
		if (a[y][x] == 0) {
			ret2++;
		}
		if (a[y][x] == 1) {
			ret3++;
		}
		return;
	}

	int one_third = n / 3;
	//재귀식
	go(one_third,y,x);
	go(one_third, y, x+ one_third);
	go(one_third, y, x+ one_third*2);
	go(one_third, y+ one_third, x);
	go(one_third, y+ one_third, x+ one_third);
	go(one_third, y+ one_third, x+ one_third*2);
	go(one_third, y+ one_third*2, x);
	go(one_third, y+ one_third*2, x+ one_third);
	go(one_third, y+ one_third*2, x+ one_third*2);



}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	go(n, 0, 0);

	cout << ret1 << "\n" << ret2 << "\n" << ret3;

}