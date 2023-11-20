#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m,ret,temp;
vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
	v.push_back(0);

	ll s = 0, e = 1, sum = v[0];
	while (1) {
		if (sum == m) ret++;
		if (sum <= m) sum += v[e++];
		if (sum > m)sum -= v[s++];
		if (e == v.size()) break;
	}
	cout << ret;
}