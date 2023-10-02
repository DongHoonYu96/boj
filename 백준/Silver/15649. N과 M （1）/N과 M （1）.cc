#include <bits/stdc++.h>
using namespace std;

int v[9];
vector<int> result;
int n, m;

void go() {
	if (result.size() == m) {
		for (auto i : result) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		v[i] = 1;
		result.push_back(i);
		go();
		result.pop_back();
		v[i] = 0;
	}

}

int main() {

	cin >> n >> m;

	go();


	return 0;
}