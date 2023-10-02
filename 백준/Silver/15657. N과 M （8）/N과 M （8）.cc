#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[10],arr[10];
int isused[10];

//현재까지 k개의 수를 선택함.
void go(int k) {
	if (k==m){
		for (int i = 0; i < m; ++i) {
			cout << num[arr[i]] << " ";
		}
		cout << "\n";
		return;
	}

	//스타트=> 조합구현
	int st = 0;
	if (k != 0) st = arr[k - 1];

	for (int i = st; i < n; ++i) {
		//if (isused[i]) continue;
		arr[k] = i;	//arr에 인덱스를 기록, return에서 인덱스로 접근하면됨.
		isused[i] = 1;
		go(k+1);
		isused[i] = 0;
	}

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	sort(num,num+n);	//정렬 end 제한 => 입력안된 0초기값 정렬안되게

	go(0);
}