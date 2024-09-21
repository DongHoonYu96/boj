
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF = 0x3f3f3f3f;
int d[105][105]; //i에서 j로 가는 거리
int n, m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    fill(&d[0][0], &d[0][0] + 105 * 105, INF); //무한대로 초기화

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int i = 1; i <= n; ++i) d[i][i] = 0; //자기자신으로 가는비용은 0

    for (int k = 1; k <= n; ++k) { //정점 k를 하나씩 추가하면서
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                //d[2][3] = d[2][3] , d[2][1]+d[1][2] 
                //(정점 k를 거쳐가는게 더싼지 계산) 
                //연산이 대입보다 빠르기때문에, 이렇게 연산조건문으로 바꾸면
                // N이 1000일때도 비빌수있음!
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
                //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] == INF) cout << 0 << " ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    


    return 0;
}