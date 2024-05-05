#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, int> indeg,outdeg;
int n,m;
map<string, vector<string>> adj;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s); //사람명단
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[s2].push_back(s1); //상도의 자식 : 호석
        adj[s1]; //자식없어도 초기화는 해줘야함! -> 0명일때 출력
        indeg[s1]++; //상도 -> 호석, 자식한테 화살표 들어옴
    }

    //indeg가 0 -> 조상
    vector<string> josang;
    for (auto item : adj) {
        if (indeg[item.first] == 0) {
            josang.push_back(item.first);
        }
    }

    sort(josang.begin(), josang.end());

    queue<string> q;
    cout << josang.size()<<"\n";
    for (auto s : josang) {
        cout << s << " ";
        q.push(s);
    }cout << "\n";

    map<string, vector<string>> res; //key의 직속자식들
    //초기값 : indeg가 0인 조상들
    while (q.size()) {
        auto cur = q.front(); q.pop();
        res[cur]; //맵 초기 할당
        //모든 후손에대해
        //나와 연결을 끊으면 indeg가 0이다(현재1) -> 직속자식이다!
        for (auto s : adj[cur]) {
            if (indeg[s] == 1) {
                res[cur].push_back(s);
                q.push(s);
            }
            indeg[s]--; //연결끊기
        }
    }

    for (auto item : res) {
        cout << item.first << " " << item.second.size() << " ";
        sort(item.second.begin(), item.second.end());
        for (auto child : item.second) {
            cout << child << " ";
        }cout << "\n";
    }
    return 0;

}