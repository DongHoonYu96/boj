#include <bits/stdc++.h>
using namespace std;   

int t,n,m, vis[1004];
vector<int> adj[1004];

int dfs(int here) {
   vis[here]=1;

   int ret=1;
   for(auto nxt : adj[here]) {
      if(vis[nxt]) continue;
      ret += dfs(nxt);
   }
   return ret;
   
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin >>t;

   while(t--) {
      cin>>n>>m;
     
      for(int i = 0; i <= n; i++) {
         adj[i].clear();
      }
      memset(vis,0,sizeof(vis));
      
      for(int i=0;i<m;++i) { // m--하면 안됨! 아래에서 조회해야함
         int a,b;
         cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
      }

      // 트리 조건 체크: 간선 수 = 노드 수 - 1
      if(m == n-1 && dfs(1) == n) {
         cout << "tree\n";
      } else {
         cout << "graph\n";
      }
   }

   
  
   return 0;
}