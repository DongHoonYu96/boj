#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int tc, n,dp[100004];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<ll> v;
		int cnt=0;

		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < n-1; ++i) {
			for (int j = i+1; j < n; ++j) {
				ll dist = v[j] - v[i];
				if (dist % 2) continue; //거리가 홀수다 -> mid가 x.5됨 -> 무조건 없음
				ll mid = v[i] + dist/2;
				
				//cout << v[i] << " " << mid << " " << v[j] << "\n";
				if (binary_search(v.begin(), v.end(), mid)) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	

	return 0;
}