#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret=200000000+1;
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

	for (int i = 0; i < n; ++i) {
		ll cur = v[i];
		int idx = lower_bound(v.begin()+i+1, v.end(),-1*v[i]) - v.begin();
		for (int k = -1; k <= 1; ++k) {
			if (idx + k < 0 || idx + k >= n) continue; //범위쳌
			if (idx + k == i) continue; //자기자신제외
			if (abs(ret) > abs(cur + v[idx + k])) { //정답갱신
				ret = cur + v[idx + k];
			}
		}
	}
	cout << ret;
	return 0;
}