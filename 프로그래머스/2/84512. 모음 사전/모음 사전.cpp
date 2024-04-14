#include <bits/stdc++.h>

using namespace std;
vector<char> w;
set<string> ss;
vector<string> v;
int arr[6]; //조합용 인덱스
int cnt;

void dfs(int k,string s){
    if(k==5){
        //cout<<s<<"\n";
        ss.insert(s);
        return;
    }
    dfs(k+1,s);
    dfs(k+1,s+"A");
    dfs(k+1,s+"E");
    dfs(k+1,s+"I");
    dfs(k+1,s+"O");
    dfs(k+1,s+"U");
}
//n(6)개 중 k(5)개를 뽑음, 중복조합
void comb(int k){
    if(k==5){
        cnt++;
        string tmp="";
        for(int i=0;i<5;++i){
            cout<<arr[i]<<" ";
            if(arr[i]==0){
                //pass
            }
            if(arr[i]==1){
                tmp+="A";
            }
            if(arr[i]==2){
                tmp+="E";
            }
            if(arr[i]==3){
                tmp+="I";
            }
            if(arr[i]==4){
                tmp+="O";
            }
            if(arr[i]==5){
                tmp+="U";
            }
        }
        //cout<<tmp<<"\n";
        v.push_back(tmp);
        cout<<"\n";
        return;
    }
    int st=0;
    if(k!=0) st=arr[k-1];
    for(int i=st;i<6;++i){
        arr[k]=i;
        comb(k+1);
    }
}
int solution(string word) {
    int answer = 0;
    //comb(0);
    dfs(0,"");
    //cout<<v.size()<<"\n";
    //cout<<cnt;
    for(auto s : ss) v.push_back(s);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        //cout<<v[i]<<"\n";
        if(v[i]==word){
            answer=i;
            ///break;
        }
    }
    
    
    return answer;
}