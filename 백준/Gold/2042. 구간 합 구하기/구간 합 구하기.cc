#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k, t1, t2, t3; 
ll t4;
vector<long long> tree;

//a[1]의 값을 val로 수정 -> 
//ex) 기존값이 6이고, 9로 바꿈 -> 차이인 "3" 만큼만 갱신해야함!
//영향을받는 1, 10, 100 ... 도 (퍼랭이들) 수정해야함
void update(int idx, ll diff) {
    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

//1번~idx 까지 구간합 리턴
//sum(7==0111)
//tree[0111], tree[0110], tree[0100] 의 합을 구하면됨. 
ll sum(int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m>>k;
    vector<long long> a(n + 1);
    tree.resize(n + 1); // 1-idx임에 주의!

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    m += k;
    while (m--) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2 >> t4;
            long long diff = t4 - a[t2];
            a[t2] = t4;
            update( t2, diff);
        }
        else {
            int t2, t3;
            cin >> t2 >> t3;
            printf("%lld\n", sum( t3) - sum( t2 - 1));
        }
    }
    return 0;

}