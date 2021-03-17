// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vector<vector<int>> paths(n);
    for(int i = 0; i < n; i++)
        paths[i].resize(m);

    paths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

    for(int i = 1; i < m; i++){
        paths[0][i] = obstacleGrid[0][i] == 0 ? paths[0][i - 1] : 0;
        
    }
        
    
    for(int i = 1; i < n; i++)
        paths[i][0] = obstacleGrid[i][0] == 0 ? paths[i - 1][0]: 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(obstacleGrid[i][j] == 1)
                continue;
            
            int above = obstacleGrid[i-1][j] == 1 ? 0 : paths[i-1][j];
            int left = obstacleGrid[i][j-1] == 1 ? 0 : paths[i][j-1];
        
            paths[i][j] = above + left;
        }
    }    

    return paths[n-1][m-1];
}
// {{0,0,0},{0,1,0},{0,0,0}}
int main(){
    vector<vector<int>>obstacleGrid = {{0, 1}};
    cout<<uniquePathsWithObstacles(obstacleGrid)<<"\n";

    return 0;
}