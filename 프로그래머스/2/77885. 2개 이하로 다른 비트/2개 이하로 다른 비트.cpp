#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto number : numbers){
        for(ll i=1;;i=i<<1){ //i : 00001, 00010 ...
            if((number & i)==0){ //0을만나면 (== 직전비트는 1이었음)
                number=number|i; //현재비트를 1로바꾸기
                number=number^(i>>1); //이전비트(1확정)를 0으로 바꾸기 (1^1==0 임)
                answer.push_back(number);
                //cout<<number<<" ";
                break;
            }
        }
    }
    return answer;
}