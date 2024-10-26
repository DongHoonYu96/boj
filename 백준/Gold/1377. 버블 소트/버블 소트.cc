#include <bits/stdc++.h>

using namespace std;

int n, len;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, int>> withIdx;  // {값, 원래 인덱스}

    // 원래 위치 기록
    for (int i = 0; i < n; i++) {
        withIdx.push_back({ arr[i], i });
    }

    // 정렬
    sort(withIdx.begin(), withIdx.end());

    // 각 원소가 왼쪽으로 얼마나 이동했는지 확인
    int maxMove = 0;
    for (int i = 0; i < n; i++) {
        maxMove = max(maxMove, withIdx[i].second - i);
    }

    cout<< maxMove + 1;
    return 0;
}