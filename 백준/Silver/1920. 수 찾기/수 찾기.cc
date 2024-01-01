#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;

int main() {
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int target;
		cin >> target;
		cout << binary_search(v.begin(), v.end(), target)<<"\n";
	}


	return 0;
}