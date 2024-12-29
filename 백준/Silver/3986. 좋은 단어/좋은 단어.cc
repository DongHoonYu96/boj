#include<bits/stdc++.h>
using namespace std;

int n,ret;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		stack<char> s;
		string str;
		cin >> str;
		for (auto c : str) {
			if (s.size() && s.top() == c) {
				s.pop();
				continue;
			}
			s.push(c);

		}
		if (s.empty()) {
			ret++;
		}

	}

	cout << ret;
}