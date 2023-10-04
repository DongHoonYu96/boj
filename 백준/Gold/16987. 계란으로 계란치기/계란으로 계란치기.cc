#include <bits/stdc++.h>
using namespace std;

int n, v[10], ret;
vector<pair<int, int>> eggs;

//현재 k번째 계란을 들고 깨려고함
void go(int k) {
	if (k >= n) {
		int died_count = 0;
		for (auto p : eggs) {
			//cout << p.first << " ";
			if (p.first <= 0) died_count++;
		}
		//cout << "\n";

		ret = max(ret, died_count);
		return;
	}

	//들고있는계란이 깨진경우
	if (eggs[k].first <= 0) {
		go(k + 1);
	}
	else {
		//때릴대상
		bool on = false;
		for (int i = 0; i < n; ++i) {
			if (i == k) continue; //자기자신은 못때림
			if (eggs[i].first <= 0) continue; //깨진계란은 못때림

			on = true;
			eggs[k].first -= eggs[i].second;	//계란깨기
			eggs[i].first -= eggs[k].second;
			go(k + 1);//다음번째 계란을 들기
			eggs[k].first += eggs[i].second;	//원복
			eggs[i].first += eggs[k].second;

		}
		//때릴대상이 없는경우
		if(!on) go(k + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//1. 드는계란 idx : 0~n-1
	//2. 치는계란 : n-1 C 1

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		eggs.push_back({ a,b });
	}

	//계란집기
	go(0);

	cout << ret;
}