#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int m, n, a[1000004], ret[1000004];   
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    fill(&ret[0], &ret[1000004], -1);
    cin >> n ;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        while (s.size() && a[s.top()] < a[i])
        {
            ret[s.top()] = a[i];
            s.pop();
        }
        s.push(i);  //idx를 스택에 push하라.
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ret[i] << " ";
    }



    return 0;
}