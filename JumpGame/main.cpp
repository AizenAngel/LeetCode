#include <numeric>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

bool attempt_to_jump_to_last(std::vector<int>& a){

    std::vector<int> visited(a.size(), -1);
    visited[visited.size() - 1] = 1;

    int n = a.size() - 1;

    for(int i = n - 1; i >= 0; i--){
        int max_jump = (i + a[i] > n ? n - i : a[i]);

        for(int j = max_jump; j >= 1; j--){
            if (visited[i + j] == 1){
                visited[i] = 1;
                break;
            }
        }
    }

    return visited[0] == 1;
}

int main(int argc, char** argv){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<int> visited(n, -1);

    for(int i = 0; i < n; i++)
        std::cin>>a[i];

    std::cout<<attempt_to_jump_to_last(a)<<"\n";

    return 0;
}