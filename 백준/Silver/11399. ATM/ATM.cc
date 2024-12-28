#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> arr;
ll fibo[1004];
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
    
    sort(arr.begin(),arr.end());
    fibo[0]=arr[0];
    for(int i=1;i<n;++i) {
        fibo[i] = fibo[i-1] + arr[i];
    }
    for(int i=0;i<n;++i) {
        ret+=fibo[i];
    }
    cout<<ret;

    
    return 0;
}