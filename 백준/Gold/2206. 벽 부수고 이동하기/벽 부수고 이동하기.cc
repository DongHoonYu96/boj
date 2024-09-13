
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//상태정의 : (y, x, 벽부쉇는지)
struct A {
    
    int y;
    int x;
    int crashed; // 현재 상태일때 벽부쉇는지

    A(int y, int x, int crashed) : y(y), x(x), crashed(crashed) {};
};

int n, m, arr[1004][1004], vis[1004][1004][2];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
ll ret; //배정된 예산중 최대값
queue<A> q;



int main()
{
    cin >> n>>m;

    for (int i = 0; i < n; ++i) {
        string tmp = "";
        cin >> tmp;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = tmp[j]-'0';
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j];
        }cout << "\n";
    }*/

    int ok = 0; //갈수있는지
    vis[0][0][0] = 1;
    q.push(A(0,0,0));
    while (q.size()) {
        int y = q.front().y;
        int x = q.front().x;
        int crashed = q.front().crashed;
        //cout << y << " " << x << " " << crashed << "\n";
        q.pop();
        //탈출은 pop 다음에
        if (y == n - 1 && x == m-1) {
            ok = 1;
            ret= vis[y][x][crashed];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (vis[ny][nx][crashed]) continue;
            
            //next가 벽이 아닌경우, 그냥 bfs와 동일논리
            if (arr[ny][nx] == 0) {
                vis[ny][nx][crashed] = vis[y][x][crashed] + 1;
                q.push(A(ny, nx, crashed));
            }
            else { //next가 벽인경우
                if (crashed == 1) continue; //이미 부셧다면 불가.

                //안부신경우(crashed==0), 다음상태는 부순걸로표시
                vis[ny][nx][crashed+1] = vis[y][x][crashed] + 1;
                q.push(A(ny, nx, crashed+1));
            }
        }
    }

    if (ok) {
        cout << ret;
    }
    else
        cout << -1;
    //cout << "\n";
    //for (int i = 0; i < n; ++i) {
    //    for (int j = 0; j < m; ++j) {
    //        cout << vis[i][j]<< " ";
    //    }cout << "\n";
    //}

    //if (vis[n - 1][m - 1] == 0) {
    //    cout << -1;
    //    return 0;
    //}
    //cout << vis[n - 1][m - 1];

    return 0;
}