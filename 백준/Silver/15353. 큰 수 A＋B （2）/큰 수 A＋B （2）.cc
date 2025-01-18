#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a,b;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);


   cin>>a>>b;
   // 자릿수 맞춰야함 0으로
   if(a.size()>b.size()) {
      while(a.size()!=b.size()) {
         b="0"+b;
      }
   }
   else {
      while(a.size()!=b.size()) {
         a="0"+a;
      }
   }
   // cout<<a<<" "<<b<<"\n";

   // 뒤에서부터 한자리씩 더하기, 캐리넘기기
   vector<int> v; //계산결과 저장, 나중에 뒤집으면됨
   int n=a.size();
   int carry=0;
   for(int i=n-1;i>=0;--i) {
      int sum=(a[i]-'0') + (b[i]-'0');
      if(carry) sum+=1;
      if(sum >=10) {
         v.push_back(sum%10);
         carry=1;
      }
      else {
         v.push_back(sum);
         carry=0;
      }
   }
   // 마지막캐리가있는경우
   if(carry) {
      v.push_back(1);
   }

   reverse(v.begin(), v.end());
   for(auto i : v) {
      cout<<i;
   }
  
   return 0;
}