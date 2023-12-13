#include <bits/stdc++.h>

using namespace std;
//왼쪽자식, 오른쪽자식, 양/늑대 값
int l[20],r[20],val[20]; 
int n; //info 크기
int ans=1;
int vis[1<<17]; // vis[x]:상태 x를 방문했는가?

//상태에 대해 dfs
void solve(int state){
    if(vis[state]) return;
    vis[state]=1;
    
    int wolf=0, num=0; //늑대의수, 전체정점의 수 조사
    for(int i=0;i<n;++i){ //현재상태에 켜져있는 노드에 대해
        if(state & (1<<i)){
            num++;
            wolf+=val[i];
        }
    }
    if(wolf*2>=num) return; //늑대가 절반이상이면 종료
    ans=max(ans,num-wolf); //현재 state의 양의수 갱신
    
    //다음상태로 넘어가기
    for(int i=0;i<n;++i){
        //i번째 비트가 꺼져있는경우 넘어감
        if(!(state & (1<<i))) continue;
        if(l[i]!=-1) 
            solve(state | (1<<l[i])); //자식이있으면 그 자식을 포함한 상태로 탐색
        if(r[i]!=-1)
            solve(state | (1<<r[i]));
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    n=info.size();
    fill(l,l+n,-1);
    fill(r,r+n,-1);
    for(int i=0;i<n;++i) val[i]=info[i];
    for(int i=0;i<n-1;++i){
        int a=edges[i][0]; //부모
        int b=edges[i][1]; //자식
        if(l[a]==-1) l[a]=b; //부모의 왼쪽자식이 없으면, 왼쪽부터 채움
        else r[a]=b;
    }
    solve(1); // 1번 상태로 시작 (0000000001) : 루트노드만 추가된상태
    return ans;
}