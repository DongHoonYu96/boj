#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000+4], lis[100000+4];
int n;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   while(cin>>n) {
      memset(a,0,sizeof(a));
      memset(lis,0,sizeof(lis));
      int len=0;
      for(int i=0;i<n;++i) {
         cin>>a[i];
      }
      for(int i=0;i<n;++i) {
         int idx = lower_bound(lis,lis+len,a[i])-lis;
         if(idx==len) {
            len++;
         }
         lis[idx]=a[i];
      }
      cout<<len<<"\n";
   }

  
   
   return 0;
}