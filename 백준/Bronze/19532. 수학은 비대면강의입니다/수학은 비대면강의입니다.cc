#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c,d,e,f;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>a>>b>>c>>d>>e>>f;

   for(int x=-999;x<=999;++x) {
      for(int y = -999;y<=999;++y) {
         if(a*x + b*y == c && d*x+e*y==f) {
            cout<<x<<" "<<y;
            return 0;
         }
      }
   }

   

   
  
   
   return 0;
}