#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll ret; // int → long long
vector<pair<int, int>> v;
vector<int> bag;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        bag.push_back(a);
    }

    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    for (int i = 0; i < k; ++i) {
        // 현재 가방에 담을 수 있는 모든 보석 추가
        while (j < n && bag[i] >= v[j].first) {
            pq.push(v[j].second);
            ++j;
        }
        // pq가 비어있지 않을 때만 처리
        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
        // if(j >= n) break; → 삭제!
    }
    cout << ret;
    return 0;
}