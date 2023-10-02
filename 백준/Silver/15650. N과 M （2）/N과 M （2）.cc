#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int isused[10];

//현재까지 k개의 수를 선택함.
void go(int k) {
	if (k==m){
		for (int i = 0; i < m; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	//조합은 시작점을 제한하면 된다.
	int st = 1;
	if (k != 0) st = arr[k - 1] + 1;	
	//시작지점 : 직전에 택한숫자 + 1
	//ex) 1 ,2 ,3 중 2개 선택시
	//1선택시 -> (arr[0]==1)+1 == 2

	for (int i = st; i <= n; ++i) {
		if (isused[i]) continue;
		arr[k] = i;
		isused[i] = 1;
		go(k+1);
		isused[i] = 0;
	}

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>m;
	go(0);
}