#include <bits/stdc++.h>
using namespace std;

int a;
vector<int> v;

int func(int a) {
	if (a % 4 == 0 and a%100!=0) {
		return 1;
	}
	if (a % 400 == 0) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a;
	cout << func(a);

}