#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ret, arr[500000+4];

// < 키, 연속된 같은키 카운팅 >
stack<pair<ll,ll>> stk; // 최악 50만개 다같은키인경우) n(n-1)/2

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;
   for(int i=0;i<n;++i) {
      cin>>arr[i];
   }
   
   for(int i=0;i<n;++i) {
      int cnt=1; //현재 사람의 연속 카운트 초기값 = 1

      // 오름차순인경우
      while(stk.size() && stk.top().first <= arr[i]) {
         ret+=stk.top().second; // 누적된 카운트들 더하기
         //같은경우 카운팅해주기
         if(stk.top().first == arr[i]) {
            cnt = stk.top().second+1;
         }
         else {
            cnt=1; // 다른키인경우 카운트 리셋
         }
         stk.pop();
      }
      // 내림차순인경우, 나보다 더큰사람이 있다는뜻 -> 1쌍추가
      if(stk.size()) ret++; 
      stk.push({arr[i],cnt});
   }

   cout<<ret;
  
  
   return 0;
}