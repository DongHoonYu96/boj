#include <bits/stdc++.h>

using namespace std;

int k,ret;
vector<vector<int>> dungeons;
vector<int> v; //인덱스들 순열돌리기

//깊이 , 현재피로도, 탐험한던전수
void dfs(int level, int k,int n){
    if(level==dungeons.size()){
        ret=max(ret,n);
        return;
    }
    
    if(k>=dungeons[v[level]][0]){
        dfs(level+1,k-dungeons[v[level]][1],n+1);
    }
    dfs(level+1,k,n);
}
int solution(int _k, vector<vector<int>> _dungeons) {
    k=_k;
    dungeons=_dungeons;
    

    for(int i=0;i<dungeons.size();++i){
        v.push_back(i);
    }
    
    do{
        //for(auto i : v) cout<<i<<" ";
        //cout<<"\n";
        dfs(0,k,0);
    }while(next_permutation(v.begin(),v.end()));
    
    
    return ret;
}