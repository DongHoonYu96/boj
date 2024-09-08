#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k,n,a[10000+4];

//길이가 x일때, 랜선이n개이상일수 있는지
int go(ll x) {
    ll cur = 0; //x개로 랜선자른 갯수
    for (int i = 0; i < k; ++i) cur += a[i] / x;
    return cur >= n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k>> n;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }


    ll st = 1, en = (1<<31)-1;
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (go(mid)) st = mid; //랜선을자를수있으면 -> 더큰길이로잘라도되는지 우측탐색
        else en = mid - 1; //랜선을 못자르면 -> 랜선길이를줄여야함 -> 좌측탐색
    }
    cout << st;

    return 0;
}