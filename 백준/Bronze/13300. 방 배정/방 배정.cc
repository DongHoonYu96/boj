#include<bits/stdc++.h>
using namespace std;

int n,k,visited[7][2],ret;
// [학년1-6][성별 / 여:0 / 남:1]

int main() {
	cin >> n>>k;
	for (int i = 0; i < n; ++i) {
		int a, b = 0;
		cin >> a >> b;	//성별,학년
		visited[b][a]++;
	}
	
	for (int i = 1; i <= 6; ++i) {
		for (int j = 0; j <= 1; j++) {
			ret += (visited[i][j]+1) / 2;	//올림구현
		}
	}

	cout << ret;
}