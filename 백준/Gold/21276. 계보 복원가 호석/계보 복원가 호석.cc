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
        indeg[s2]++; //상도한테 화살표들어옴
        outdeg[s1]++; //호석에서 화살표나감
    }

    //outdeg가 0 -> 조상
    vector<string> josang;
    for (auto item : adj) {
        if (outdeg[item.first] == 0) {
            josang.push_back(item.first);
        }
    }

    cout << josang.size()<<"\n";
    for (auto s : josang) {
        cout << s << " ";
    }cout << "\n";

    //outdegree의 차이가 1-> 직계자식!
    for (auto item : adj) { //모든 후손들에대해 item : 부모이름, {후손들이름}
        vector<string> jasik;
        for (auto s : item.second) {
            if (outdeg[s] - outdeg[item.first] == 1) {
                jasik.push_back(s);
            }
        }
        cout << item.first << " " << jasik.size() << " ";
        for (auto s : jasik) {
            cout << s << " ";
        }cout << "\n";
        //cout << item.first << " " << indeg[item.first] << " ";
        //for (auto s : item.second) {
        //    cout << s << " ";
        //}cout << "\n";
    }


    return 0;

}