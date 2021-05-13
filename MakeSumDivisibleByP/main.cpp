#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int minSubarray(vector<int>& a, int p){
    int n = a.size();
    int rem = 0;

    ll s = 0;

    for(int i = 0; i < n; i++){
        s += a[i];
    }

    rem = s % p;
    
    if(rem == 0)
        return 0;
    
    int rm = n;
    unordered_map<int, int> rems;
    
    s = 0;

    for(int i = 0; i < n; i++){
        s += a[i];
        int r = s % p;

        if(r == rem)
            rm = min(rm, i + 1);

        if (rems.find(r - rem) != rems.end())
            rm = min(rm, i - rems[r - rem]);

        if(rems.find(r - rem + p) != rems.end())
            rm = min(rm, i - rems[r - rem + p]);

        cout<<rm<<"\n";

        rems[r] = i;
    }

    if(rm >= n)
        return -1;
    
    return rm;
}

int main(){
    vector<int> arr = {3, 1, 4, 2};
    vector<int> arr_rem(arr.size());
    int n = arr.size();
    int p = 6;

    cout<<minSubarray(arr, p);

    return 0;
}