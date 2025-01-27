#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ret;
vector<pair<int,int>> v; // <데드라인, 컵라면 >
priority_queue<int, vector<int>, greater<>> pq; //컵라면 최소힙

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;
   for (int i=0;i<n;++i) {
      int a,b;
      cin>>a>>b;
      v.push_back({a,b});
   }
   sort(v.begin(),v.end());
   
   for(int i=0;i<n;++i) {
      pq.push(v[i].second);
      if(pq.size()>v[i].first) {
         pq.pop();
      }
   }

   while(pq.size()) {
      ret+=pq.top();
      pq.pop();
   }
   cout<<ret;
   
   
   return 0;
}