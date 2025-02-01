#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    int cnt = 0;
    vector<int> a(K);
    unordered_set<int> plugged;
    
    for(int i = 0; i < K; i++) cin >> a[i];
    
    for(int i = 0; i < K; i++) {
        int current = a[i];
        
        if(plugged.find(current) != plugged.end()) continue;
        
        if(plugged.size() < N) {
            plugged.insert(current);
            continue;
        }
        
        int latest = -1;
        int latest_idx = -1;
        
        for(auto plug : plugged) {
            int next_use = K;
            
            for(int j = i + 1; j < K; j++) {
                if(a[j] == plug) {
                    next_use = j;
                    break;
                }
            }
            
            if(next_use > latest_idx) {
                latest_idx = next_use;
                latest = plug;
            }
        }
        
        plugged.erase(latest);
        plugged.insert(current);
        cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}