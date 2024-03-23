#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>> pq1; //최대힙
priority_queue<int, vector<int>,greater<int>> pq2; //최소힙
int n,tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (i == 0) {
			pq1.push(tmp);
			cout << tmp << "\n";
			continue;
		}

		if (pq1.top() <= tmp) {
			pq2.push(tmp);
		}
		else {
			pq1.push(tmp);
		}

		//재조정
		if (pq1.size() < pq2.size()) {
			int temp = pq2.top(); pq2.pop();
			pq1.push(temp);
		}
		if (pq1.size() > pq2.size()+1) {
			int temp = pq1.top(); pq1.pop();
			pq2.push(temp);
		}

		cout << pq1.top() << "\n";

	}


	
	return 0;
}