#include <bits/stdc++.h>

int main(){

    int n;
    std::cin>>n;
    std::vector<int> arr(n);

    if(n % 2){
        for(int i = 0; i < n; i++)
            arr[i] = i - (n)/2;
    }else{
        int delta = 0;
        for(int i = -n/2; i <= n/2; i++){
            if(i == 0)
                continue;
             arr[delta++] = i;
        }
            
    }


    std::copy(
        arr.begin(),
        arr.end(),
        std::ostream_iterator<int>(std::cout, " ")
    );

    return 0;
}