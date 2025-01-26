#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>,greater<>> pq; //최소힙

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;
   for(int i=0;i<n;++i) {
      int p,d;
      cin>>p>>d;
      v.push_back({d,p}); // { 일, 돈 }
   }
   sort(v.begin(),v.end()); // 일기준 오름차

   for(int i=0;i<n;++i) {
      pq.push(v[i].second); // 돈 추가

      //일수가 여러개인경우, 적은돈 제거
      if(pq.size() > v[i].first) { 
         pq.pop();
      }
   }

   while(pq.size()) {
      ret+=pq.top(); pq.pop();
   }
   
   cout<<ret;
   

   return 0;
}