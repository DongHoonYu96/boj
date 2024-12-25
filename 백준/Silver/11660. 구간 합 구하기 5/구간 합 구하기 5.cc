#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1025][1025], sum[1025][1025]; 
// sum[x][y] = (0,0)부터 (x,y)까지 사각형 안에 있는 수의 합
int sumAll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

   /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }*/

    int x1, x2, y1, y2;
    for (int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2; // x2가 큰것은 보장됨.
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        cout << "\n";
    }

    
    return 0;
}