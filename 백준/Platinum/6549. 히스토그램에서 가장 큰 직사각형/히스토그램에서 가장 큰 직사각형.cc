#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, arr[100000+4];

// < 값, idx >

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   while(1) {
      cin>>n;
      if(n==0) return 0;

      stack<pair<ll,ll>> s; // tc문제는 초기화 주의
      ll ret=0;
      memset(arr,0,sizeof(arr));

      for (int i = 1; i <= n; i++) cin >> arr[i];

      s.push({0,0});
      for(int i=1;i<=n+1;++i) {
         // 내림차순 -> 확정 -> 계산
         while(s.size() && s.top().first > arr[i]) {
            int h = s.top().first;
            s.pop();
            ret= max(ret, (i-s.top().second-1) * h); // 밑변 * 높이
         }
         // 오름차순, 같은경우 -> 단순 push
         s.push({arr[i],i});
      }
      cout<<ret<<"\n";
   }

   
   return 0;
}