#include<bits/stdc++.h>
using namespace std;

int n,m,ret;
deque<int> d;
vector<int> v;

void printD(deque<int> d){
	for (auto i : d) {
		cout << i << " ";
	}
	cout << "\n";

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		d.push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		int target;
		cin >> target;
		//v.push_back(target);

		int cnt1 = 0;
		deque<int> q1 = d;
		while (q1.front() != target) {
			cnt1++;
			//뒤로이동
			int temp = q1.front();
			q1.pop_front();
			q1.push_back(temp);
		}
		int cnt2 = 0;
		deque<int> q2 = d;
		while (q2.front() != target) {
			cnt2++;
			//앞으로이동
			int temp = q2.back();
			q2.pop_back();
			q2.push_front(temp);
		}

		//뒤로이동하는게 최소값인경우
		if (cnt1 <= cnt2) {
			d = q1;
			//cout << "뒤로 : ";
			//printD(d);
			d.pop_front();	//정답은 pop해준다
			ret += cnt1;
		}//앞으로 이동하는게 최소값인 경우
		else {
			d = q2;
			//cout << "앞으로 : ";
			//printD(d);
			d.pop_front();
			ret += cnt2;
		}


	}

	cout << ret;

	
}