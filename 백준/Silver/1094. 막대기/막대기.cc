#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>x;

    // 64까지
    int cnt=0;
    for(int j=1;j<=(1<<6);j*=2) {
        if(x&j) cnt++;
    }

    cout<<cnt;

    
    
    return 0;
}