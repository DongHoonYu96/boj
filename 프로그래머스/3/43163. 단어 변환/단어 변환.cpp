#include <bits/stdc++.h>

using namespace std;

int visited[54];
int n,answer, is_possible,word_size;

bool check(string s1, string s2){
    int count=0;
    for(int i=0;i<word_size;++i){
        if(s1[i]==s2[i]) count++;
    }
    
    if(count==word_size-1) return true;
    return false;
}

void dfs(string& now, string& target, vector<string> &words, int depth){

    //cout<<now<<"\n";
    if(depth>words.size()) return;
    
    if(now==target){
        answer=min(answer,depth);
        is_possible=1;
        //cout<<depth<<" 끝\n";
        return;
    }
    
    for(int i=0;i<words.size();++i){
        if(visited[i]) continue;
        if(!check(now,words[i])) continue;
        
        visited[i]=1;
        dfs(words[i],target,words,depth+1);
        visited[i]=0;       
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {

    answer=987654321;
    n=words.size();
    word_size=words[0].size();
    dfs(begin,target,words,0);
    
    //cout<<check("log","cog");
    if(!is_possible) return 0;
    return answer;
}