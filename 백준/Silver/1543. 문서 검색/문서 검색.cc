#include <bits/stdc++.h>

using namespace std;
int ret;
string s,t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	getline(cin, t);
	for (int i = 0; i < s.size();) {
		string temp = s.substr(i, t.size());
		//cout << temp << " ";
		if (temp == t) {
			i += t.size();
			ret++;
		}
		else {
			++i;
		}

	}
	
	cout << ret;

	return 0;
}