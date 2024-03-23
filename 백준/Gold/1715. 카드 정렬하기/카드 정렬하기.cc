#include <bits/stdc++.h>

using namespace std;

int ret,n;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
	cin.tie(0);

	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}


	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		if (pq.empty()) break;

		auto nxt = pq.top(); pq.pop();
		//cout << cur << " " << nxt << " \n";
		pq.push(cur + nxt);
		ret+= (cur + nxt);
	}

	cout << ret;
	return 0;
}