#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,ret;
vector<pair<int,int>> v; // < 무게, 가격 >
vector<int> bag; // 가방무게들
priority_queue<int,vector<int>> pq; // 최대힙

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>k;
   for (int i=0;i<n;++i) {
      int a,b;
      cin>>a>>b;
      v.push_back({a,b});
   }
   for (int i=0;i<k;++i) {
      int a;
      cin>>a;
      bag.push_back(a);
   }
   // 보석 무게순 정렬
   sort(v.begin(),v.end());

   //가방 오름차순정렬
   sort(bag.begin(), bag.end());
   
   //각 가방에 대해
   int j=0; // 보석을 가르키는 포인터
   for(int i=0;i<k;++i) {
      while(j<n && bag[i]>=v[j].first) { //가능한 보석들을 다 담음
         pq.push(v[j].second);
         ++j;
      }
      if(pq.size()) {
         ret+=pq.top();
         pq.pop();
      }
      // if(j>=n) break;
   }
   cout<<ret;
   return 0;
}