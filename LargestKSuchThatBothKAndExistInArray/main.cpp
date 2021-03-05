// https://leetcode.com/discuss/interview-question/406031/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <cmath>

int get_largest_k_that_both_k_and_minus_k_exist_in_array(std::vector<int> arr){

    std::sort(arr.begin(), 
              arr.end(),
              [](auto it1, auto it2){
                  return it1 < it2;
              });

    int start = 0, last = arr.size() - 1;

    while(start < last){
        if(abs(arr[start]) < abs(arr[last]))
            last--;
        if(abs(arr[start]) > abs(arr[last]))
            start;
        if(abs(arr[start]) == abs(arr[last]))
            break;
    } 

    if(start == last)
        return 0;
    
    return abs(arr[start]);

}

int main(int argc, char** argv){
    int n;
    std::cin>>n;
    std::vector<int> arr(n);

    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    
    std::cout<<get_largest_k_that_both_k_and_minus_k_exist_in_array(arr)<<"\n";

    return 0;
}