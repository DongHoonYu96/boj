#include <bits/stdc++.h>

using namespace std;

int n, m;
long long arr[1000000 + 4], sum[1000000 + 4];
// sum[x][y] = (0,0)부터 (x,y)까지 사각형 안에 있는 수의 합
long long ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    // sum을 %m한 결과 구하기
    sum[0] = arr[0] % m ;
    for (int i = 1; i < n; ++i) {
        sum[i] = (sum[i-1]%m + arr[i]%m )%m;
    }

    // 값이 0의갯수는 정답에 더하기
    for (int i = 0; i < n; ++i) {
        if (sum[i] == 0) ret++;
    }

    vector<long long> v(m,0); //v[i] : i숫자의 갯수
    // 같은값 갯수세기
    for (int i = 0; i < n; ++i) {
        v[sum[i]]++;
    }

    // C2하기
    for (auto num : v) {
        if (num == 0) continue;
        ret = ret + num* (num - 1) / 2;
    }
    
    cout << ret;

    
    return 0;
}