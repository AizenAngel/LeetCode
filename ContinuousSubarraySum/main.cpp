#include <bits/stdc++.h>
using namespace std;

    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            if((mp[sum % k] != 0 && i - mp[sum%k] + 1 > 1) || (i > 0 && sum % k == 0))
                return true;
            
            else if(mp[sum % k] == 0)
                mp[sum%k] = i + 1;
        }
        
        return false;
    }

int main(){



    return 0;
}