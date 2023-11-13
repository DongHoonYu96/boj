#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100004];
int ret = 0x7fffffff;

/*
* 투포인터
* 1.정렬
* 2.for(st=0~n)
* 3. while(en범위쳌 && 조건만족안하면) en++
* 4. 정답갱신
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	int en = 0;
	for (int st = 0; st < n; ++st) {
		while (en < n && a[en] - a[st] < m) en++;
		if (en == n) break; //범위쳌
		ret = min(ret, a[en] - a[st]);
	}
	cout << ret;
}