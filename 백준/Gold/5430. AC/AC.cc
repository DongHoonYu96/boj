#include<bits/stdc++.h>
using namespace std;

int t,n;
deque<int> d;

void printD(deque<string> d){
	for (auto i : d) {
		cout << i << " ";
	}
	cout << "\n";

}
void parse(string& tmp, deque<int>& d) {
	int cur = 0;
	for (int i = 1; i + 1 < tmp.size(); i++)
	{
		if (tmp[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if (cur != 0)
		d.push_back(cur);
}
//split : O(n)
vector<string> split(string& input, string deli) {
	long long pos = 0;
	string token = "";
	vector<string> ret;

	//1. 구분자가 있는 위치찾기
	while ((pos = input.find(deli)) != string::npos) {
		//1-1. 문자열자르기, 넣기, 자른문자열 지우기
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + deli.length());
	}

	//마지막 남은 문자열 넣기
	ret.push_back(input);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		d.clear();
		bool is_front = true;
		string ret="", arr = "";
		string p = "";
		cin >> p;
		cin >> n;
		cin >> arr;

		//예외처리
		//입력이 []이고, D명령이 있는경우 -> error
		//입력이 []이고, D명령이 없는경우 ->[]
		if (arr == "[]") {
			if (p.find("D") != string::npos) {
				cout << "error\n";
				continue;
			}
			else {
				cout << "[]\n";
				continue;
			}
			
		};

		//O(n) 최악 : 10만
		//arr = arr.substr(1, arr.size()-2);
		//cout << "arr: " << arr << "\n";

		//최악 : O(n) : 10만
		//vector<string> nums;
		//nums = split(arr, ",");

		//최악 : O(n) : 10만
		/*for (auto s : nums) {
			d.push_back(s);
		}*/
		
		//해결 : O(n):10만
		parse(arr, d);

		bool is_empty = false;
		int size_p = p.size();
		//최악 : O(n) : 10만 
		for (int i = 0; i < size_p; ++i) {
			if (p[i] == 'R') {
				is_front = !is_front;
			}
			else if (p[i] == 'D') {//"버리는" 함수
				/*cout << "데큐 : ";
				printD(d);
				cout << " size:" << d.size();*/
				if (d.empty()) {
					cout << "error\n";
					is_empty = true;
					break;
				}
				else {
					if (is_front) {
						d.pop_front();
					}
					else {
						d.pop_back();
					}
				}
			}
		}
		if (is_empty) continue;
		//if (d.empty()) continue;
		
		if (is_front) {
			//최악 : O(n) : 10만
			for (auto s : d) {
				ret += to_string(s);
				ret += ",";
			}
			ret = ret.substr(0, ret.size() - 1);
			ret = "[" + ret;
			ret += "]";
		}
		else {
			while (d.size()) {
				ret += to_string(d.back());
				d.pop_back();
				ret += ",";
			}
			ret = ret.substr(0, ret.size() - 1);
			ret = "[" + ret;
			ret += "]";
		}
		cout << ret << "\n";
	}

}