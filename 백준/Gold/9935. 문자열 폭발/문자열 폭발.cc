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
   
   string ret="";
   for(int i=0;i<n;++i) {
      ret+=s[i];
      if(len <= ret.size()) {
         string sub = ret.substr(ret.size()-len,ret.size());
         if(sub==t) {
            ret.erase(ret.end()-len,ret.end());
         }
      }
   }
   
   if(!ret.size())cout << "FRULA" << "\n";
   else cout << ret << "\n";
   return 0;
}