#include <bits/stdc++.h>
using namespace std;

pair<int, int> maxSubArray(vector<int>& a){
    int ans = a[0];
    int prev = a[0];

    for(int i = 1; i < a.size(); i++){
        prev = max(prev + a[i], a[i]);
        ans = max(ans, prev);
    }

    return {prev, ans};
}

int kConcatenationMaxSum(vector<int>&a, int k) {
    int M = 1000000007;
    auto res = maxSubArray(a);
    int prev = res.first;
    int ans = res.second;

    if(prev <= 0 || k == 1)
        return max(ans,0);

    int prev_prev = prev;
    int prev_ans = ans;
    a[0] += prev;
    res = maxSubArray(a);
    prev=res.first;
    ans=res.second;
    if(prev_prev == prev)
        return max(prev_ans, max(ans, 0));

    int increase = ans - prev_ans;

    return (prev_ans%M+(((long long)k-1)*(increase))%M)%M; 
}

int main(){
    vector<int> a = {1, 2};
    int k = 3;

    cout<<kConcatenationMaxSum(a, k)<<"\n";

    return 0;
}