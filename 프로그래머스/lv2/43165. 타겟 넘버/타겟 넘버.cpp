#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int>& numbers, int& target, int idx, int result){
    
    if(idx==numbers.size()){
        if(result==target){
            answer++;
        }
        return;
    }
    
    dfs(numbers,target,idx+1,result-numbers[idx]);
    dfs(numbers,target,idx+1,result+numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return answer;
}