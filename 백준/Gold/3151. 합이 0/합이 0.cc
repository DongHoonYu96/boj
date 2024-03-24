#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret;
int n;
vector<ll> v;
set<tuple<int, int, int>> s;
int vis[10004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i){
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	//for (auto i : v) cout << i << " ";
	//cout << "\n";

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cur = v[i] + v[j];
			//cout << cur << " ";
			int lb = lower_bound(v.begin()+j+1, v.end(), -1 * cur)-v.begin();
			int ub = upper_bound(v.begin()+j+1, v.end(), -1 * cur) - v.begin();
			ret += ub - lb;
			
		}
	}
	cout << ret;
	return 0;
}