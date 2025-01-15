#include <bits/stdc++.h>
using namespace std;   

int m;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin >> m;

   int s=0;
   while(m--) {
      string op;
      int num;
      cin>>op;

      if(op =="add") {
         cin>>num;
         num--;
         s |= (1<<(num));
      }
      if(op=="remove") {
         cin>>num;
         num--;
         if(s & (1<<(num))) {
            int bit = 1<<num;
            int mask = ~bit;
            s &= mask;
         }
      }
      if(op=="check") {
         cin>>num;
         num--;
         if(s & (1<<(num))) {
            cout<<1<<"\n";
         }
         else {
            cout<<0<<"\n";
         }
      }
      if(op=="toggle") {
         cin>>num;
         num--;
         if(s & (1<<(num))) {
            int bit = 1<<num;
            int mask = ~bit;
            s &= mask;
         }
         else {
            s |= (1<<(num));
         }
      }
      if(op=="all") {
         s = (1<<20) -1;
      }
      if(op=="empty") {
         s=0;
      }
      
   }
  
   return 0;
}