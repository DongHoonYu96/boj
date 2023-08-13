#include <bits/stdc++.h>
using namespace std;

long a, b, c;
int visited[10];
int main() {
	cin >> a >> b >> c;

	long num = a * b * c;
	string s=to_string(num);
	for (auto c : s) {
		visited[c - '0']++;
	}

	for (auto i : visited) {
		cout << i << "\n";
	}

}