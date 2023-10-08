#include <bits/stdc++.h>

using namespace std;

int ret;
map<string, int> m1;
map<int, int> m2;

//현재 k번째 옷을 입을것임.
void go(int k, int cnt){
    //cout<<"go:("<<k<<","<<cnt<<") "<<m2[k]<<"\n";
    
    if(k>=m1.size()){
        //cout<<cnt<<"\n";
        if(cnt>0){
            ret++;
        }
        return;
    }
    
    //go(k+1,cnt+1);
    
    //i : k번째 옷 종류에서 입을 옷의 갯수
    for(int i=0;i<=m2[k];++i){
        go(k+1,cnt+i);
    }
    
}

int solution(vector<vector<string>> clothes) {
    
    for(auto v : clothes){
        m1[v[1]]++;
    }
    
    ret=1;
    for(auto item : m1){
        ret*=item.second+1;
    }
    ret--;
    
    return ret;
    
    int i=0;
    for(auto item : m1){
        //cout<<item.first<<" "<<item.second<<"\n";
        m2[i]=item.second;
        ++i;
    }
    
    // for(auto item : m2){
    //    cout<<item.first<<" "<<item.second<<"\n";
    // }

    
    go(0,0);
    
    return ret;
}