#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k,ret,temp;
vector<ll> v;
int vis[1000000 + 1];	//해당숫자 방문했는지 여부

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n>>k;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		v.push_back(temp);
	}
	//v.push_back(0);

	if (n == 1) {
		cout << 1;
		return 0;
	}


	ll e = 0, ret = 0;
	for (int s = 0; s < n; ++s) {
		//홀수의 갯수가 k개이하인동안
		while (e < n && vis[v[e]]<k) {
			vis[v[e]]++;
			e++;
		}
		ret = max(ret, e - s);
		vis[v[s]]--;	//다음반복문위해 홀수갯수 갱신(시작부분이 홀수이면 제거)
	}
	cout << ret;
}