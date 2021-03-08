#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>

int jump(std::vector<int>& nums) {
    int INF = -1;
    int n = nums.size();

    int jumps[31000];

    for(int i = 0; i < n; i++){
        jumps[i] = n + 1;
    }

    n--;

    jumps[n] = 0;

    for(int i = n-1; i >= 0; i--){

        int max_jump = (i + nums[i] > n ? n - i : nums[i]);

        for(int j = max_jump; j >= 1; j--){
            if(jumps[j + i] != INF){
                jumps[i] = ((jumps[j + i] + 1 )< jumps[i] ? (jumps[j+i] + 1) : jumps[i]);
            }
        }
    }

    // std::copy(
    //     std::begin(jumps),
    //     std::begin(jumps) + n,
    //     std::ostream_iterator<int>(std::cout, " ")
    // );

    return jumps[0];
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