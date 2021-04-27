#include <bits/stdc++.h>
using namespace std;

// [5, 7, 1, 8] true
// [4, 2, 3] true
// [3, 4, 2, 3] false 

bool checkPossibility(vector<int>& nums) {

    int count = 0;
    int max_so_far = nums[0];
    int n = nums.size();


    for(int i = 0; i < n - 1; i++){

        if(nums[i] > nums[i + 1]){
            count++;
            if(count == 2)
                return false;
            
            if (i < n - 2) {
                if(nums[i] >= nums[i + 2]){
                    nums[i] = nums[i+1];
                }else{
                    nums[i+1] = nums[i];
                }
            }else{
                nums[i+1] = nums[i];
            }
        
            i--;
        }
    }
    
    for(int i = 0; i < n - 1; i++){
        if(nums[i] > nums[i + 1])
            return false;
    }

    return true;
}

int main(int argc, char** argv){

    std::vector<int> test = {4, 2, 3};

    cout<<checkPossibility(test)<<"\n";

    return 0;
}