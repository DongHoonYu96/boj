#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int d[504][504][2]; //좌표, 0-> 1아래

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    fill(&d[0][0][0],&d[0][0][0]+504*504*2,0);
    //dp[0][0]=0;
    ///-> -> -> 초기화
    for(int i=0;i<m;++i)
    {
        if(city_map[i][0]==1) break;
        d[i][0][1]=1;
    }
    for(int j=0;j<n;++j)
    {
        if(city_map[0][j]==1) break;
        d[0][j][0]=1;
    }

    //return 0;

    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(city_map[i-1][j]==0){
                d[i][j][1]+=(d[i-1][j][0]+d[i-1][j][1])%MOD;
            }
            if(city_map[i-1][j]==2){
                d[i][j][1]+=(d[i-1][j][1]%MOD);
            }
            if(city_map[i][j-1]==0){
                d[i][j][0]+=(d[i][j-1][0]+d[i][j-1][1])%MOD;
            }
            if(city_map[i][j-1]==2){
                d[i][j][0]+=(d[i][j-1][0]%MOD);
            }
        }
    }
    
    return (d[m-1][n-1][0]+d[m-1][n-1][1])%MOD;
}