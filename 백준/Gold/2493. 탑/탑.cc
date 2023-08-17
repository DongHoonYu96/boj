#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int, int>> s;	//높이,인덱스

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/**
	* 1. 맨왼쪽에 {100,000,001 / idx 0} 의 탑이있다고 가정
	* 1.5 push
	* 2. 나보다 작은 타워는 쓸모없음 -> 모두 pop 
	* 3. 내 좌측에는 나보다 큰 타워만남음 == 레이저맞음
	*/
	cin >> n;
	s.push({ 100000001,0 });
	for (int i = 1; i <= n; ++i) {
		int height;
		cin >> height;
		
		while (height > s.top().first) {
			s.pop();
		}
		cout << s.top().second<<" ";

		s.push({ height,i });
	}
}