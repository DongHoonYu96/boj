#include <bits/stdc++.h>

using namespace std;
vector<int> arrA,arrB;
vector<vector<int>> dice;
int n;
int maxA, vis[6];

void go(int depth, int val, vector<int> &idxs){
    cout<<depth<<" "<<val<<"\n";
    if(depth==n/2){
        arrA.push_back(val);
        return;
    }
    
    for(int i=0;i<6;++i){
        if(vis[i]) continue;
        vis[i]=1;
        go(depth+1,val+dice[idxs[depth]][i],idxs);
        vis[i]=0;
    }
}

void go2(int depth, int val, vector<int> &idxs){
    if(depth==n/2){
        arrB.push_back(val);
        return;
    }
    
    for(auto idx : idxs){
        for(int i=0;i<6;++i){
            go(depth+1,val+dice[idx][i],idxs);
        }
        
    }
}

vector<int> solution(vector<vector<int>> _dice) {
    dice=_dice;
    vector<int> answer;
    n=dice.size();
    vector<int> v;
    for(int i=0;i<n/2;++i) v.push_back(0);
    for(int i=0;i<n/2;++i) v.push_back(1);
    
    //1. A가 가져갈 주사위 선택하기(1)
    //1 1 0 0
    do{
        vector<int> a,b;
        for(int i=0;i<n;++i){
            if(v[i])
                a.push_back(i); //a가가져갈 주사위의 인덱스저장
            else
                b.push_back(i); //b가가져갈 주사위의 인덱스저장
        }
        
        arrA.clear();
        arrB.clear();
        go(0,0,a);
        go2(0,0,b);
        
        sort(arrA.begin(),arrA.end());
        sort(arrB.begin(),arrB.end());
        
        //for(auto i : arrA) cout<<i<<" ";
        //cout<<"\n";
        
        int winA=0;
        for(auto i : arrA){
            winA+=(arrB.end()-lower_bound(arrB.begin(),arrB.end(),i));
            //cout<<winA<<"\n";
        }
        if(winA>maxA){
            answer.clear();
            for(auto i : a){
                answer.push_back(i+1);
            }
            maxA=winA;
        }
    }while(next_permutation(v.begin(),v.end()));
    
    
    //2. 가져간 주사위를 굴린 부분 계산
    return answer;
}