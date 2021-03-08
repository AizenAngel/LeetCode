#include <bits/stdc++.h>

bool attempt_to_jump_to_last(std::vector<int>& a, int** visited, int start){
    if((*visited)[start] != -1)
        return (*visited)[start] == 1;

    int n = a.size() - 1;

    int max_jump = (start + a[start] > n ? n : start + a[start]);

    for(int i = start + 1; i <= max_jump; i++){
        if(attempt_to_jump_to_last(a, visited, i)){
            (*visited)[start] = 1;
            return true;
        }
    }

    (*visited)[start] = 0;
    return false;
}

int main(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    int* visited = new int[n];

    for(int i = 0; i < n; i++)
        visited[i] = -1;

    for(int i = 0; i < n; i++)
        std::cin>>a[i];

    visited[n-1] = 1;

    std::cout<<attempt_to_jump_to_last(a, &visited, 0)<<"\n";

    for(int i = 0; i < a.size(); i++)
        std::cout<<visited[i]<<" ";

    return 0;
}

/*
5
4 3 2 1 5
*/