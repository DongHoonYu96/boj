#include <bits/stdc++.h>
using namespace std;


char a[54][54];
int vis[54][54],vis2[54][54],ret,fin;
int dx[]={1,0,0,-1}; //d l r u
int dy[]={0,-1,1,0};
char dc[]={'d','l','r','u'};
string answer="impossible";
vector<string> v;

int get_dist(int x, int y, int a , int b){
    return abs(x-a)+abs(y-b);
}
void dfs(int depth, int n, int m, int x, int y, int r, int c, int k, string s){
    //cout<<x<<" "<<y<<"\n";
    // if(depth==ret){
    //     v.push_back(s);
    //     return;
    // }
    if(fin) return;
    int dist=get_dist(x,y,r,c);
    if(k-depth-dist<0) return; //제한-현재깊이-남은거리(남은움직임횟수)가 음수 -> 도달불가능
    if((k-depth-dist)%2==1) return; //남은 움직임횟수가 홀수 ->  돌아오기 불가
    if(depth==k){
        if(x==r && y==c) {
        answer=s;
        fin=1;
        }
        return;
    }
    
    //vis[x][y]=1;
    
    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(ny<1 || ny>m || nx<1 || nx>n) continue;
        if(vis[nx][ny]) continue;
        
        dfs(depth+1, n,m,nx,ny,r,c,k,s+dc[i]);
        //vis[ny][nx]=0;
    }
    return;
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    //bfs 후 최단거리 홀->k도 홀수여야 도달가능 (짝이면 k도짝수여야)

//     queue<pair<int,int>> q;
//     q.push({x,y});
//     while(q.size()){
//         auto cur = q.front(); q.pop();
//         for(int i=0;i<4;++i){
//             int nx=cur.first+dx[i];
//             int ny=cur.second+dy[i];
//             if(ny<1 || ny>m || nx<1 || nx>n) continue;
//             if(vis[nx][ny]) continue;
            
//             if(i==0) a[nx][ny]='d';
//             if(i==1) a[nx][ny]='l';
//             if(i==2) a[nx][ny]='r';
//             if(i==3) a[nx][ny]='u';
//             q.push({nx,ny});
//             vis[nx][ny]+=vis[x][y]+1;
//         }
//     }
//     ret=vis[r][c]+1;
//     //cout<<ret;
//     if(ret%2==0 && k%2!=0) return "impossible";
//     if(ret%2!=0 && k%2==0) return "impossible";
    
//     fill(&vis[0][0],&vis[0][0]+54*54,0);
//     vis[x][y]=1;
    dfs(0,n,m,x,y,r,c,k,"");
    for(auto s : v) cout<<s<<" ";
    
    return answer;
    
    vector<string> result;
    for(auto s : v) {
        //if(s.size()==ret){
            cout<<s<<"\n";
            //아래가빔 -> 1순위
            if(r+1<=n){
                string temp=s;
                while(ret!=k){
                    temp+="du";
                    ret+=2;
                }
                result.push_back(temp);
            //}
           
            //좌측이빔 -> 2순위
            if(c-1>=1){
                string temp=s;
                while(ret!=k){
                    temp+="lr";
                    ret+=2;
                }
                result.push_back(temp);
            }
            //우측이빔 -> 3순위
            if(c+1<=m){
                string temp=s;
                while(ret!=k){
                    temp+="rl";
                    ret+=2;
                }
                result.push_back(temp);
            }
             //위가빔 -> 꼴등
            if(r-1>=n){
                string temp=s;
                while(ret!=k){
                    temp+="ud";
                    ret+=2;
                }
                result.push_back(temp);
            }
        }
            
    }
    //사전순 : dlru
    
    sort(result.begin(),result.end());
    return result[0];
}