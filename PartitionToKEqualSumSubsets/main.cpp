#include <bits/stdc++.h>

bool find_sums(std::vector<int>& groups, int end, std::vector<int> nums, int target){
    
    if(end < 0)
        return true;
    
    int v = nums[end--];

    for(int i = 0; i < groups.size(); i++){
        if(groups[i] + v <= target){
            groups[i] += v;
            if(find_sums(groups, end, nums, target))
                return true;
            groups[i] -= v;
        }
        if(groups[i] == 0) break;
    }
    return false;
}

int main(int argc, char** argv){

    int n, k;
    std::cin>>n>>k;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++)
        std::cin>>arr[i];

    int sum = std::accumulate(arr.begin(), 
                              arr.end(), 
                              0, 
                              [](int acc, const int el){
                                  return acc + el;
                              });

    if(sum % k){
        return false;
    }

    int target = sum / k;

    sort(arr.begin(), arr.end(), [](const auto &it1, const auto &it2){
        return it1 < it2;
    });

    n = arr.size() - 1;
    
    if(arr[n] > target){
        return false;
    }
            
    while(n >= 0 && arr[n] == target){
        n--;
        k--;
    }

    std::vector<int> groups(k, 0);

    std::cout<<find_sums(groups, n, arr, target)<<"\n";

    return 0;
}