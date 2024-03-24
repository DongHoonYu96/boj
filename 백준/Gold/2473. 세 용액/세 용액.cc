#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret1=1000000000,ret2 = 1000000000,ret3 = 1000000000;
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
			int idx = lower_bound(v.begin()+j+1, v.end(), -1 * cur)-v.begin();
			
			//정답후보 : idx-1,idx,idx+1
			if (idx - 1 >= 0 && abs(ret1 + ret2 + ret3) > abs(cur + v[idx - 1])
				&&idx-1 !=i &&idx-1!=j) {
				ret1 = v[i];
				ret2 = v[j];
				ret3 = v[idx-1];
			}
			if (idx < n && abs(ret1 + ret2 + ret3) > abs(cur + v[idx])
				&& idx  != i && idx  != j) {
				ret1 = v[i];
				ret2 = v[j];
				ret3 = v[idx];
			}
			if (idx + 1 <n && abs(ret1 + ret2 + ret3) > abs(cur + v[idx + 1])
				&& idx + 1 != i && idx + 1 != j) {
				ret1 = v[i];
				ret2 = v[j];
				ret3 = v[idx+1];
			}
			
		}
	}
	cout << ret1<<" "<<ret2<<" "<<ret3;
	return 0;
}