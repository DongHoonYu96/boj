#include <bits/stdc++.h>
using namespace std;

int n;
char a[2500][2500];


//함수정의 : n만큼의 범위에 *-' ' 채워넣기 , 시작좌표 
void go(int n, int y, int x) {
	//기저사례는 최대한 간단히(원소1개만 처리할정도로)
	if (n==1) {

		a[y][x] = '*';
		return;
	}

	//재귀식
	//9칸으로 나눈후 각각칸의 시작좌표를 구했음.
	//단, 중앙인경우는 pass(빈칸)
	//ex)!가 시작좌표임.
	// (0,0) (0,3) (0,6) == (y,x) (y,x+n/3*1) (y,x+n/3*2)
	//! * * ! * * ! * *
	//*
	//*
	//...

	int num = n / 3;
	go(num, y, x);
	go(num, y, x+num*1);
	go(num, y, x+num*2);
	go(num, y+ num * 1, x);
	//go(num, y+num*1, x+num*1); pass(공백)
	go(num, y+ num * 1, x+ num * 2);
	go(num, y+ num * 2, x);
	go(num, y+ num * 2, x+ num * 1);
	go(num, y+ num * 2, x+ num * 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//2차원 배열 초기화 방법
	for (int i = 0; i < n; ++i) {

		fill(a[i], a[i] + n, ' ');
	}

	go(n, 0, 0);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << "\n";
	}


}