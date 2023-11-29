#include <bits/stdc++.h>
using namespace std;

int n, k;
int vis[100000 + 4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >>k;
	
	//비용, 정점
	priority_queue <pair<int, int>,
					vector<pair<int,int>>,
					greater<>> pq;
	
	//비용이 적은것부터 탐색함
	pq.push({ 0,n});
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		//cout << cur.first << " " << cur.second << "\n";

		if (cur.second < 0 || cur.second >= 100000 + 4) continue;
		if (cur.second == k) {
			cout << cur.first;
			return 0;
		}

		if (vis[cur.second]) continue;
		vis[cur.second] = 1;
		pq.push({ cur.first + 1, cur.second + 1 });
		pq.push({ cur.first + 1, cur.second - 1 });
		pq.push({ cur.first, cur.second*2 });
	}

	return 0;
}