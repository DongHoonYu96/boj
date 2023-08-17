#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main() {
	cin >> n;
	while (n--) {
		string op="";
		cin >> op;
		if (op == "push") {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (op == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (op == "size") {
			cout << q.size() << "\n";
		}
		else if (op == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (op == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << q.front() << "\n";
		}
		else if (op == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << q.back() << "\n";
		}
	}
}