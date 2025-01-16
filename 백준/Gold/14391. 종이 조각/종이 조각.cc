#include <bits/stdc++.h>
using namespace std;   

int n,m, arr[5][5], ret;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin >>n>> m;

   for(int i=0;i<n;++i) {
      string s;
      cin>>s;
      for(int j=0;j<m;++j) {
         arr[i][j]=s[j]-'0';
      }
   }

   int N = n*m;
   for(int subset = 0; subset < (1<<N);++subset) {
      int garo_sum=0;
      for(int i=0;i<n;++i) {
         int sum=0;
         for(int j=0;j<m;++j) {
            if(subset & (1<<(j+i*m))) { //j+i*n 아님
               sum = sum*10 + arr[i][j];
            }
            else {
               garo_sum +=sum;
               sum=0;
            }
         }
         garo_sum += sum; // Add remaining sum
      }

      int sero_sum=0;
      for(int j=0;j<m;++j) {
         int sum=0;
         for(int i=0;i<n;++i) {
            if(!(subset & (1<<(j+i*m)))) {
               sum = sum*10 + arr[i][j];
            }
            else {
               sero_sum +=sum;
               sum=0;
            }
         }
         sero_sum += sum; // Add remaining sum
      }
      ret = max(ret, garo_sum + sero_sum);
   }

   cout<<ret;
   
  
   return 0;
}