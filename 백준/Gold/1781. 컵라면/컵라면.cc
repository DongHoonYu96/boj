#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class cmp {
public:
	bool operator () (pair<ll, ll> p1, pair<ll, ll> p2) {
		if (p1.first == p2.first) {
			return p1.second < p2.second;
		}
		return p1.first > p2.first;
	}
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,cmp> pq;
priority_queue<ll, vector<ll>, greater<int>> pqans;

ll n,ret;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	/*while (pq.size()) {
		cout << pq.top().first << " " << pq.top().second << "\n";
		pq.pop();
	}*/

	int day = 1;
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		//데드라인중 최대값을 ans큐에 넣는다
		if (day <= cur.first) {
			pqans.push(cur.second);
			day++;
		}
		else {
			//같은데드라인중 더작은값은 자동으로패스됨
			//이전데드라인(ans.top)을 선택하지않는것이 최적인경우
			if (pqans.top() < cur.second) {
				pqans.pop();
				pqans.push(cur.second);
			}
		}
	}

	while (pqans.size()) {
		ret += pqans.top();
		pqans.pop();
	}

	cout << ret;
	return 0;
}