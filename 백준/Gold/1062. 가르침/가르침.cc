#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,ret;
int study[26];
int words[54]; // 단어를 bit로 나타내어 저장
vector<string> arr;

// mask: 현재 배운 알파벳들의 비트마스크
// 현재 배운 알파벳들로 읽을 수 있는 단어의 개수를 반환
int count(int mask) {
    int cnt=0;
    for(auto word : words) {
        // word가 0이 아니고(빈 단어가 아님)
        // word의 모든 알파벳이 mask에 포함되어 있으면 카운트
        /**
        *'abc'의 비트마스크(word) 만들기:
            a: 1<<0  = 000...000001
            b: 1<<1  = 000...000010
            c: 1<<2  = 000...000100
            word     = 000...000111  (이진수로 7)

            케이스별로 살펴보기:

            1. mask가 "abc"인 경우:
            mask      = 000...000111
            word      = 000...000111
            word & mask = 000...000111  (== word, 읽기 가능!)

            2. mask가 "ab"인 경우:
            mask      = 000...000011
            word      = 000...000111
            word & mask = 000...000011  (!= word, 읽기 불가능)

            3. mask가 "abcd"인 경우:
            mask      = 000...001111
            word      = 000...000111
            word & mask = 000...000111  (== word, 읽기 가능!)
            즉, mask가 더 큰 범위면 가능!
        */
        if(word && (word & mask) == word) cnt++;
    }
    return cnt;
}

// index: 현재 검사중인 알파벳 (0: 'a', 1: 'b', ...)
// k: 앞으로 배워야 할 알파벳 수
// mask: 지금까지 배운 알파벳들의 비트마스크
int go(int idx, int k, int mask) {
    if(k<0) {
        return 0;
    }
    if(idx==26) return count(mask);
    
    //idx번째 알파벳을 선택하는경우
    //visited 대신 mask에 상태저장
    int ret = go(idx+1, k-1, mask | (1<<idx));

    // 현재 알파벳(index)이 필수 알파벳(a,n,t,i,c)이 아니면
    // 배우지 않는 경우도 시도
    //idx번째 알파벳을 선택안하는경우
    if (idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && 
       idx != 'i'-'a' && idx != 'c'-'a') {
        ret= max(ret,go(idx+1,k,mask));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;

    // 단어를 bit로 나타내어 저장 => 나중에 체크쉬움
    /**
    *  예를 들어 단어가 "ant"라면:

        1. 'a': 1 << (97-97) = 1 << 0 = 000...0001
        2. 'n': 1 << (110-97) = 1 << 13 = 0010000000000
        3. 't': 1 << (116-97) = 1 << 19 = 1000000000000000000

        OR 연산(|=)으로 합치면:
        word[i] = 1000000000010000000001

        이렇게 하나의 정수에 해당 단어에 포함된 모든 알파벳의 위치에 1이 설정
     */
    for(int i=0;i<n;++i) {
        string s;
        cin>>s;
        for(auto c:s) {
            words[i]|=1<<(c-'a');
        }
    }

    // 첫 알파벳부터, k개를 배워야함, 아직 아무것도 배우지 않은 상태에서 시작
    cout<<go(0,k,0);
    
    return 0;
}