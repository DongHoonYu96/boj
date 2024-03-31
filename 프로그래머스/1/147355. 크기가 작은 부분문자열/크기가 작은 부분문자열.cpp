#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<=t.size()-p.size();++i){
        string temp=t.substr(i,p.size());
        //cout<<temp<<" ";
        if(stol(temp)<=stol(p)) answer++;
    }
    return answer;
}