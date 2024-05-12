#include <bits/stdc++.h>

using namespace std;

int n;
int pre1[3], pre2[3], cur1[3], cur2[3];
int mx[3], mi[3];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i=0 ;i<n ;++i) {
        int x, y, z;
        cin >> x >> y >> z;
        int p, q,r;
        p = max(mx[0], mx[1]);
        q = max({ mx[0], mx[1],mx[2] });
        r = max(mx[1], mx[2]);
        mx[0] = x + p;
        mx[1] = y + q;
        mx[2] = z + r;

        p = min(mi[0], mi[1]);
        q = min({ mi[0], mi[1], mi[2] });
        r = min(mi[1], mi[2]);
        mi[0] = x + p;
        mi[1] = y + q;
        mi[2] = z + r;

        /*cout << "[";
        for (int j = 0; j < 3; ++j) {
            cout << mi[j] << " ";
        }cout << "]\n";*/

    }
   

    cout << max({ mx[0],mx[1],mx[2] })<<" ";
    cout << min({ mi[0],mi[1],mi[2] }) << " ";

    return 0;

}