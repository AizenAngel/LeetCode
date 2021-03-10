#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height){

    int size = height.size();

    if(!size)
        return 0; 

    
    std::vector<int> left_max(size);
    std::vector<int> right_max(size);

    left_max[0] = height[0];

    for(int i = 1; i < size; i++){
        left_max[i] = max(left_max[i-1], height[i]);
    }

    right_max[size - 1] = height[size - 1];

    for(int i = size - 2; i >= 0; i--){
        right_max[i] = max(height[i], right_max[i + 1]);
    }

    int ans = 0;

    for(int i = 0; i < size; i++){
        ans += min(right_max[i], left_max[i]) - height[i];
    }

    return ans;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin>>n;
    std::vector<int>height(n);

    for(int i = 0; i < n; i++){
        std::cin>>height[i];
    }

    std::cout<<trap(height)<<"\n";

    return 0;
}