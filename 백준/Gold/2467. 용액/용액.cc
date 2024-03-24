#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret1=1000000000+1, ret2=1000000000+1;
int n;
vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i){
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(v.begin(), v.end(), -1 * v[i])-v.begin();
		//cout << idx << "\n";

		if (idx - 1 >= 0 && abs(v[i] + v[idx - 1]) < abs(ret1 + ret2)
			&& v[i]!=v[idx-1]) {
			ret1 = v[i];
			ret2 = v[idx - 1];
			//cout << v[i] << " " << v[idx - 1] << "\n";
		}

		if (idx <n && abs(v[i] + v[idx]) < abs(ret1 + ret2)
			&& v[i] != v[idx]) {
			ret1 = v[i];
			ret2 = v[idx];
		}

		if (idx + 1 <n && abs(v[i] + v[idx + 1]) < abs(ret1 + ret2)
			&& v[i] != v[idx + 1]) {
			ret1 = v[i];
			ret2 = v[idx + 1];
		}

	}
	cout << ret1 << " " << ret2;

	return 0;
}