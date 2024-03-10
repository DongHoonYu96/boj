#include <bits/stdc++.h>

using namespace std;

int n,m,cy,cx;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int a[304][304], b[304][304]; //원본배열,계산배열
int vis[304][304]; 

void dfs(int y, int x) {
    vis[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (vis[ny][nx]) continue; //미방문
        if (a[ny][nx] == 0) continue; // 빈칸은 제외
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    //0. !전체 가능한 년도에 대해!
    //1. 빙하에 대해, 주변이 빈칸이면 b배열만들기

    for (int year = 1; year < 300*300; ++year) {
        //배열초기화 항상 까먹지말것!
        fill(&vis[0][0], &vis[0][0] + 304 * 304, 0);
        fill(&b[0][0], &b[0][0] + 304 * 304, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) continue; //빙하아니면 탐색안함
                int tmp = 0;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (a[ny][nx] == 0) tmp++;
                }
                b[i][j] -= tmp;
            }
        }

        //2. 원본배열에 뺄셈하기
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] <= 0) continue; // 빙하에대해서만 수행
                a[i][j] += b[i][j];
                if (a[i][j] < 0) a[i][j] = 0;
            }
        }

        
        //3. 빙산 덩어리 갯수 카운팅
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] <= 0) continue;
                if (vis[i][j]) continue;
                dfs(i, j);
                ret++;
                if (ret >= 2) { //2덩어리 이상이면 끝
                    cout << year;
                    return 0;
                }
            }
        }
        if (ret == 0) { //빙산이 분리불가능한경우 0출력(전부 0이면 bfs안돌겠지)
            cout << 0;
            return 0;

        }
    }
    cout << 0;


    return 0;
}