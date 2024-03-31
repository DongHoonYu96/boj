#include <bits/stdc++.h>

using namespace std;
int vis[204];
vector<int> v;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		int c = toupper(s[i]);
		vis[c]++;
	}
	
	int m = *max_element(vis, vis + 204);
	for (int i = 'A'; i <= 'Z'; ++i) {
		if (m == vis[i]) {
			//cout << (char)i<<" ";
			v.push_back(i);
		}
	}

	if (v.size() == 1) cout << (char)v[0];
	else cout << "?";

	return 0;
}