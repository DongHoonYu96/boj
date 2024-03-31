#include <bits/stdc++.h>

using namespace std;
string s,ret;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i]>='a' && s[i]<='z') {
			ret += toupper(s[i]);
		}
		else {
			ret += tolower(s[i]);
		}
	}
	cout << ret;
	return 0;
}