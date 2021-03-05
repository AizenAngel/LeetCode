// https://leetcode.com/discuss/interview-question/364618/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

int main(int argc, char** argv){

    int n;
    std::cin>>n;
    std::vector<int> a(n); 

    for(int i = 0; i < n; i++)
        std::cin>>a[i];
    
    std::sort(a.begin(), a.end(), [](auto p1, auto p2){
        return p1 > p2;
    });

    // std::copy(
    //     a.begin(),
    //     a.end(),
    //     std::ostream_iterator<int>(std::cout, " ")
    // );

    int sum = 0;

    for(int i = 0; i < n - 1; i++){
        sum += (i + 1) * ( a[i] > a[i + 1] ? 1 : 0);
    }    

    std::cout<<sum<<"\n";

    return 0;
}
