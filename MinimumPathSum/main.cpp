// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> min_sum(n);

    for(int i = 0; i < n; i++){
        min_sum[i].resize(m);
    }    

    min_sum[0][0] = grid[0][0];

    for(int i = 1; i < n; i++){
        min_sum[i][0] = min_sum[i - 1][0] + grid[i][0];
    }

    for(int i = 1; i < m; i++){
        min_sum[0][i] = min_sum[0][i - 1] + grid[0][i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            min_sum[i][j] = grid[i][j] + min(min_sum[i-1][j], min_sum[i][j-1]);
        }
    }

    return min_sum[n-1][m-1];
}

int main(){

    //vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};

    cout<<minPathSum(grid)<<"\n";

    return 0;
}