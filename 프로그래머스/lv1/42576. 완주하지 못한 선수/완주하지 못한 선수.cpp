#include <bits/stdc++.h>

using namespace std;

map<string, int> m1,m2;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto s : completion){
        m1[s]++;
    }
    for(auto s : participant){
        m2[s]++;
    }
     for(auto s : participant){
        if(m1[s]!=m2[s]){
            return s;
        }
    }
   
    
    return answer;
}