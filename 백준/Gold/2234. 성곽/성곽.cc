#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ret1,ret2, ret3; //방의갯수, 가장 넓은방의 넓이
int arr[54][54], vis[54][54];
int dy[]={1,0,-1,0}; //남, 동, 북, 서
int dx[]={0,1,0,-1};
int bit[]={8,4,2,1}; // 각 방향에 해당하는 비트값 추가

int dfs(int y, int x) {
    vis[y][x]=1;
    int cnt=1;

    for(int i=0;i<4;++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
        if(vis[ny][nx]) continue;
        if(i==0 && !(arr[y][x]&8)) {
            cnt+=dfs(ny,nx);
        }
        if(i==1 && !(arr[y][x]&4)) {
            cnt+=dfs(ny,nx);
        }
        if(i==2 && !(arr[y][x]&2)) {
            cnt+=dfs(ny,nx);
        }
        if(i==3 && !(arr[y][x]&1)) {
            cnt+=dfs(ny,nx);
        }
    }
    ret2=max(ret2,cnt);
    return cnt;
}

int dfs3(int y, int x) {
    vis[y][x]=1;
    int cnt=1;

    for(int i=0;i<4;++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
        if(vis[ny][nx]) continue;
        if(i==0 && !(arr[y][x]&8)) {
            cnt+=dfs3(ny,nx);
        }
        if(i==1 && !(arr[y][x]&4)) {
            cnt+=dfs3(ny,nx);
        }
        if(i==2 && !(arr[y][x]&2)) {
            cnt+=dfs3(ny,nx);
        }
        if(i==3 && !(arr[y][x]&1)) {
            cnt+=dfs3(ny,nx);
        }
    }
    ret3=max(ret3,cnt);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            if(vis[i][j]) continue;
            dfs(i,j);
            ret1++;
        }
    }

    //n^2 C 1 * 4(동서남북) 벽제거
    // memset(vis,0,sizeof(vis));
    // for(int i=0;i<m;++i) {
    //     for(int j=0;j<n;++j) {
    //         // if(vis[i][j]) continue;
    //         for(int k=0;k<4;++k) {
    //             int mask = ~(1<<k); //k번째 비트 끄기
    //             int origin = arr[i][j];
    //             arr[i][j]&= mask;
    //             dfs3(i,j);
    //             arr[i][j]=origin;
    //         }
    //     }
    // }
    // 벽을 하나씩 제거해보면서 최대 크기 계산
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            for(int k=0;k<4;++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
                
                // 현재 위치에 k방향의 벽이 있는 경우에만 시도
                if(arr[i][j] & bit[k]) {
                    // 양쪽 벽 모두 제거
                    int origin = arr[i][j];
                    int origin_neighbor = arr[ny][nx];
                    arr[i][j] &= ~bit[k];
                    arr[ny][nx] &= ~bit[(k+2)%4];
                    
                    // 전체 맵에서 가장 큰 방 찾기
                    memset(vis,0,sizeof(vis));
                    for(int y=0;y<m;++y) {
                        for(int x=0;x<n;++x) {
                            if(!vis[y][x]) {
                                ret3 = max(ret3, dfs3(y,x));
                            }
                        }
                    }
                    
                    // 원상복구
                    arr[i][j] = origin;
                    arr[ny][nx] = origin_neighbor;
                }
            }
        }
    }
    cout<<ret1<<"\n"<<ret2<<"\n"<<ret3;
    
    return 0;
}