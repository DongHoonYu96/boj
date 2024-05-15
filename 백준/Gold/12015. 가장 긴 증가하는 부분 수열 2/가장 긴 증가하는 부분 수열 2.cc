#include <bits/stdc++.h>
using namespace std;

int n, lis[1000000+1], len, num;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //1. num 이상인 idx를 찾음 -> 더 작은값이 들어오면, 작은값으로 교체함!
        //lis(현재의 증가수열길이) 중에서
        int idx = lower_bound(lis, lis + len, num) - lis;
        if (lis[idx] == 0) len++; //처음보는값인경우, lis길이+1
        lis[idx] = num; 
        /*for (int j = 0; j < n; j++) {
            printf("%d ", lis[j]);
        }
        printf("\n");*/
    }
    printf("%d", len);

    return 0;
}


