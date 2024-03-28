#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret;
int n, c;
vector<ll> v;

//간격이 len 일때, 설치가능공유기가 c개이상인가?
//값차이가 len 이상이면, 설치하면 된다.
int go(ll len) {
	ll cnt = 1; //처음집에는 무조건 설치함
	ll cur = v[0];
	for (int i = 1; i < n; ++i) {
		if (v[i] - cur >= len) {
			cur = v[i];
			cnt++;
		}
	}
	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>c;
	for(int i=0;i<n;++i){
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	//* 매개변수 탐색!
	//1. 가장 인접한 공유기사이 거리를x로설정
	//2. x기준으로 공유기 설치
	//3. 공유기를 c개이상 설치가능 -> 여유있음 & 정답후보임-> x를늘리고 재탐색
	//4. c개이상 설치불가 -> x를 줄이고 다시탐색

	ll st = 1; //집간 최소거리
	ll en = v[n - 1] - v[0]; //집간 최대거리
	ll mid; //현재 간격
	while (st <= en) {
		mid = (st + en) / 2;

		//간격을 mid로 했더니 공유기가 c개이상임 -> 정답후보 -> 더큰mid가 있는지 탐색 
		if (go(mid)) {
			st = mid + 1;
			ret = max(ret, mid);
		}
		//공유기가 c개 미만임 -> 불가 -> 간격을줄여야함
		else {
			en = mid-1;
		}
	}

	
	cout << ret;
	return 0;
}