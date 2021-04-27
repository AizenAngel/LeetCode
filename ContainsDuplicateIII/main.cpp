#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    multiset<long> ms;

    for(auto i = 0; i < nums.size(); i++){
        int minVal =  (long)nums[i] - (long)t;
        auto iter = ms.lower_bound(minVal);
        if(iter != ms.end() && *iter <= (long) nums[i] + (long)t)
            return true;
        
        ms.insert(nums[i]);
        if(ms.size() > k)
            ms.erase(ms.find(nums[i - k]));
    }

    return false;
}

int main(){


    return 0;
}