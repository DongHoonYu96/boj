#include <bits/stdc++.h>

using namespace std;

int n,vis[16],ret;
vector<pair<int, int>> v1,v2;

void dfs(int day, int money) {

	if (day == n) {
		ret = max(ret, money);
		return;
	}
	if (day > n) return;

	dfs(day+v1[day].first, money + v1[day].second); //해당강의선택
	dfs(day+1, money); //미선택
}
bool cmp(pair<int,int> p1, pair<int,int> p2) {
	if (p1.first == p2.first) {
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}
int main() {
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v1.push_back({ a,b });
	}

	dfs(0, 0);
	cout << ret;
	//sort(v1.begin(), v1.end(),cmp);

	/*for (auto p : v1) {
		if (vis[p.first]) continue;
		vis[p.first] = 1;
		v2.push_back({ p.first,p.second });
	}

	for (auto p : v2) {
		cout << p.first << " " << p.second<<"\n";
	}*/


	return 0;
}