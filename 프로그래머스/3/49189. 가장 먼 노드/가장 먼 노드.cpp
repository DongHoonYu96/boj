#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int visited[20004];
vector<int> adj[20004];
int max_distance;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto v:edge){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    q.push(1);
    visited[1]=1;
    while(q.size()){
        int now=q.front(); q.pop();
        for(auto next : adj[now]){
            if(visited[next]) continue;
            q.push(next);
            visited[next]+=visited[now]+1;
            max_distance=max(max_distance,visited[next]);
        }
    }
    
    for(int i=1;i<=n;++i){
        if(visited[i]==max_distance) answer++;
    }
    
    
    return answer;
}