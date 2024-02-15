#include <bits/stdc++.h>

using namespace std;

int n, a[1000000+4], b, c,tot;
long long ret;

int main() {
	cin.tie(0);

	cin >> n;

	for(int i=0;i<n;++i) {
		cin >> a[i];
		tot += a[i];
	}
	cin>> b >> c;

	//각 시험장에 대해 검사필요
	
	for (int i = 0; i < n; ++i) {
		//총감독만으로 충분한경우 다음시험장검사
		ret++; //총감독은 반드시 있어야함
		if (a[i] <= b) {
			continue;
		}


		int res = a[i] - b; //감독해야하는 학생수
		
		if (res % c == 0) {
			ret += (res / c);
		}
		else {
			ret += (res / c);
			ret++;
		}
	}

	cout << ret;

	return 0;
}