#include <bits/stdc++.h>

int root = 1;
int unused = 2;
const int mx = 100000 * 10 + 1; //!const 해야 배열의 크기로 사용가능!
int nxt[mx][26]; //종류
int cnt[mx], chk[mx], child[mx]; // 중복접두사의 갯수
int n;

using namespace std;

//내가 처음이면 1 리턴
void insert(string& s) {
    int cur = root;
    for (auto c : s) {
        if (nxt[cur][c - 'a'] == -1) {
            nxt[cur][c - 'a'] = unused++;
            child[cur]++;
        }
        cur = nxt[cur][c - 'a'];
        cnt[cur]++;
    }
    chk[cur] = 1; //단어의끝 표시
}


//전통적인 find : 있는지 없는지 검사
int find(string& s) {
    int ret = 1;
    int cur = root;

    for (int i = 0; i < s.size();++i) {

        /*if (nxt[cur][c - 'a'] == -1) {
            return false;
        }*/ //존재하는단어만 입력으로 들어옴!
        cur = nxt[cur][s[i] - 'a'];
        //cout << s[i] <<" "<< cnt[cur] << " " << child[cur] ;
        if (cnt[cur] == 1) {
            //cout << " 유일->모두자동완성 ";
            return ret; //유일한경우
        }
        //자식이1개다? -> 자동완성 -> ret+안하고 다음문자열 검색함
        if (!chk[cur] && child[cur] == 1) {
            //cout << " 자식이1명->자식자동완성 \n";

            continue; //자식이1명임 -> 자동완성
        }
        //단, 단어의끝은 예외(입력해야함)
        ret++;
        //cout << "다음단어를 입력하셈 ret+1 \n";
        if (i == s.size() - 1) {
            //cout << "다음단어 없으셈 \n";
            ret--;
        }
    }
    return  ret;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed;
    cout.precision(2); //!소수 둘째자리까지출력 (셋째에서 반올림)!

    while (cin >> n) {
        root = 1;
        unused = 2;
        memset(nxt, -1, sizeof(nxt));
        fill(child, child + mx, 0);
        fill(chk, chk + mx, 0);
        fill(cnt, cnt + mx, 0);

        vector<string> v;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            insert(s);
            v.push_back(s);
        }

        double ans = 0;
        for (int i = 0; i < n; ++i) {
            //ans+=find(v[i]);
            int t = find(v[i]);
            //cout << "답 "<<t << "\n";
            ans += t;
        }
        cout << 1.0 * ans / n<<"\n";
    }
    return 0;

}