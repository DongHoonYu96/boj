#include <bits/stdc++.h>

using namespace std;
vector<int> answer(11);
vector<int> tmp(11);
int maxDiff;

vector<int> solution(int n, vector<int> info) {
    
    //1~2^10 : O(1024) -> 가능
    for(int subset=1;subset<(1<<10);++subset){
        int a=0,b=0,cnt=0; //어피치,라이언 점수, 쏜화살수
        for(int i=0;i<10;++i){ //인덱스 하나씩 보면서 subset에 1이 있는지 탐색
            if(subset&(1<<i)){ //1==라이언이 이기는경우
                b+=10-i;
                tmp[i]=info[i]+1; //라이언이 맞힌 화살갯수 갱신 , 한발더쏴야 이김
                cnt+=tmp[i];
            }
            else{ //라이언이 지거나 비기는경우
                tmp[i]=0; //0발쏨
                if(info[i]>0){ //어피치가 쏜화살이 있는경우
                    a+=10-i;
                }
                else{//둘다 0발인경우
                    //pass
                }
            }
        }
        
        if(cnt>n) continue; //쏠수있는화살보다 많이쏜경우 패스
        
        tmp[10]=n-cnt; //남은화살을 0점에 쏘기
        
        //새로운 최대값인경우
        if(b-a>maxDiff){
            maxDiff=b-a;
            answer=tmp;
        }
        //정답이 두개인경우
        else if(b-a==maxDiff){
            //maxDiff=b-a;
            for(int i=10;i>=0;--i){
                if(tmp[i]>answer[i]){
                    answer=tmp;
                    break;
                }
            }
        }
    }
    if(maxDiff==0)
        return {-1};
    return answer;
}