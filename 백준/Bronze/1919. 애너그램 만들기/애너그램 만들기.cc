#include <bits/stdc++.h>
using namespace std;

int ret,a[26];
string s1, s2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s1>>s2;

	for (auto c : s1) {
		a[c - 'a']++;
	}
	for (auto c : s2) {
		a[c - 'a']--;
	}

	//for (auto i : a) cout << i << " ";
	for (int i = 0; i < 26;++i) {
		if (a[i] != 0) {
			ret += abs(a[i]);
		}
	}

	cout << ret;
}