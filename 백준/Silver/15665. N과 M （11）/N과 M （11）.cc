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
	/*int st = 0;
	if (k != 0) st = arr[k - 1];*/

	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		//if (isused[i]) continue;
		if (tmp == num[i]) continue;	
		//(이전수열의 막항 == 새로추가할 값)중복된 수열이면 패스!

		arr[k] = i;	//idx 간접 저장
		tmp = num[arr[k]];	//마지막항 저장
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