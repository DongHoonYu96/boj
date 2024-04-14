#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string deli){
    vector<string> ret;
    long long pos=0;
    
    while((pos=s.find(deli))!=string::npos){
        string token=s.substr(0,pos);
        ret.push_back(token);
        s.erase(0,pos+deli.size());
    }
    ret.push_back(s);
    return ret;
    
}

string solution(string s) {
    string answer = "";
    
    vector<string> v = split(s," ");
    for(auto s : v){
        string tmp="";
        for(int i=0;i<s.size();++i){
            if(i==0) tmp+=toupper(s[i]);
            else tmp+=tolower(s[i]);
        }
        answer+=tmp;
        answer+=" ";
    }
    
    answer=answer.substr(0,answer.size()-1);
    
    
    return answer;
}