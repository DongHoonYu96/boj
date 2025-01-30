#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ret; // 경우의수는 ll 박고 시작
ll arr[100000+4], vis[100000+4];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;

   for(int i=0;i<n;++i) {
      cin>>arr[i];
   }

   //각 s 에 대해
   int e=0;
   for(int s=0;s<n;++s) {
      while(e<n) {
         if(vis[arr[e]]) {
            //ret+=(e-s); // 여기두면 e==n이 될때 계산이 누락됨!
            break;
         }
         vis[arr[e]]=1;
         e++;
      }
      ret+=(e-s); // 올바른위치
      vis[arr[s]]=0;
   }
   
   cout<<ret;
   
   return 0;
}