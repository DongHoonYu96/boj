#include <bits/stdc++.h>

using namespace std;

int d[100000+1];
int solution(int n) {
    int answer=0;
    d[0]=0;
    d[1]=1;
    d[2]=1;
    d[3]=2;
    for(int i=4;i<=100000;++i){
        d[i]=(d[i-1]%1234567+d[i-2]%1234567)%1234567;
    }
    return d[n];
}