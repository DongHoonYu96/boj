#include <bits/stdc++.h>

using namespace std;

int parent[104];

//부모노드찾기
int get_parent(int node){
    if(parent[node]==node) return node;
    return parent[node]=get_parent(parent[node]);
}

//같은그룹인지 검사
int find(int node1, int node2){
    if(get_parent(node1)==get_parent(node2)){
        return 1;
    }    
    return 0;
}

//같은집합으로 만드는함수
void union_parent(int node1, int node2){
    int p1=get_parent(node1);
    int p2=get_parent(node2);
    
    //노드숫자가 작은쪽으로 병합
    //주의: node1(자신)이 아니라 p1(자신의부모)의 부모를갱신해야함.
    if(p1>p2){
        parent[p1]=p2;
    }
    else{
        parent[p2]=p1;
    }
}

bool cmp(vector<int> v1, vector<int> v2){
    return v1[2]<v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(),costs.end(),cmp);    
    
    //초기값 : 자기자신을 부모로 두기
    for(int i=0;i<n;++i){
        parent[i]=i;
    }
    
    int edge_count=0;
    for(auto v:costs){
        //if(edge_count>=n-1) break;
        if(find(v[0],v[1])) continue;   //같은그룹이면 == 연결시 사이클을 만들면 pass
        union_parent(v[0],v[1]);
        answer+=v[2];
        
        
    }
    
    return answer;
}