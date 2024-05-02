#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ROOT = 1; //1번부터 시작!
int unused = 2; //다음노드 넣을 번호
const int MX = 10000 * 10 + 5; // N * 문자열길이 : 최대 등장 가능한 글자의 수
int chk[MX]; // 해당노드가 단어의 끝인지
int nxt[MX][10]; //[mx][문자종류]
//[노드][자식'A'] = 자식번호
//[1]['A'] = 2 //1번노드의 자식이 A이고, 그 번호가 2번임
//[1]['B'] = -1(초기값) : B라는 자식이 없음

int c2i(char c) {
    return c - '0';
}

//삽입시, cur이 체크되있음 -> 삽입단어와 이미 있는단어가 접두어관계임 -> ~일관성 -> 0
bool insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) //기존에 없던 문자면
            nxt[cur][c2i(c)] = unused++; //번호부여, unused갱신(2->3)
        cur = nxt[cur][c2i(c)]; // 새 노드(2) 가르키도록
        if (chk[cur]) return 0;
    }
    if (cur != unused - 1) return 0;
    chk[cur] = 1; //단어의 끝 표시
    return 1;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    //return chk[cur]; //딱맞는 단어 검사
    return true; //접두사검사
}

void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            continue;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = 0; //단어의 끝 표시만 지우면 됨.
}
int n,t;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> t;
    while (t--) {
        unused = 2;
        /*memset(nxt, -1, sizeof(nxt));
        memset(chk, 0, sizeof(chk));*/
        fill(chk, chk + MX, 0);
        for (int i = 0; i < MX; i++)
            fill(nxt[i], nxt[i] + 10, -1);
        cin >> n;
        int flag = 1;

        string s;
        while (n--) {
            cin >> s;
            if (!insert(s)) {
                flag = 0;
            } 
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}