#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;  // 첫 번째 그룹을 위한 카운트
    int n = targets.size();
    
    sort(targets.begin(), targets.end(), cmp);
    
    double missile = targets[0][1] - 0.5;  // 첫 번째 요격 지점
    
    for(int i = 1; i < n; ++i){
        if(targets[i][0] >= missile) {  // 현재 미사일이 이전 요격 범위를 벗어난 경우
            missile = targets[i][1] - 0.5;  // 새로운 요격 지점
            answer++;
        }
    }
    
    return answer;
}