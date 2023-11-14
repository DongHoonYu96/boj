#include <bits/stdc++.h>

using namespace std;

vector<stack<int>> v;
stack<int> s;   //뽑은애들

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n=board.size()-1;
    
    for(int x=0;x<n+1;++x){
        stack<int> temp;
        for(int y=n;y>=0;--y){
            if(board[y][x]==0) continue;
            temp.push(board[y][x]);
        }
        v.push_back(temp);
    }
    
    // for(auto ss:v){
    //     while(ss.size()){
    //         cout<<ss.top()<<" ";
    //         ss.pop();
    //     }
    //     cout<<"\n";
    // }
    
    
    for(int i : moves){
        if(v[i-1].size()){
            if(s.size() && s.top()==v[i-1].top()){
                s.pop();
                answer++;
            }
            else{
                s.push(v[i-1].top());
            }
            v[i-1].pop();
        }
        
    }
    
    return answer*2;    //인형은 한번터질때 2개씩 터짐
}