#include <bits/stdc++.h>
using namespace std;

int sec,y,x;
int n,k,L, a[104][104], vis[104][104]; //-1 : 내몸, 2 : 사과, 0: 빈칸
//0 1 2 3 : -> 아 <- 위
deque<pair<int,int>> dq; // 뱀위 위치저장
vector<pair<int,int>> _time; // <초, 1> <초,3>, 몇초에 바뀌는지, 현재 방향에 더할숫자(1시계,3반시계)
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int dir=0;

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> n>>k;
   for(int i = 0; i < k; i++) {
      int y,x;
      cin>>y>>x;
      a[--y][--x]=1; //사과표시 (0-idx) 무조건 0-idx로 바꿔라.
   }
   cin>>L;
   for(int i = 0; i < L; i++) {
      char c;
      int y;
      cin>>y>>c;
      // D(오른쪽)면 1, L(왼쪽)이면 3을 더함 / 시계, 반시계
      if(c=='D')
         _time.push_back({y,1});
      else {
         _time.push_back({y,3});
      }
   }

   dq.push_back({0,0}); //시작점

   int idx=0; // 방향바꿀 시간인지 조회 위한 변수
   while(dq.size()) {
      sec++; // 시간증가
      tie(y,x)=dq.front();
      int ny = y + dy[dir]; //방향에따라 다음에 갈 위치 정하기
      int nx = x+ dx[dir];

      // 벽이나 자기 자신과 부딪히면 종료
      if(ny >= n || ny < 0 || nx >= n || nx < 0 || vis[ny][nx]) break;

      //사과 없는경우
      if(!a[ny][nx]) {
         vis[dq.back().first][dq.back().second]=0; //꼬리부분 미방문표시
         dq.pop_back(); // 과거의 꼬리제거
      }
      else { //사과있는경우, 사과를 제거!
         a[ny][nx]=0;
      }

      vis[ny][nx]=1;
      dq.push_front({ny,nx});

      if(sec == _time[idx].first) {
         // dir+= _time[idx].second % 4;
         dir = (dir + _time[idx].second) % 4;  // 수정된 부분
         idx++;
      }
   }
   
   cout<<sec;
   return 0;
}