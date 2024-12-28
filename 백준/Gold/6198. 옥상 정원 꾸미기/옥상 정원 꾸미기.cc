#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;
stack<pair<ll,ll>> s;
ll ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    s.push({0,arr[0]});
    for (int i = 1; i < n; ++i) {
        //나보다 작은놈은 필요없다.
        while(s.size() && s.top().second <= arr[i]) {
            s.pop();
        }
        ret+=s.size();
        s.push({i, arr[i]});
    }
    
    cout<<ret;
    
    return 0;
}