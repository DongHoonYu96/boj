#include <bits/stdc++.h>

using namespace std;

int visited[104];
int adj[104][104];

int dfs(int node){
    visited[node]=1;
    
    int ret=1;
    
    for(int next=0;next<104;++next){
        if(adj[node][next]==0) continue;   //연결이아니면 pass 
        if(adj[next][node]==0) continue;   //연결이아니면 pass
        if(visited[next]) continue;
        ret+=dfs(next);
    }
    
    return ret;
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    
    //1. 1개씩 연결끊기
    //2. dfs 돌면서 연결된 노드세기
    //3. 최대값 차이 갱신
    // n*n==10000 가능
    
    for(auto v : wires){
        adj[v[0]][v[1]]=1;
        adj[v[1]][v[0]]=1;
    }
    
    
    for(auto v : wires){
        //visit 초기화
        fill(visited,visited+104,0);
        
        
        adj[v[0]][v[1]]=0;
        adj[v[1]][v[0]]=0;
        
        vector<int> temp;
        for(int i=1;i<=n;++i){
            if(visited[i]) continue;
            temp.push_back(dfs(i));
            
        }
        // for(auto i : temp){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        answer=min(answer,abs(temp[0]-temp[1]));
        
        //탐색끝나면 다시연결해주기
        adj[v[0]][v[1]]=1;
        adj[v[1]][v[0]]=1;
    }
    
    return answer;
}