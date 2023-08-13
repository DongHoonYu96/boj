#include <bits/stdc++.h>
using namespace std;

int n, x, visited[2000004], ret;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
		visited[temp] = 1;
	}
	cin >> x;

	for (int i = 0; i < n; ++i) {
		if (x < v[i]) continue;	
		//목표보다 현재값이 큰경우 -> 불가

		if (visited[x - v[i]]) { //목표값이 잇으면 ret++
			ret++;
		}
		else {
			//pass
		}
	}

	cout << ret / 2;

}