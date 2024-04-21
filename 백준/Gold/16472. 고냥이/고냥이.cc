#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string str;
set<int> ss; //현재 알파벳 등장한것들 저장
int n, ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> str;

    int s = 0, e = 0;
    ss.insert(str[s]);


    while (s<str.size() && e<str.size()) {
        ret = max(ret, e - s + 1);

        if (ss.size() <= n) {
            e += 1;
            if (e < str.size() && ss.find(str[e]) == ss.end()) {
                ss.insert(str[e]);
            }
        }
        if (ss.size() > n) {
            s = s + 1;
            e = s;
            ss.clear();
            ss.insert(str[s]);
        }

    }

    cout << ret;

    return 0;
}