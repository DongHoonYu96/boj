#include <bits/stdc++.h>

using namespace std;

int a[1000004];
vector<int> v;//누적합

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    v.push_back(sequence[0]);
    for(int i=1;i<sequence.size();++i){
        v.push_back(sequence[i]+v[i-1]);
    }
    
    for(int i=0;i<sequence.size();++i){
        //cout<<v[i]<<" ";
    }
    
    int mindist=987654321;
    
    //바로찾은경우
    int idx=lower_bound(v.begin(),v.end(),k)-v.begin();
        if(binary_search(v.begin(),v.end(),k)) {
            int dis=idx;
        if(mindist>dis){
            mindist=dis;
            answer={0,idx};
        }
        else if(mindist==dis){
            if(answer[0]>0)
            answer={0,idx};
        }
            //continue;
        }
    
    for(int i=0;i<sequence.size();++i){
        int idx=lower_bound(v.begin()+i+1,v.end(),k+v[i])-v.begin();
        
        if(binary_search(v.begin()+i+1,v.end(),k+v[i])==0) continue; //없으면 패스
        int dis=idx-i-1;
        if(mindist>dis){
            mindist=dis;
            answer={i+1,idx};
        }
        else if(mindist==dis){
            if(answer[0]>i+1)
            answer={i+1,idx};
        }
    }
    
    return answer;
}