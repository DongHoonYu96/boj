#include <bits/stdc++.h>

using namespace std;

int dp[504][504];

//1. d[i][j] : i높이에서 누적 최대합. / 출발지점 : j
//pre[i]: i번째에서 이전에 선택한 값.

//d[0]=7
//d[1][0]=7+3
//d[1][1]=7+8

//d[2][0]=d[1][0]+score[2][0]
//d[2][1]=max(d[1][0], d[1][1])+score[2][1]
//d[2][2]=d[1][1]+score[2][2]

//2. d[k][i] = max(d[k-1][i-1],d[k-1][i])+score[k][i]
//단, i==0 -> d[k][i] =d[k-1][0]+score[k][i]
//단, i==n끝 -> d[k][i] =d[k-1][끝]+score[k][i]
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=i; j++){
            if(j==0) dp[i][j] = dp[i-1][0] + triangle[i][j];
            else if(j==i) dp[i][j] = dp[i-1][i-1] + triangle[i][j];
            else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    for(int i = 0; i < n;i++){
        if(answer < dp[n-1][i]) answer = dp[n-1][i];
    }
    return answer;
    
    return 0;
}