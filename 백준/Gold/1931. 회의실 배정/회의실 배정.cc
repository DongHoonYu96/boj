#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ret;
vector<pair<int,int>> v; // < 끝시, 시작시 >

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;
   for (int i=0;i<n;++i) {
      int a,b;
      cin>>a>>b;
      v.push_back({b,a});
   }
   sort(v.begin(),v.end());

   int endTime=v[0].first; ret++;
   for(int i=1;i<n;++i) {
      if(v[i].second < endTime ) continue;
      endTime = v[i].first;
      ret++;
   }
   cout<<ret;
   return 0;
}