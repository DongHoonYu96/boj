#include<bits/stdc++.h>
using namespace std;

string s;
int m;
list<char> L;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		L.push_back(s[i]);
	}
	auto now = L.end();
	//cout << *now;

	cin >> m;
	while (m--) {
		char op;
		cin >> op;
		if (op == 'P') {
			char c;
			cin >> c;
			L.insert(now, c);
		}
		else if (op == 'L') {
			if (now == L.begin()) continue;
			now--;
		}
		else if (op == 'D') {
			if (now == L.end()) continue;
			now++;
		}
		else if (op == 'B') {
			if (now == L.begin()) continue;
			now--;
			now=L.erase(now);
		}
	}

	for (auto i : L) {
		cout << i;
	}
}