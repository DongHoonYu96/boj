#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, L;
ll arr[5000000 + 4];
deque<pair<ll,ll>> d; // <idx, val>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    d.push_back({ 0,arr[0] });
    cout << arr[0] << " ";

    
    for (int i = 1; i < n; ++i) {
        // 우측에서 삽입, 넣을때 자신보다 큰값은 삭제 => 정렬효과
        // 하나씩빼기 => 완탐효과
        while (d.size() && d.back().second > arr[i]) {
            d.pop_back();
        }
        d.push_back({ i,arr[i] });
        
        // 좌측에서 제거할지 판단. 현재 idx - L <= 좌측idx -> 삭제
        if (d.front().first <= i - L) {
            d.pop_front();
        }

        // 좌측의 val 출력
        cout << d.front().second << " ";
    }
    return 0;
}