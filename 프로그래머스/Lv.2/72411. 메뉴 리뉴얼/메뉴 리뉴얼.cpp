#include <bits/stdc++.h>

using namespace std;

map<string,int> freq[11];

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m; //코스이름, 등장횟수
    
    for(auto order : orders){ //ABCFG
        sort(order.begin(),order.end());
        for(int subset=1;subset<(1<<order.size());++subset){ // A, AB, ABC, ...
            string menu;
            for(int j=0;j<order.size();++j){
                if(subset & (1<<j)) menu+=order[j];
            }
            freq[menu.size()][menu]++;
        }
    }
    
    vector<string> ans;
    for(auto i : course){
        int mxfreq=0;
        for(auto p : freq[i])
            mxfreq=max(mxfreq,p.second);
        if(mxfreq<2) continue;
        for(auto p : freq[i]){
            if(p.second==mxfreq) ans.push_back(p.first);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}