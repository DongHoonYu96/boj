#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,double>> vec; //idx , v*w

bool cmp(pair<int,double> p1, pair<int,double> p2){
	if(p1.second==p2.second){ //가격이 같다면
		return p1.first<p2.first; //회사번호 작은순
	}
	return p1.second>p2.second; //가격큰순
}
int main() {
	char input[100];
	cin >> n;
	for(int i=0;i<n;++i){
		double v,w,tmp;
		cin>>v>>w;
		tmp=v*w*10;
		tmp=floor(tmp);
		vec.push_back({i+1,tmp});
	}
	sort(vec.begin(),vec.end(),cmp);
	
	for(auto p : vec){
		cout<<p.first<<" ";
		//cout<<p.first<<" "<<p.second<<"\n";
	}
	return 0;
}