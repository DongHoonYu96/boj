#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 1. 칠판 만들기
char board[3100][6200];
// 2. 별 그리기
void printStar(int x,int y){
    board[x+0][y+2] = '*';

    board[x+1][y+1] = '*';
    board[x+1][y+3] = '*';

    board[x+2][y+0] = '*';
    board[x+2][y+1] = '*';
    board[x+2][y+2] = '*';
    board[x+2][y+3] = '*';
    board[x+2][y+4] = '*';
}
// 3. 재귀함수
void makeStarTree(int n,int x,int y){
    if(n==3){
        printStar(x,y);
        return;
    }
    makeStarTree(n/2,x,y+n/2);
    makeStarTree(n/2,x+n/2,y);
    makeStarTree(n/2,x+n/2,y+n);
}
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++) fill(board[i],board[i]+n*2,' ');
    makeStarTree(n,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n*2;j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}