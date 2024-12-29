#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, ret;
vector<int> arr;

void combi(int idx, vector<int>& v) {
    if(v.size()==2) {
        int a = arr[v[0]];
        int b = arr[v[1]];
        if(a+b == m) {
            ret++;
        }
        return;
    }
    for(int i=idx+1 ; i<n;++i) {
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    if(m > 200000) {
        cout<<0;
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    
    vector<int> v;
    combi(-1,v);
    
    cout<<ret;
}
