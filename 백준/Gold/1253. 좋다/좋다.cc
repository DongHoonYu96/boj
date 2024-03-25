#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret;
int n,vis[2004];
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

	sort(v.begin(), v.end());
	//for (auto i : v) cout << i << " ";
	//cout << "\n";

	for (int i = 0; i < n-1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll cur = v[i]+v[j];
			//cout << i << " " << j << "\n";
			int LB = lower_bound(v.begin() , v.end(), cur) - v.begin();
			int UB = upper_bound(v.begin(), v.end(), cur) - v.begin();

			//해당수가 존재하는경우
			if (UB - LB) {
				//cout << i << " " << j <<" " << v[LB] << "\n";
				if (vis[LB]) continue; //해당수는 이미 좋은수인경우 패스
				if (i == LB || j == LB) continue;
				ret += (UB - LB);
				vis[LB] = 1;
			}
			//ret += (UB - LB);
			//cout << i << " " << j << "\n";
			//int idx = lower_bound(v.begin() + i + 1, v.end(), cur) - v.begin();
			//for (int k = -1; k <= 1; ++k) {
			//	if (idx + k < 0 || idx + k >= n) continue; //범위쳌
			//	if (idx + k == i) continue; //자기자신제외
			//	if (abs(ret) > abs(cur + v[idx + k])) { //정답갱신
			//		ret++;
			//	}
			//}
		}
		
	}
	
	cout << ret;
	return 0;
}