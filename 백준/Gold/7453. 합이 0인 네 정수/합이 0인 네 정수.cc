#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ret;
int n;
vector<ll> a,b,c,d,v1,v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i){
		ll q,w,e,r;
		cin >> q>>w>>e>>r;
		a.push_back(q);
		b.push_back(w);
		c.push_back(e);
		d.push_back(r);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	
	//1. v1배열에 a와+b를 조합한 숫자들을넣음
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			v1.push_back(a[i] + b[j]);
		}
	}
	//2.c배열에 c+d 숫자들넣기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			v2.push_back(c[i] +d[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); ++i) {
		int ub = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		int lb = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		ret += ub - lb;
	}


	cout << ret;
	return 0;
}