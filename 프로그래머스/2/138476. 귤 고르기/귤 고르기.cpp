#include <bits/stdc++.h>

using namespace std;

int a[10000000+1]; //a[1] : 1의 등장횟수
int ret;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto i : tangerine){
        a[i]++;
    }
    
    sort(a,a+10000000+1,greater<int>());
    
    int i=0;
    while(true){
        if(k==0) break;
        if(a[i]==0) {
            i++;
            ret++;
            continue;
        }
        a[i]--;
        k--;
        
    }
    
    return ret+1;
}