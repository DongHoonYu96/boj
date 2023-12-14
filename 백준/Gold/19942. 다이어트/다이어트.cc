#include <bits/stdc++.h>

using namespace std;

int n, m, mp, mf, ms, mv;
int a[15][5];
int ret = 987654321;
vector<int> arr;


int main() {
	cin.tie(0);
	cin >> n >>  mp >> mf >> ms >> mv;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3]>>a[i][4];
	}

	for (int subset = 1; subset < (1 << n); ++subset) {
		int p = 0, f = 0, s = 0, v = 0, w=0;
		vector<int> tmp;
		for (int i = 0; i < n; ++i) {
			if (subset & (1 << i)) {
				p += a[i][0];
				f += a[i][1];
				s += a[i][2];
				v += a[i][3];
				w += a[i][4];
				tmp.push_back(i+1);
			}
		}
		//cout << p << " " << f << " " << s << " " << v << " \n";
		if (p >= mp && f >= mf && s >= ms&& v>=mv) {
			if (ret > w) {
				ret = w;
				arr = tmp;
			}
			if (ret == w) {
				vector<vector<int>> vv;
				vv.push_back(tmp);
				vv.push_back(arr);
				sort(vv.begin(), vv.end());
				arr = vv[0];
			}
		}
	}

	if (ret == 987654321) {
		cout << -1;
		return 0;
	} 
	cout << ret << "\n";
	for (auto i : arr) cout << i << " ";

	return 0;
}