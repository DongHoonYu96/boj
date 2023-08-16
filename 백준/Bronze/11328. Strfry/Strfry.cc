#include <bits/stdc++.h>
using namespace std;

int tc,v1[26], v2[26];
string s1, s2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> tc;

	for (int i = 0; i < tc; ++i) {
		fill(v1,v1+26,0);
		fill(v2, v2 + 26, 0);
		/*
		* str1 과 str2의
		* 알파벳 갯수가 같으면 possible이다.
		*/
		cin >> s1 >> s2;
		if (s1.size() != s2.size()) {
			cout << "Impossible\n";
			continue;
		}
		for (int i = 0; i < s1.size(); ++i) {
			v1[s1[i] - 'a']++;
			v2[s2[i] - 'a']++;
		}

		bool all_same = true;
		for (int i = 0; i < 26; ++i) {
			if (v1[i] != v2[i]) {
				all_same = false;
				break;
			}
		}
		if (all_same) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}
}