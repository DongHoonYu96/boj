#include<bits/stdc++.h>
using namespace std;

int tc;
list<char> L;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {

		string s;
		cin >> s;
		auto now = L.begin();
		for (int i = 0; i < s.size(); ++i) {
			char op = s[i];
			if (op == '<') {
				if (now == L.begin()) continue;
				now--;
			}
			else if (op == '>') {
				if (now == L.end()) continue;
				now++;
			}
			else if (op == '-') {
				if (now == L.begin()) continue;
				now--;
				now=L.erase(now);
			}
			else {	//영어
				L.insert(now, op);
				//now++;
				
			}
		}

		for (auto i : L) {
			cout << i;
		}
		cout << "\n";
		L.clear();
	}

	
}