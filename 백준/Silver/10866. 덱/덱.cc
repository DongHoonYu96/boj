#include<bits/stdc++.h>
using namespace std;

int n;
deque<int> d;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string op = "";
		cin >> op;
		if (op == "push_front") {
			int temp = 0;
			cin >> temp;
			d.push_front(temp);

		}
		else if (op == "push_back") {
			int temp = 0;
			cin >> temp;
			d.push_back(temp);
		}
		else if (op == "pop_front") {
			if (d.empty()) {
				cout << "-1\n";
				continue;
			}
			int temp = d.front();
			cout << temp << "\n";
			d.pop_front();
		}
		else if (op == "pop_back") {
			if (d.empty()) {
				cout << "-1\n";
				continue;
			}
			int temp = d.back();
			cout << temp << "\n";
			d.pop_back();
		}
		else if (op == "size") {
			cout << d.size() << "\n";
		}
		else if (op == "empty") {
			cout << d.empty() << "\n";
		}
		else if (op == "front") {
			if (d.empty()) cout << "-1\n";
			else cout << d.front() <<"\n";
		}
		else if (op == "back") {
			if (d.empty()) cout << "-1\n";
			else cout << d.back() << "\n";
		}
	}

}