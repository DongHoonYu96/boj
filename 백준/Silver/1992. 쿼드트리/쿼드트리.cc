#include <bits/stdc++.h>
using namespace std;

int n, a[150][150];
string ret;

//시작좌표~끝좌표(시작좌표+n)까지 돌면서 모두같은지 검사
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

		if (a[y][x] == 0) {
			ret += "0";
		}
		if (a[y][x] == 1) {
			ret += "1";
		}

		return;
	}

	int half = n / 2;
	//재귀식
	//4칸으로 나눈후 각각칸의 시작좌표를 구했음.

	//시작할때 괄호열어
	ret += "(";

	go(half, y, x);
	go(half, y, x+half);
	go(half, y+half, x);
	go(half, y+half, x+half);
	//종료할때 괄호닫어
	ret += ")";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; ++j) {
			a[i][j]= temp[j] - '0';
		}
	}

	go(n, 0, 0);

	cout <<ret;

}