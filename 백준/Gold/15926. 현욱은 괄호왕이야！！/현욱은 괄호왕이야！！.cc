#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ret, dp[200000+4];

stack<int> stk;
string s;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>s;
   
   for(int i=0;i<n;++i) {
      // cout<<cnt<<" ";
      if(s[i]=='(') {
         stk.push(i);
      }
      else if(s[i]==')' && stk.size()){
         dp[i]=1;
         dp[stk.top()]=1;
         stk.pop();
      }
   }

   int cnt=0;
   for(int i=0;i<n;++i) {
      if(dp[i]) {
         cnt++;
         ret=max(ret,cnt);
      }
      else {
         cnt=0;
      }
   }
   
   cout<<ret;
  
   return 0;
}