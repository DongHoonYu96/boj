#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> q1; //최대힙
priority_queue<int, vector<int>,greater<int>> q2; //최소힙

vector<string> split(string& s, string deli){
    long long pos = 0;
	string token = "";
	vector<string> ret;
    
    while((pos=s.find(deli))!=string::npos){
        token=s.substr(0,pos);
        ret.push_back(token);
        s.erase(0,pos+deli.size());
    }
    ret.push_back(s); //s를넣어야함! token아님!
    return ret;
}
bool cmp(string s1, string s2){
    return stoi(s1) < stoi(s2);
}
string solution(string s) {
    string answer = "";
    vector<string> v = split(s," ");
    
    sort(v.begin(),v.end(),cmp);
    
    answer+=v[0];
    answer+=" ";
    answer+=v[v.size()-1];
    
    // for(auto ss : v) {
    //     int cur = (stoi)ss;
    //     q1.push(cur);
    //     q2.push(cur);
    // }
    // answer+=q2.top();
    // answer+=" ";
    // answer+=q1.top();
    //cout<<q2.top()<<" "<<q1.top();
    return answer;
}