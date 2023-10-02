#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[15], isused[15], arr[15];

//현재 q개뽑았음
void go(int q) {
	if (q == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << a[arr[i]] << " ";
		}
		cout << "\n";
		return;
	}

	int st = 0;
	if (q != 0) st = arr[q - 1];

	for (int i = st; i < k; ++i) {
		if (isused[i]) continue;
		arr[q] = i;
		isused[i] = 1;
		go(q + 1);
		isused[i] = 0;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> k;
		if (k == 0) break;

		// k C 6 구현
		for (int i = 0; i < k; ++i) {
			cin >> a[i];
		}

		go(0);

		cout << "\n";

	}
	
}