#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>> pq1;
priority_queue<int,vector<int>,greater<int>> pq2;
int deleted[1000000];

vector<string> split(string s, string deli){
    vector<string> ret;
    long long pos=0;
    while((pos = s.find(deli))!=string::npos){
        string token = s.substr(0,pos);
        ret.push_back(token);
        s.erase(0,pos+deli.size());
    }
    ret.push_back(s);
    return ret;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> deleted;
    // vector<string> v = split("D -1"," ");
    // for(auto s : v) cout<<s<<" ";
    
    int cnt=0; // 현재 큐에들어있는 원소갯수
    for(auto operation : operations){
        vector<string> v = split(operation," ");
        if(v[0]=="I"){
            pq1.push(stoi(v[1]));
            pq2.push(stoi(v[1]));
            cnt++;
            continue;
        }
        else if(v[0]=="D"){
            if(cnt==0) continue;
            if(v[1]=="1"){
                if(pq1.empty()) continue;
                pq1.pop();
                cnt--;
            }
            if(v[1]=="-1"){
                if(pq2.empty()) continue;
                pq2.pop();
                cnt--;
            }
            if(cnt==0){
                while(pq1.size()) pq1.pop();
                while(pq2.size()) pq2.pop();
            } 
        }
    }

    if(cnt==0) return {0,0};
    return {pq1.top(),pq2.top()};
    return answer;
}