#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, n;

    cin>>n>>a>>b>>c;

    int base[3] = {a, b, c};
    int arr[3] = {a, b, c};
    int res = 0;
    
    sort(begin(arr), end(arr), [](const auto &it1, const auto &it2){
        return it1 < it2;
    });

    sort(begin(base), end(base), [](const auto &it1, const auto &it2){
        return it1 < it2;
    });

    int inc[3] = {base[1] / base[0], base[2]/ base[1], 1};

    int count = 0;

    while(count < n){
        int index = min_element(begin(arr), end(arr)) - begin(arr);

        cout<<count<<"\n";
        
        if(arr[index] == res){
            arr[index] += base[index];
            count++;
            res = arr[index];
        }

        res = arr[index];
        arr[index] += base[index] * min(inc[index], n - count);
        count += min(inc[index], n - count);
    }
    
    // for(int i = 0; i < 3; i++)
    //     cout<<arr[i]<<" ";

    cout<<"\n"<<res<<"\n";

    return 0;
}

/*
4
2
3
4
*/