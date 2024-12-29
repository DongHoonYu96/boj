#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;
stack<pair<ll,ll>> s;
ll ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    arr.push_back(0); // 스택에 남은애들 계산을 위해

    for (int i = 0; i < arr.size(); i++) {
        // 스택 top의 높이가 현재 높이보다 크면
        // 스택이 비거나 top의 높이가 현재보다 작아질 때까지 계산
        while (!s.empty() && arr[s.top().first] > arr[i]) {
            ll height = arr[s.top().first];
            s.pop();
            
            // 너비 계산: 스택이 비어있으면 현재 인덱스까지의 전체 너비
            // 비어있지 않으면 현재 인덱스와 스택 top 사이의 거리
            ll width;
            if (s.empty()) {
                width = i;
            } else {
                width = i - s.top().first - 1;
            }
            
            ret = max(ret, height * width);
        }
        s.push({i,arr[i]});  // 현재 인덱스를 스택에 추가
    }
    
    cout<<ret;
    
    return 0;
}