#include <bits/stdc++.h>
using namespace std;   

int t;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   string s;
   cin >>s;

   int yes=1;
   string buf="";
   for(int i=0;i<s.size();++i) {
      if(s[i]=='p') {
         if(i+1 >= s.size()) {
            yes=0;
            break;
         }
         if(s[i+1]!='i') {
            yes=0;
            break;
         }
         ++i;
      }
      else if(s[i]=='k') {
         if(i+1 >= s.size()) {
            yes=0;
            break;
         }
         if(s[i+1]!='a') {
            yes=0;
            break;
         }
         ++i;
      }
      else if(s[i]=='c') {
         if(i+1 >= s.size() || i+2>=s.size()) { // && 아님!!!
            yes=0;
            break;
         }
         if(s[i+1]!='h' || s[i+2]!='u') {
            yes=0;
            break;
         }
         i+=2;
      }
      else {
         yes=0;
         break;
      }
   }

   if(yes) {
      cout<<"YES";
   }
   else {
      cout<<"NO";
   }
   
   
  
   return 0;
}