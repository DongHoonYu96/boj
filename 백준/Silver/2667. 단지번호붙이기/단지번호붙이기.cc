#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, c,  a[25][25], v[25][25];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
vector<int> ret;

int dfs(int y, int x)
{
    v[y][x] = 1;
    int ret = 1;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;

        if (a[ny][nx] == 1 && v[ny][nx] == 0)
            ret = ret + dfs(ny, nx);
    }
    return ret;

}

int main() {
    /*ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;*/
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(a[i][j]==1 && v[i][j]==0)
                ret.push_back(dfs(i, j));
        }
    }

    
    printf("%d\n", ret.size());
    sort(ret.begin(), ret.end());
    for (int a : ret) printf("%d\n",a);

   /* cout << ret.size()<<endl;
    sort(ret.begin(), ret.end());
    for (int a : ret) cout << a << endl;*/
    return 0;
}