#include <bits/stdc++.h>

using namespace std;

map<string, vector<int>> m;

void go(string str, int idx, vector<string>& ret){
    if(idx==4){
        //cout<<str<<"\n";
        m[str].push_back(stoi(ret[4]));
        //m[""].push_back(stoi(ret[4])); //- - - - 에도 넣어야함 -> 1회만 넣어야함
        return;
    }
    go(str+ret[idx],idx+1,ret);
    go(str,idx+1,ret);
}

vector<string> split(string input, string deli) {
	long long pos=0;
	vector<string> ret;
	string token = "";
	while ((pos=input.find(deli)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + deli.size());
	}
	//마지막 192.168.0.1 의 1저장
	ret.push_back(input);

	return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // m["hello java"].push_back(1);
    // m["hello java"].push_back(23);
    // for(auto i : m["hello java"]) cout<<i<<" ";
    
    for(auto i : info){
        vector<string> ret=split(i," ");
        go("",0,ret); //2^4가지 경우의수의 맵에 점수를 넣는함수
    }
    
    for(auto item : m){
        sort(m[item.first].begin(),m[item.first].end());
    }
 
    for(int i=0;i<query.size();++i){
        vector<string>ret=split(query[i]," ");
        string s="";
        if(ret[0]=="-"){
            //pass
        }
        else{
            s+=ret[0];
        }
        if(ret[2]=="-"){
            //pass
        }
        else{
            s+=ret[2];
        }
        if(ret[4]=="-"){
            //pass
        }
        else{
            s+=ret[4];
        }
        if(ret[6]=="-"){
            //pass
        }
        else{
            s+=ret[6];
        }
        answer.push_back(m[s].end()-lower_bound(m[s].begin(),m[s].end(),stoi(ret[7])));
    }
    
    return answer;
}