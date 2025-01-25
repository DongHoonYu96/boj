#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ret;
int arr[10000+4], sum[10000+4];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>m;
   for(int i=0;i<n;++i) {
      cin>>arr[i];
   }

   int st=0; // sum에 포함
   int en=1; //sum에 안포함 => while문 범위를 같은것까지 넣어야함.
   int sum=arr[st];

   while(en<=n) {
      //감소하는 수 필요
      if(sum==m) {
         ret++;
         sum-=arr[st];
         st++;   
      }
      if(sum>m) {
         sum-=arr[st];
         st++; 
      }
      //증가하는 수 필요
      if(sum<m) {
         sum+=arr[en];
         en++; 
      }
   }
   
   cout<<ret;

   return 0;
}