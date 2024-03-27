#include <bits/stdc++.h>

using namespace std;

string arr[50004];
vector<string> answer;
map<string, int> m1; //이름,현재인덱스 저장
map<int,string> m2; //현재인덱스, 이름 저장
vector<pair<string,int>> v1; //이름,인덱스저장

vector<string> solution(vector<string> players, vector<string> callings) {
    
    for(int i=0;i<players.size();++i){
        v1.push_back({players[i],i});
        m1[players[i]]=i;
        m2[i]=players[i];
    }
    
    for(auto calling : callings){
        int idx = m1[calling];
        string prev_name = m2[idx-1];
        string cur_name=calling;
        
        m1[cur_name]=m1[cur_name]-1;
        m1[prev_name]=m1[prev_name]+1;
        
        m2[idx]=prev_name;
        m2[idx-1]=cur_name;
    }
    //sort(m2.begin(),m2.end());
    for(auto item : m2){
        //cout<<item.second<<" ";
        answer.push_back(item.second);
    }
    
    return answer;
    
    vector<int> v;
    for(int i=0;i<players.size();++i){
        v.push_back(i);
    }
    for(int i=0;i<players.size();++i){
        m1[players[i]]=i;
    }
    
    for(auto calling : callings){
        int idx=m1[calling];
        //cout<<idx<<"\n";
        
        //스왑
        int temp1=v[idx-1];
        int temp2=v[idx];
        v[idx-1]=temp2;
        v[idx]=temp1;
        
        //맵 갱신
        m1[calling]=temp1;
        m1[m2[idx-1]]=temp2;
        // m2[idx]=calling;
        // m2[idx-1]=m2[idx-1];
        
    }
    for(auto i : v) cout<<i<<" ";
    
    
    
    return answer;
}