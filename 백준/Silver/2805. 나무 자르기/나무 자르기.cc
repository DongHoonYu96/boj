#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m, a[1000000 + 4];

//길이가 x일때, 가질나무가m개 이상인지
int go(ll x) {
    ll cur = 0; //x개로 랜선자른 갯수
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] - x;
        if (tmp < 0) continue;
        cur += tmp;
    }
    return cur>=m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //sort(a, a + 1000000 + 4);
    ll st = 0, en = 2000000000;
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (go(mid)) st = mid; //랜선을자를수있으면 -> 더큰길이로잘라도되는지 우측탐색
        else en = mid - 1; //랜선을 못자르면 -> 랜선길이를줄여야함 -> 좌측탐색
    }
    cout << st;

    return 0;
}