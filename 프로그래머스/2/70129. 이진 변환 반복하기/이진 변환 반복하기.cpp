#include <bits/stdc++.h>

using namespace std;
vector<int> answer;

//n을 2진법으로 바꾸기
string go(int n){
    string ret="";
    while(n>1){
        ret=to_string(n%2)+ret;
        n/=2;
    }
    ret=to_string(n)+ret;
    return ret;
}
vector<int> solution(string s) {
    
    // cout<<go(4);
    // return {1};
    
    int zero=0;//제거된 0의갯수
    int cnt=0; //변환횟수
    while(s!="1"){
        cnt++;
        //1.모든 0을제거
        string temp="";
        for(auto c : s){
            if(c=='0') {
                zero++;
                continue;
            }
            temp+=c;
        }
        //2. temp의 길이를 2진법으로 바꾸기
        s=go(temp.size());
        
    }
    return {cnt,zero};
}