#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret,n,tmp;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n*n; ++i) {
		cin >> tmp;
		pq.push(tmp);
		if (n < pq.size()) pq.pop();
	}

	cout << pq.top();

	
	return 0;
}