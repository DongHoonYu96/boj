#include <bits/stdc++.h>

using namespace std;

int arr[200004];

int solution(vector<int> nums)
{
    for(auto i : nums){
        arr[i]++;
    }
    
    int count=0;
    for(auto i : arr){
        if(i!=0) count++;
    }
    
    //cout<<"count: "<<count<<"\n";
    //cout<<"size: "<<nums.size()<<"\n";
    if(count<nums.size()/2){
        return count;
    }
    else{
        return nums.size()/2;
    }
}