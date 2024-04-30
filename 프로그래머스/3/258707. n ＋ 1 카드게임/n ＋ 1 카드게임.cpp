#include <bits/stdc++.h>

using namespace std;

int ret, n, vis[1004]; //해당동전을 갖고있는지
//vector<int> v; //현재 갖고있는 숫자들
vector<int> cards;

//set 두쌍 안에서 두쌍의합이 n+1이 있는지
//있으면, 그 두 쌍 삭제
int check2(set<int>& s1, set<int>& s2){
    vector<int> v1,v2;
    for(auto i : s1) v1.push_back(i);
    sort(v1.begin(),v1.end());
    for(auto i : s2) v2.push_back(i);
    sort(v2.begin(),v2.end());
    
    for(int i=0;i<v1.size();++i){
        if(binary_search(v2.begin(),v2.end(),(n+1)-v1[i])){
            s1.erase(v1[i]);
            s2.erase(v2[lower_bound(v2.begin(),v2.end(),n+1-v1[i]) - v2.begin()]);
            return 1;
        }
    }
   return 0;
}
//set 안에서 두쌍의합이 n+1이 있는지
//있으면, 그 두 쌍 삭제
int check1(set<int>& s){
    vector<int> v;
    for(auto i : s) v.push_back(i);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        if(binary_search(v.begin(),v.end(),(n+1)-v[i])){
            s.erase(v[i]);
            s.erase(v[lower_bound(v.begin(),v.end(),n+1-v[i]) - v.begin()]);
            return 1;
        }
    }
   return 0;
}

//인덱스(n/3부터시작), 라운드, 남은코인
void dfs(int idx, int round , int coin){
    if(coin<0) return; //배제
    if(idx==n) return; //남은카드 없음
    //n+1이 되도록 카드를 못내는경우
    //if(check()) return;
    
    //둘다버림
    dfs(idx+2,round+1,coin);
    //1을가짐
    vis[cards[idx]]=1;
    dfs(idx+2,round+1,coin--);
    vis[cards[idx]]=0;
    //2를가짐
    vis[cards[idx+1]]=1;
    dfs(idx+2,round+1,coin=coin-1);
    vis[cards[idx+1]]=0;
    //둘다가짐
    vis[cards[idx]]=1;
    vis[cards[idx+1]]=1;
    dfs(idx+2,round+1,coin=coin-2);
    vis[cards[idx]]=0;
    vis[cards[idx+1]]=0;
}
int solution(int coin, vector<int> _cards) {
    n=_cards.size();
    cards=_cards;
    
    set<int> mycard;
    deque<int> remain;
    set<int> avail;

    for(int i=0;i<n;++i){
        if(i<n/3) mycard.insert(cards[i]);
        else remain.push_back(cards[i]);
    }
    
    
    ret=1;
    //1라진행
    while(1){
        if(remain.size()==0) break;
        int a,b;
        a=remain.front();
        remain.pop_front();
        b=remain.front();
        remain.pop_front();
        avail.insert(a);
        avail.insert(b);
        
        // for(auto i : mycard) cout<<i<<" "; cout<<"\n";
        // for(auto i : remain) cout<<i<<" "; cout<<"\n";
        // for(auto i : avail) cout<<i<<" "; cout<<"\n";
        // cout<<"\n";
        
        if(check1(mycard)){
            ret++;
            continue;
        }
        if(check2(mycard,avail) && coin>=1){
            ret++;
            coin-=1;
            continue;
        }
        if(check1(avail) && coin>=2){
            ret++;
            coin-=2;
            continue;
        }
        break;
    }
    
    
    
    
    
    return ret;
}