#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x,ret; // 경우의수는 ll 박고 시작
vector<ll> v;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n;

   for(int i=0;i<n;++i) {
      int tmp;
      cin>>tmp;
      v.push_back(tmp);
   }
   cin>>x;

   sort(v.begin(),v.end());

   for(int i=0;i<n;++i) {
      if(binary_search(v.begin()+i+1,v.end(),abs(x-v[i]))) ret++;
      // int idx = lower_bound(v.begin()+i+1,v.end(),abs(x-v[i]))-v.begin();
      // if(idx!=n) ret++;
   }
   
   cout<<ret;
   
   return 0;
}