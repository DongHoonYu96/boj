#include <bits/stdc++.h>
using namespace std;

int n,s,ret;
int arr[24];

//현재깊이, 총합
void go(int cur, int tot) {
	if (cur==n){
		if (tot == s) {
			ret++;
		}
		return;
	}

	//재귀식
	//현재값을 안더하는경우
	go(cur+1, tot);
	//현재값을더하는경우
	go(cur+1,tot+arr[cur]);

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	go(0,0);
	if (s == 0) ret--;	//공집한인경우 제외하라는 조건있음
	cout << ret;
}