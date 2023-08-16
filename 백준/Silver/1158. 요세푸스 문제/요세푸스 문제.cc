#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
int main() 
{
	int n, k;	//1~n개, k개지나면아웃
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}//입력끝

	int cnt = 1;
	cout << "<";
	while (!q.empty())
	{
		int a = q.front();	//값 임시저장
		q.pop();

		if (cnt == k)	//k번째가 되면 아웃
		{
			if (q.size() == 0)
				cout<<a<<">";
			else
				cout << a<<", ";

			cnt = 1;
		}
		//k번째가아니면 다시 뒤로넣어
		else
		{
			cnt++;
			q.push(a);
		}
		
	}
	//cout << ">";
    
}
