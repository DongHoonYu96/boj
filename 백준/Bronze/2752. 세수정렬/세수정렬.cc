#include <bits/stdc++.h>
using namespace std;

int a, b, c;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; ++i) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	for (auto i : v) {
		cout << i<<" ";
	}

}