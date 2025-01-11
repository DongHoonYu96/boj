#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,ret;
int study[26];
vector<string> arr;


void go(int subset) {
    memset(study,0,sizeof(study));
    for(int i=0;i<26;++i) {
        if(subset & (1<<i)) {
            study[i]=1; //0:'a', 1:'b'
        }
    }
    int cnt=0;

    for(auto s : arr) {
        bool flag=true;
        for(auto c: s) {
            if(!study[c-'a']) {
                flag=false;
                break;
            }
        }
        if(flag) cnt++;
    }
    ret=max(ret,cnt);
}

void combi(int idx, vector<int> v) {
    if(v.size()==k) {
        memset(study,0,sizeof(study));
        for(auto i : v) {
            study[i]=1; //0:'a', 1:'b'
        }
        int cnt=0;

        for(auto s : arr) {
            bool flag=true;
            for(auto c: s) {
                if(!study[c-'a']) {
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        ret=max(ret,cnt);
        return; //return 빼먹지마
    }

    for(int i=idx+1;i<26;++i) { //idx+1 부터! 
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;

    for(int i=0;i<n;++i) {
        string s;
        cin>>s;
        arr.push_back(s);
    }

    // k가 5보다 작으면 'a','n','t','i','c'도 읽을 수 없음
    if(k < 5) {
        cout << 0;
        return 0;
    }

    // 필수 알파벳 5개를 뺀 나머지 k-5개를 선택
    //k -= 5;
    //'a','n','t','i','c' 는 기본으로 
    int bit=0;
    for(char c : {'a','n','t','i','c'}) {
        study[c-'a'] = true;
        bit |= (1<<(c-'a')); // c-'a' 아님에 주의!
    }

    // vector<int> v;
    // combi(-1,v);

    for(int subset = 1; subset < (1<<26); ++subset) {
        //subset|=bit; // 필수포함 알파벳, 이러면 안됨
        // 필수 알파벳이 포함되어 있는지 확인
        if((subset & bit) != bit) continue;
        int cnt=0;
        for(int i=0;i<26;++i) {
            if(subset & (1<<i)) {
                cnt++;
            }
        }
        //nCk
        if(cnt==k) {
            go(subset);
        }
    }

    cout<<ret;
    
    return 0;
}