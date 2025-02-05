#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,s,e,l,r,ret;
pair<int,int> p[1000000+4];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;

   for(int i=0;i<n;++i) {
      cin>>s>>e;
      p[i]={s,e};
   }

   sort(p,p+n);
   l=p[0].first; r=p[0].second;
   for(int i=1;i<n;++i) {
      if(r>=p[i].first && r<=p[i].second) { // 합칠수있으면 합치기
         r=p[i].second;
      }else if(r<p[i].first) { //못합치는경우 기존길이 더하기
         ret+=(r-l);
         l=p[i].first;
         r=p[i].second;
      }
   }

   ret+=(r-l);
   //마지막 남은길이 더하기
   cout<<ret;
   
   return 0;
}