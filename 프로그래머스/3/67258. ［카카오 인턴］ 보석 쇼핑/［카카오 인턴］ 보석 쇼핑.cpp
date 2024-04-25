#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
set<string> se1,se2; //원본유일문자열개수, 현재유일문자열갯수
int min_dist=987654321;
vector<pair<int,int>> ans; //정답후보들
int limit; //유일문자열의 갯수, curmap.size()가 이거이상이면 조건만족

//1. 거리짧은것 우선
//2. 거리가같으면, s가작은것 우선
bool cmp(pair<int,int> p1, pair<int,int> p2){
    int dist1=p1.second-p1.first;
    int dist2=p2.second-p2.first;
    if(dist1==dist2){
        return p1.first<p2.first;
    }
    return dist1<dist2;
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    for(auto s:gems){
        se1.insert(s);
        //m1[s]++;
    }
    limit=se1.size();
    
    int s=0, e=0;
    m[gems[s]]++; //초기값
    while(1){
        //탈출조건 : e가끝에도달 and 조건불만족
        if(e==gems.size()-1 && m.size()!=limit) break;
        
        //조건불만족하는경우, e를 +시킴(범위체크 필수!, +시키기전 갱신필수!)
        if(m.size()!=limit){
            if(e==gems.size()-1) continue; //범위쳌
            e++;
            m[gems[e]]++;
        }
        //조건만족하는경우, 정답에넣고, s를+ 시킴(+시키기전에 m 갱신해야함)
        else{
            ans.push_back({s,e});
            m[gems[s]]--; //s+1전 갱신
            
            if(m[gems[s]]==0){ //갱신했는데 0개남은경우 map에서 제거!
                m.erase(gems[s]);
            }
            s++;
        }
    }
    
    sort(ans.begin(),ans.end(),cmp);
    // for(auto p : ans){
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }
    answer={ans[0].first+1,ans[0].second+1};
    return answer;
}