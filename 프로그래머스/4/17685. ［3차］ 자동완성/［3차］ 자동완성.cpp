#include <bits/stdc++.h>

int root = 1;
int unused=2;
const int mx=100000 * 10 +5; //!const 해야 배열의 크기로 사용가능!
int nxt[mx][27];
int cnt[mx],chk[mx]; // 중복접두사의 갯수

using namespace std;

void insert(string& s){
    int cur=root;
    for(auto c : s){
        if(nxt[cur][c-'a']==-1){
            nxt[cur][c-'a']=unused++;
        }
        cur=nxt[cur][c-'a'];
        cnt[cur]++;
    }
    chk[cur]=1; 
}
int find(string& s){
    int ret=0;
    int cur=root; //첫글자에서 시작
    
    for(auto c : s){
        if(cnt[cur]==1) break;
        cur=nxt[cur][c-'a'];
        ret++;
    }

    return ret;

}
int solution(vector<string> words) {
    int answer = 0;
    memset(nxt,-1,sizeof(nxt));
    
    for(auto word : words){
        insert(word);
    }
    for(auto word : words){
        answer+=find(word);
        cout<<"\n";
    }
    return answer;
}