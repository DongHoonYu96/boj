#include <bits/stdc++.h>

using namespace std;
int n,arr[11],vis[11],mx;
unordered_set<int> s;
vector<vector<int>> dice;
vector<int> arrA,arrB;
vector<int> answer;

//a의 각원소에대해
//b보다 큰 갯수 == A의 승리갯수
int go2(vector<int>& a, vector<int>& b){
    int ret=0;
    sort(b.begin(),b.end()); //이분탐색은 정렬후 사용!
    for(auto i : a){
        int idx= lower_bound(b.begin(),b.end(),i)-b.begin();
        ret+=idx;
    }
    return ret;
}

//dp : 메모리를 이용해서 시간복잡도 줄이기!
//a,b의 idx를 가지고 합배열만들기
//그때 a의 승리수 리턴
void dfs(vector<int>& a, vector<int>& b, int depth, int sum1,int sum2){
    if(depth==a.size()){
        arrA.push_back(sum1);
        arrB.push_back(sum2);
        return ;
    }
    
    for(int i=0;i<6;++i){
        dfs(a,b,depth+1,sum1+dice[a[depth]][i],sum2+dice[b[depth]][i]);
    }
    
    
}

//현재까지 k 개뽑음
void go(int k){
    if(k==n/2){
        vector<int> a,b; //a,b가 고른 주사위의 인덱스
        for(int i=0;i<n;++i) s.insert(i);
        for(int i=0;i<n/2;++i){
            a.push_back(arr[i]);
            s.erase(arr[i]);
            //cout<<arr[i]<<" ";
        }
        for(auto i : s){
            b.push_back(i);
        }
        // cout<<"a: "; for(auto i : a) cout<<i<<" "; cout<<"\n";
        // cout<<"b: "; for(auto i : b) cout<<i<<" ";
        // cout<<"------------------\n";
        
        arrA.clear();
        arrB.clear();
        dfs(a,b,0,0,0);
        
        //이분탐색
        int cnt = go2(arrA,arrB);
        if(cnt>=mx){ //a의 승률이 큰경우 발견
            mx=cnt;
            answer.clear();
            for(int i : a){
                answer.push_back(i+1); //1-idx로 만듬
            }
        }
        
        
        return;
    }
    
    
    int st=0;
    if(k!=0) st=arr[k-1];
    for(int i=st;i<n;++i){
        if(vis[i]) continue;
        vis[i]=1;
        arr[k]=i;
        go(k+1);
        vis[i]=0;
    }
}
vector<int> solution(vector<vector<int>> _dice) {

    dice=_dice;
    n=dice.size();
    for(int i=0;i<n;++i) s.insert(i);
    go(0);
    return answer;
}