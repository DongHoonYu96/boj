#include <bits/stdc++.h>
using namespace std;

int n,ret;
int arr[10];
int isused1[40];	// | 에 퀸이있는지
int isused2[40];	// / 에 퀸이있는지
int isused3[40];	// \ 에 퀸이있는지

//cur번째 행(ㅡ)에 말을 놓는함수
void go(int cur) {
	if (cur == n) {
		//n번째 퀸을 놓는데 성공한경우
		ret++;
		return;
	}

	//(cur, i)에 말을 놓는다.
	for (int i = 0; i < n; ++i) {
		if (isused1[i]) continue;	//같은 | 에는 둘수없다
		if (isused2[i+cur]) continue;	// / 에는 둘수없다
		if (isused3[i - cur + n - 1]) continue;// \ 에는 둘 수 없다.

		isused1[i] = 1;
		isused2[i+cur] = 1;
		isused3[i-cur+n-1] = 1;
		go(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[i - cur + n - 1] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	go(0);
	cout << ret;
}