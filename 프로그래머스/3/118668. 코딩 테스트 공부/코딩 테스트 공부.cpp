#include <bits/stdc++.h>

using namespace std;

int max_alp,max_cop;
const int INF=987654321;
int dp[154][154]; //(알고력,코딩력)에 도달하는데 필요한 최소시간

int solution(int alp, int cop, vector<vector<int>> problems) {
    int ret = 0;
    fill(&dp[0][0],&dp[0][0]+154*154,INF);
    int last=problems.size();                           
    //목표값 구하기
    for (int i = 0; i < last; i++) {
        max_alp=max(max_alp,problems[i][0]);
        max_cop=max(max_cop,problems[i][1]);
    }
    //alp,cop가 최대값보다 큰경우 예외처리
    alp=min(max_alp,alp);
    cop=min(max_cop,cop);
    //cout<<max_alp<<"\n";
    //cout<<max_cop<<"\n";
    
    //초기값
    dp[alp][cop]=0;

    //2. 경우의수
    //알고력공부해야되는경우 : dp[i+1][j]=dp[i][j]+1, 자기자신
    //코딩력공부해야되는경우 : dp[i][j+1]=dp[i][j]+1, 자기자신
    //문풀가능한경우 : dp[i+해당[2]][j+해당[3]]=dp[i][j]+해당[4] , 자기자신
    for(int i=alp;i<=max_alp;++i){
        for(int j=cop;j<=max_cop;++j){
            if(i<max_alp) dp[i+1][j]=min(dp[i][j]+1,dp[i+1][j]);    //알고력부족한경우
            if(j<max_cop) dp[i][j+1]=min(dp[i][j]+1,dp[i][j+1]);    //코딩력부족한경우
            for(auto v : problems){
                if(v[0]<=i && v[1]<=j){ //문풀가능한경우
                    int next_alp=min(max_alp,i+v[2]);   //최대값넘어가는 경우 최대값으로 고정
                    int next_cop=min(max_cop,j+v[3]);
                    dp[next_alp][next_cop]=min(dp[next_alp][next_cop],dp[i][j]+v[4]);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}