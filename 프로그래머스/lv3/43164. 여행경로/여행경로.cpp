#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<string> answer;
int visited[10004];
vector<vector<string>> ticket;
bool fin;

void dfs(string here, int count){
    //visited[here]=1;
    if(count==ticket.size()){
        fin=true;
    }
    
    for(int i=0;i<ticket.size();++i){
        if(visited[i]) continue;
        string there="";
        there=ticket[i][1];
        if(ticket[i][0] != here) continue;
        
        answer.push_back(there);
        visited[i]=1;
        dfs(there,count+1);
        
        if(!fin){
            answer.pop_back();
            visited[i]=0;
        }
    }
    return;
}

//2차원벡터를 2차원배열로 생각하라.
vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(),tickets.end());    //알파벳순서
    ticket=tickets; //자유롭게사용위해
    answer.push_back("ICN");
    dfs("ICN",0);
    return answer;
}