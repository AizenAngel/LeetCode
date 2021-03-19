// https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    


    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = (matrix[i][j] == '1' ? 1 : 0);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = (dp[i][j] != 0 ? dp[i][j-1] + dp[i][j] : 0);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<"\n";
    // }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int length = 201;

            for(int k = i; k >= 0 && dp[k][j] != 0; k--){
                length = min(length, dp[k][j]);
                int height = (i - k + 1);
                ans = max(ans, length * height);
            }
        }
    }

    return ans;
}

int main(){

    vector<vector<char>>matrix = {{'1','0','1','0','0'},
                                  {'1','0','1','1','1'},
                                  {'1','1','1','1','1'},
                                  {'1','0','0','1','0'}};

    cout<<maximalRectangle(matrix);

    return 0;
}