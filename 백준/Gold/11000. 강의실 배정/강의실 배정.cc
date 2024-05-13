#include <bits/stdc++.h>

using namespace std;


class cmp {
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first > p1.first;
        //!종료시간이 같다면! 시작시간이 작은것부터

        return p1.second > p2.second;
    }
};

int n,ret;
priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
vector<pair<int, int>> v;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i=0;i<n;++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    //1. 시작시간 기준으로 정렬

    pq.push({ v[0].first,v[0].second });
    for (int i = 1; i < n;++i) {
        pq.push({ v[i].first,v[i].second });

        //top과 같은강의실을 사용가능하다면, top을 지운다.
        //같은강의실 사용으로 간주, 즉 pq.size가 강의실의 갯수가된다. 
        if (pq.top().second <= v[i].first) {
            pq.pop();
        }

    }
    cout << pq.size();
    return 0;

}