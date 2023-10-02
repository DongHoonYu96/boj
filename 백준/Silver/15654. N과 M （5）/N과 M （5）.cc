#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int isused[10];
vector<int> v;

//현재까지 k개의 수를 선택함.
void go(int k) {
	if (k==m){
		for (int i = 0; i < m; ++i) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	//int st = 1;
	//if (k != 0) st = arr[k - 1];

	for (int i = 0; i < n; ++i) {
		if (isused[i]) continue;
		arr[k] = v[i];
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
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());

	go(0);
}