#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ret=987654321;
int a[44]; //a[i] : i 행 의 상태를 숫자 1개로 나타냄

void go(int here) {
    if(here==n+1) {
        /**
         *  i: 1 2 4 를 돌면서 | T의 갯수검사, 열 검사 위한 변수
         *  j: a[1] a[2] a[3] 행의 상태 탐색위한 변수
         **/
        int sum=0; // 현재 상태에서 최적의 t의갯수
        for(int i=1; i<= (1<<(n-1)); i*=2) { // ++i 아님에 주의!!, (n-1)에 괄호쳐야함에 주의!
            int t=0; //t의 갯수
            for(int j=1; j<=n;++j) {
                if(a[j] & i) {
                    t++;
                }
            }
            if(t > n/2) { //뒤집는게 최적
                sum+=n-t;
            }
            else {
                sum+=t; //안뒤집는게 최적
            }
        }
        ret=min(ret,sum);
        return;
    }

    a[here]= ~a[here]; // 뒤집는경우
    go(here+1);
    a[here]= ~a[here]; // 안뒤집는경우
    go(here+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    /**
     *  124
     *  HHT -> 4 로 만들기
     */
    for(int i=1;i<=n;++i) {
        string s;
        cin>>s;
        int val=1;
        for(int j=0;j<n;++j) {
            if(s[j]=='T') a[i] |=val;
            val*=2;
        }
    }

    go(1);

    // for(int i=1;i<=n;++i) {
    //     cout<<a[i]<<" ";
    // }

    cout<<ret;
    
    return 0;
}