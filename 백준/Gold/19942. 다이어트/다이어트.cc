#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,mp,mf,ms,mv;
int arr[16][6];
int ret=987654321; //최소비용구하기, 초기화=최대로
map<int, vector<vector<int>>> m; // 비용별 정답들

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mp>>mf>>ms>>mv;
    
    for(int i=0;i<n;++i) {
        for(int j=0;j<5;++j) {
            cin>>arr[i][j];
        }
    }

    //전체 부분집합에 대해( 1 ~ 2^n -1 ) ( 0 0 0 0 1  ~ 1 1 1 1 1 )
    for(int subset = 1; subset < (1 << n); ++subset) {
    // for(int subset = 8+4+2; subset <= 8+4+2; ++subset) {
        int a=0,b=0,c=0,d=0, e=0;
        vector<int> tmp; //정답 index들 후보
        //한칸씩 보면서 비트가 켜져있는지 검사
        //비트가 켜져있는경우 해당 재료를 선택
        for(int i=0; i< n;++i) {
            if(subset & (1<<i)) {
                a+=arr[i][0];
                b+=arr[i][1];
                c+=arr[i][2];
                d+=arr[i][3];
                e+=arr[i][4];
                tmp.push_back(i+1); // 1-idx로 바꾸기
            }
        }
        if(a<mp || b<mf || c<ms || d<mv) continue;
        if(ret >= e) { //현재가 더 싼경우
            ret=e;
            m[ret].push_back(tmp);
        }
    }

    if(ret==987654321) {
        cout<<-1;
        return 0;
    }

    cout<<ret<<"\n";
    sort(m[ret].begin(),m[ret].end());
    for(auto i : m[ret][0]) {
        cout<<i<<" ";
    }

    
    
    return 0;
}