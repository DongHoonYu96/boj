#include <bits/stdc++.h>
using namespace std;

int t, n;
int d[44][2];
// d[i][0] : fibo(i)에서 0이 출력되는 횟수
// d[i][1] : fibo(i)에서 1이 출력되는 횟수

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    }
    else if (n == 1) {
        printf("1");
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    d[2][0] = d[1][0] + d[0][0];
    d[2][1] = d[1][1] + d[0][1];

    for (int i = 2; i <= 40; ++i) {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];

    }

    while (t--) {
        cin >> n;
        cout << d[n][0] << " " << d[n][1] << "\n";
    }
}