#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,t,ret,a[10][10],v[10][10];
vector<pair<int, int>> vir,w;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
void dfs(int y, int x)
{
    v[y][x] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m||v[ny][nx]) continue;
        if(a[ny][nx]==0) dfs(ny, nx);
    }
    return;
}
/*
* 1.virus퍼뜨리기(0 and 방문안됨->안전영역임)
* 2.0개수세기
*/
int sol()
{
    fill(&v[0][0], &v[0][0] + 10 * 10, 0);
    for (int i = 0; i < vir.size(); ++i) 
        dfs(vir[i].first, vir[i].second);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 0 && !v[i][j]) cnt++;
        }
    }
    return cnt;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 0) w.push_back({ i, j });
            if (a[i][j] == 2) vir.push_back({ i, j });
        }
    }

    /*
    * 3중반복문 => nC3구현
    */
    for(int i=0;i<w.size();++i)
        for(int j=0;j<i;++j)
            for (int k = 0; k < j; ++k)
            {
                a[w[i].first][w[i].second]=1;
                a[w[j].first][w[j].second] = 1;
                a[w[k].first][w[k].second] = 1;
                ret = max(ret, sol());
                a[w[i].first][w[i].second] = 0;
                a[w[j].first][w[j].second] = 0;
                a[w[k].first][w[k].second] = 0;
            }
    cout << ret;
    return 0;
}