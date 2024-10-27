#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    int answer = 0;
    
    // B팀의 숫자들을 내림차순으로 정렬
    sort(B.begin(), B.end(), greater<int>());
    // A팀의 숫자들을 내림차순으로 정렬
    sort(A.begin(), A.end(), greater<int>());
    
    int left = 0;    // B팀의 가장 큰 수들을 가리키는 포인터
    int right = n-1; // B팀의 가장 작은 수들을 가리키는 포인터
    
    // A팀의 각 숫자에 대해 큰 수부터 처리
    for(int i = 0; i < n; i++) {
        // B팀의 현재 가장 큰 수가 A팀의 수보다 크면
        if(B[left] > A[i]) {
            answer++; // 승점 획득
            left++;   // 다음으로 큰 B팀의 수로 이동
        }
        // A팀의 수가 더 크거나 같으면
        else {
            right--; // B팀의 가장 작은 수 중 하나를 사용
        }
    }
    
    return answer;
}