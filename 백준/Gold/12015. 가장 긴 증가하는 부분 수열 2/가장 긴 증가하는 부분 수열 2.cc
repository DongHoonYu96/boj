#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000000+4], lis[1000000+4];
int n,len;


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;
   for(int i=0;i<n;++i) {
      cin>>a[i];
   }

   for(int i=0;i<n;++i) {
      int idx = lower_bound(lis,lis+len,a[i])-lis;

      //개큰수 등장
      if(idx==len) {
         len++;
      }
      lis[idx]=a[i];
   }
   cout<<len;
   
   return 0;
}