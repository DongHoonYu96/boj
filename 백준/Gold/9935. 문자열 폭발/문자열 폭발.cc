#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,t;
stack<char> stk;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>s>>t;

   int n = s.size();
   int len = t.size();

   for(int i=0;i<n;++i) {
      stk.push(s[i]);
      //stack의 top과 target의 끝이 같으면 검사시작
      if(stk.size() && stk.top()==s[i] && stk.size() >= len) {
         string tmp="";
         for(int j=0;j<len;++j) {
            tmp+=stk.top();
            stk.pop();
         }
         
         reverse(tmp.begin(),tmp.end());
         //원복
         if(tmp!=t) {
            for(int k=0;k<tmp.size();++k) {
               stk.push(tmp[k]);
            }
         }
         //같으면 원복을 안하면됨
      }
   }

   string ret="";
   while(stk.size()) {
      ret+=stk.top();
      stk.pop();
   }
   reverse(ret.begin(),ret.end());
   if(ret=="") {
      cout<<"FRULA";
   }
   else {
      cout<<ret;
   }

   return 0;
}