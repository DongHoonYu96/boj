#include <bits/stdc++.h>

using namespace std;

int Y,X,num, a[504][504],ret;
vector<pair<int,int>> v; //탐색대상위치

int left(int y, int x) {
    if (x < 0) {
        return 0;
    }
    if (a[y][x] == 1) return 1;

    return left(y, x - 1);
}
int right(int y, int x) {
    if (x >= X) {
        return 0;
    }
    if (a[y][x] == 1) return 1;

    return right(y, x + 1);
}

//해당좌표에 빗물이 찰수있는지
int go(int y, int x) {
    //좌측에 1이있고 우측에 1이있으면 빗물찰수있음.

    if (left(y, x) && right(y, x)) return 1;
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Y>>X;

    for(int i=0;i<X;++i) {
        cin >> num;
        for (int j =Y-1; j>=0; --j) {
            if (num <= 0) break;
            a[j][i] = 1;
            num--;
        }
    }

    for (int i = 0; i < Y; ++i) {
        for (int j = 0; j <X; ++j) {
            if (a[i][j] == 0) {
                v.push_back({ i,j });
            }
            //cout << a[i][j] << " ";
        }//cout << "\n";
    }

    for (auto p : v) {
        if (go(p.first, p.second)) ret++;
    }

    cout << ret;
    return 0;

}