#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;
ll ans[1000000 + 4];
stack<pair<ll, ll>> s; // idx, val

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;

    for (int i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    s.push({ 0,arr[0] });

    for (int i = 1; i < n; ++i) {
        ll cur = arr[i];
        while (s.size() && s.top().second < cur) {
            ans[s.top().first] = cur;
            s.pop();
        }
        s.push({ i,cur });
    }

    while (s.size()) {
        ll idx = s.top().first;
        ans[idx] = -1;
        s.pop();
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}