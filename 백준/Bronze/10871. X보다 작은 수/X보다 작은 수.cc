#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>x;

	for (int i = 0; i < n; ++i) {
		int temp = 0;
		cin >> temp;
		if (temp < x) {
			v.push_back(temp);
		}
	}

	for (auto i : v) {
		cout << i << " ";
	}
}