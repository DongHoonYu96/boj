#include<bits/stdc++.h>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		stack<char> s;
		getline(cin, str);
		if (str == ".") break;

		bool is_wrong = false;
		for (char c : str) {
			//1.( -> push
			//2.) and 현재==( ->pop
			//3.) and 현제 == 빈칸 ->no

			if (c == '(') {
				s.push(c);
			}
			else if (c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (s.size() && s.top() == '(') {
					s.pop();
				}
				else if (s.size() && s.top() != '(') {
					is_wrong = true;
					break;
				}
				else if (s.empty()) {
					is_wrong = true;
					break;
				}
			}
			else if (c == ']') {
				if (s.size() && s.top() == '[') {
					s.pop();
				}
				else if (s.size() && s.top() != '[') {
					is_wrong = true;
					break;
				}
				else if (s.empty()) {
					is_wrong = true;
					break;
				}
			}
		}

		//짝이 안맞는경우
		//ex) [)
		if (is_wrong) {
			cout << "no\n";
			continue;
		}

		//폭팔안된 (가 남아있으면 no
		if (s.size()) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}
}