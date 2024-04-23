#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll n;
ll m;
vector<ll> v,lef;
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n>>m;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int s = 0, e = n - 1;

	while (s <= e) {
		//이미 x가 된경우 -> 너 가능성없어(더 탐색할필요 없음) -> 제거
		if (v[e] >= m) {
			cnt++;
			e--;
			continue;
		}

		//딱 하나만 남았고, x보다 작으면 쓰레기임
		if (s == e){
			lef.push_back(v[s]);
			break;
		}

		//13통을 만들수있음 -> 만든다
		//이게 최적인 이유 : 가장비싼통입장에서 고를때, 최소값을 고르는게 최적이다.
		// ex) 8의 입장에서는 아무거나골라도 13/2가 넘으므로 최소값(0)을 고르는게 최적임.
		if (v[s] + v[e] >= (m+1)/2) {
			s++;
			e--;
			cnt++;
			continue;
		}
		//두개더해도 13통을 만들수 없는경우
		//세통을 더하면 개손해임
		//작은값을 lef (쓰레기들)배열에 넣고, s를 큰값을 넣으면 되는지 탐색한다.
		if (v[s] + v[e] < (m + 1) / 2) {
			lef.push_back(v[s]);
			s++;
			continue;
		}
	}

	//쓰레기 3개를 모으면 13확정임!
	//두통을합치면 x/2가 보장되기때문에(문제조건)
	cout << cnt + lef.size() / 3;


	

	return 0;
}