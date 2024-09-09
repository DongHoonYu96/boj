
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, sum;
ll arr[10004];
ll ret; //배정된 예산중 최대값

//배정예산 상한액이 x일때, 되는지
ll go(ll x) {
    if (x > m) return 0; //상한액이 총예산을 넘어가는 경우

    //모든 요청이 배정될수 있는경우
    if (sum <= m) {
        return 1;
    }
    ////배정될수없는경우
    ll tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > x) tmp += x;
        else tmp += arr[i];
    }
    return tmp <= m;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> m;

    sort(arr, arr + n);
    ll st = 1;
    ll en = *max_element(arr, arr+n);

    while (st < en) {
        ll mid = (st + en+1) / 2;
        //cout << st << " "<< mid<<" " << en << "\n";

        if (go(mid)) {
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }

    cout << st;

    return 0;
}