#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret,n;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main() {
	cin.tie(0);

	cin >> n;
	while (n--) {
		ll op;
		cin >> op;
		if (op == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top()<<"\n";
			pq.pop();
		}
		else {
			pq.push(op);
		}

	}
	
	return 0;
}