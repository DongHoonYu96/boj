#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1000000+1] ; //노드i의 인접리스트
int indeg[1000000+1],outdeg[1000000+1],vis[1000000+1];
int a,b,c,d,n;

int dfs(int node, int st){
    cout<<node<<" ";

    //8자?
    if(vis[node] && node==st){
        return 2;
    }
    
    //다음노드봣더니 이미방문됨 -> 사이클
    if(vis[node]){
        cout<<"도넛\n";
        return 1; //도넛
    }

    for(auto nxt : adj[node]){
        if(vis[nxt]) continue;
        vis[node]=1;
        dfs(nxt,st);
    }
    return 0;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    unordered_set<int> s;
    //n=edges.size();
    
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        indeg[edge[1]]++;
        outdeg[edge[0]]++;
        n = max(n, max(edge[0], edge[1]));
    }

    for(int i=1;i<=n;++i){
        if(outdeg[i]>=2 && indeg[i]==0) a=i;
        //막대모양갯수 == indgee가 0인정점갯수
        else if(outdeg[i]==0 && indeg[i]>=1) {
            //cout<<i<<"\n";
            c++;
        }
        //도넛모양갯수 == in,out이 2이상인 정점의 갯수
        //즉! 유일정점의 특징을 발견하고, 그 갯수를 세면된다!
        else if(indeg[i]>=2 && outdeg[i]>=2) d++;
    }
    b=adj[a].size() - (c+d);
    //b+c+d == a.adj.size();
    //a : indegre 0 and outdegre max
    //b : 도넛
    //c : 막대
    //d : 8자
    return answer={a,b,c,d};
}