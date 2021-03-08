#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>

int jump(std::vector<int>& nums) {

    if (n == 1)
        return 0;

    int n = nums.size();
    int max_reachable_index = nums[0];
    int limit = nums[0];

    int min_jumps = 1;

    for(int i = 1; i < n; i++){

        if(i  > limit){
            min_jumps++;
            limit = max_reachable_index;
        }
        

        max_reachable_index = std::max(max_reachable_index, i + nums[i]);
    }

    return min_jumps;
}

int main(int argc, char** argv){

    int n;
    std::cin>>n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    
    std::cout<<jump(arr)<<"\n";

    return 0;
}