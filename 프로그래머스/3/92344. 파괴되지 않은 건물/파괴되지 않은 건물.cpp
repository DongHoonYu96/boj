#include <bits/stdc++.h>

using namespace std;
int a[1004][1004],ret;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n=board.size();
    int m=board[0].size();
    //1. 누적합배열생성
    for(auto v : skill){
        int type=v[0], r1=v[1],c1=v[2],
                r2=v[3],c2=v[4],degree=v[5];
        if(type==1) degree= -degree;
        a[r1][c1]+=degree;
        a[r2+1][c2+1]+=degree;
        a[r1][c2+1]-=degree;
        a[r2+1][c1]-=degree;
    }
    
    //누적합더하기 ->, 아래
    for(int i=0;i<n;++i){
        for(int j=1;j<m;++j){
            a[i][j]+=a[i][j-1];
        }
    }
    //누적합더하기  아래
    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){
            a[i][j]+=a[i-1][j];
        }
    }
    
    //board와 a 더하기
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            board[i][j]+=a[i][j];
        }
    }
    
    //1이상인 갯수세기
    int ret=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]>=1) ret++;
        }
    }
    return ret;
}