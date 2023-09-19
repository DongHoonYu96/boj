#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // vector<int> temp(array.begin()+2-1,array.begin()+5);
    // for(auto i:temp){
    //     cout<<i<<" ";
    // }
    
    for(auto arr:commands){
        vector<int> temp(array.begin()+arr[0]-1,array.begin()+arr[1]);
        sort(temp.begin(),temp.end());
        answer.push_back(temp[arr[2]-1]);

    }
    
    
    return answer;
}