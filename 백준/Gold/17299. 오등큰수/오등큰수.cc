#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;
stack<pair<ll,ll>> s;
ll F[1000000+4],ans[1000000+4];
ll ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        F[tmp]++;
        arr.push_back(tmp);
    }

    s.push({0,arr[0]});
    for (int i = 1; i < n; ++i) {
        while(s.size() && F[s.top().second] < F[arr[i]]) {
            ans[s.top().first] = arr[i];
            s.pop();
        }
        s.push({i, arr[i]});
    }

    while(s.size()) {
        ans[s.top().first] = -1;
        s.pop();
    }

    for(int i=0; i <n; ++i) {
        cout<< ans[i]<<" ";
    }
    

    
    return 0;
}