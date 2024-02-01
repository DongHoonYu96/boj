#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m,vis[500000+4];
vector<ll> a,b;
vector<ll> ans;

int main() {
	cin.tie(0);

	cin >> n>>m;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < m; ++i) {
		ll tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (auto i : a) {
		if (binary_search(b.begin(), b.end(), i)) continue;
		ans.push_back(i);
	}

	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";

	return 0;
}