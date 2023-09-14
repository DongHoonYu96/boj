#include <bits/stdc++.h>

using namespace std;

int answer;
int v[204];
int N;

//해당 노드(컴퓨터)dfs
void dfs(int& n, vector<vector<int>>& computers){
    v[n]=1;
    
    
    for(int i=0;i<N;++i){
        if(v[i]) continue;
        if(computers[n][i]==1){
            dfs(i,computers);
        }
    }
    return;
    
}

int solution(int n, vector<vector<int>> computers) { 
    N=n;
    for(int i=0;i<n;++i){
        if(v[i]){
            continue;
        }
        dfs(i,computers);
        answer++;
    }
    
    
    return answer;
}