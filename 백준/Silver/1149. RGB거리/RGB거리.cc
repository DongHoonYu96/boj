#include <bits/stdc++.h>
using namespace std;

//i번째 집을 j색으로 칠했을때 최소비용, 칠한색깔(0:빨, 1:초, 2:파)
int d[1004][3], a[1004][3];
int n;

/*
* d[1][0]
* d[1][1]
* d[1][2]
* 
* d[k][0] : max(d[k-1][1]+a[k][0], d[k-1][2]+a[k][0])
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		cin >> a[i][1];
		cin >> a[i][2];
	}
	
	d[0][0] = a[0][0];
	d[0][1] = a[0][1];
	d[0][2] = a[0][2];
	
	for (int i = 1; i < n; ++i) {
		d[i][0] = min(d[i - 1][1] + a[i][0], d[i - 1][2] + a[i][0]);
		d[i][1] = min(d[i - 1][0] + a[i][1], d[i - 1][2] + a[i][1]);
		d[i][2] = min(d[i - 1][0] + a[i][2], d[i - 1][1] + a[i][2]);
	
	}

	int ret = d[n-1][0];
	ret = min(ret, d[n - 1][1]);
	ret = min(ret, d[n - 1][2]);

	cout << ret;




}