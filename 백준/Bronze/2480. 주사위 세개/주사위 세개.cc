#include <bits/stdc++.h>
using namespace std;

int a,b,c;
vector<int> v;
int ret;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a>>b>>c;

	if (a == b and b == c) {
		ret = 10000 + a * 1000;
	}
	else if (a == b and b != c) {
		ret = 1000 + a * 100;
	}
	else if (b == c and a != c) {
		ret = 1000 + b * 100;
	}
	else if (a == c and a != b) {
		ret = 1000 + a * 100;
	}
	else if (a != b and a != c and b != c) {
		int max = 0;
		if (a > max)max = a;
		if (b > max)max = b;
		if (c > max) max = c;
		ret = 100 * max;
	}

	cout << ret;

}