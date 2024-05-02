#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ROOT = 1; //1번부터 시작!
int unused = 2;
const int MX = 10000 * 500 + 5; // N * 문자열길이 : 최대 등장 가능한 글자의 수
bool chk[MX]; // 해당노드가 단어의 끝인지
int nxt[MX][26]; 
//[노드][자식'A'] = 자식번호
//[1]['A'] = 2 //1번노드의 자식이 A이고, 그 번호가 2번임
//[1]['B'] = -1(초기값) : B라는 자식이 없음

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++; //번호부여, cur갱신
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true; //단어의 끝 표시
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

int n, m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        insert(s);
    }

    int ans = 0;
    while (m--) {
        string s;
        cin >> s;
        ans += find(s);
        //if (find(s)) cout <<"정답:"<< s << "\n";
    }
    cout << ans;
}