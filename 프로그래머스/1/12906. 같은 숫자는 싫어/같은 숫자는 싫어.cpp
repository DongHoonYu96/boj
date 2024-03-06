#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<arr.size();++i){
        int cur=s.top();
        
        if(cur!=arr[i]) s.push(arr[i]);
    }
    
    while(s.size()){
        answer.push_back(s.top()); s.pop();
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}