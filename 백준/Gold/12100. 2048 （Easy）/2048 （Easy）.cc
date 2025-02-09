#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ret;
int n, a[24][24], origin[24][24];

void moveup() {
    for(int j = 0; j < n; j++) {
        int idx = 0;  // 숫자를 채울 위치
        int prev = 0; // 이전 숫자 저장
        
        // 위에서부터 아래로 읽으면서
        for(int i = 0; i < n; i++) {
            if(a[i][j] == 0) continue;
            
            if(prev == 0) {
                prev = a[i][j];
            }
            else if(prev == a[i][j]) {
                a[idx++][j] = prev * 2;
                prev = 0;
            }
            else {
                a[idx++][j] = prev;
                prev = a[i][j];
            }
        }
        if(prev != 0) a[idx++][j] = prev;
        
        // 나머지 채우기
        while(idx < n) a[idx++][j] = 0;
    }
}

void movedown() {
    for(int j = 0; j < n; j++) {
        int idx = n-1;  // 숫자를 채울 위치
        int prev = 0; // 이전 숫자 저장
        
        // 아래에서부터 위로 읽으면서
        for(int i = n-1; i >= 0; i--) {
            if(a[i][j] == 0) continue;
            
            if(prev == 0) {
                prev = a[i][j];
            }
            else if(prev == a[i][j]) {
                a[idx--][j] = prev * 2;
                prev = 0;
            }
            else {
                a[idx--][j] = prev;
                prev = a[i][j];
            }
        }
        if(prev != 0) a[idx--][j] = prev;
        
        // 나머지 채우기
        while(idx >= 0) a[idx--][j] = 0;
    }
}

void moveleft() {
    for(int i = 0; i < n; i++) {
        int idx = 0;  // 숫자를 채울 위치
        int prev = 0; // 이전 숫자 저장
        
        // 왼쪽에서부터 오른쪽으로 읽으면서
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0) continue;
            
            if(prev == 0) {
                prev = a[i][j];
            }
            else if(prev == a[i][j]) {
                a[i][idx++] = prev * 2;
                prev = 0;
            }
            else {
                a[i][idx++] = prev;
                prev = a[i][j];
            }
        }
        if(prev != 0) a[i][idx++] = prev;
        
        // 나머지 채우기
        while(idx < n) a[i][idx++] = 0;
    }
}

void moveright() {
    for(int i = 0; i < n; i++) {
        int idx = n-1;  // 숫자를 채울 위치
        int prev = 0; // 이전 숫자 저장
        
        // 오른쪽에서부터 왼쪽으로 읽으면서
        for(int j = n-1; j >= 0; j--) {
            if(a[i][j] == 0) continue;
            
            if(prev == 0) {
                prev = a[i][j];
            }
            else if(prev == a[i][j]) {
                a[i][idx--] = prev * 2;
                prev = 0;
            }
            else {
                a[i][idx--] = prev;
                prev = a[i][j];
            }
        }
        if(prev != 0) a[i][idx--] = prev;
        
        // 나머지 채우기
        while(idx >= 0) a[i][idx--] = 0;
    }
}

void bok() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            a[i][j] = origin[i][j];
        }
    }
}

void go(vector<int>& v) {
    for(int dir : v) {
        if(dir==0) moveup();
        else if(dir==1) movedown();
        else if(dir==2) moveleft();
        else moveright();
    }
    
    int mx = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            mx = max(mx, a[i][j]);
        }
    }
    ret = max(ret, mx);
}

void combi(vector<int>& v) {
    if(v.size()==5) {
        bok();
        go(v);
        return;
    }
    for(int i=0; i<4; ++i) {
        v.push_back(i);
        combi(v);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> origin[i][j];
        }
    }
    
    vector<int> v;
    combi(v);
    cout << ret;
    
    return 0;
}