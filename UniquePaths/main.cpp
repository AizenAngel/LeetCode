// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    // matrix represents possible ways to reach every point on the map.
    vector<vector<int>> paths(m);

    for(int i = 0; i < paths.size(); i++)
        paths[i].resize(n);
    
    /* 
        We can move just down or right. So if we are on 0th column,
        we can only move right (bacause no tile is above it),
        so we can reach it on only one way - by going right.

        For example, consider the following matrix. 

        S - - - - - F - -
        - - - - - - - - -
        - - - - - - - - - 

        On how many ways could we reach point F starting from point S
        with only possible movement being down and right?
        Thats's right, we can only move right, so only possible way is:

        S X X X X X F - -
        - - - - - - - - -
        - - - - - - - - - 

        Same intuition goes if F is in the same column like S.
        Thats why we say paths[i][0] = 1, for every i from (0, m),
        and points[0][i] = 1, for every i from (0, m).
        Bacause there is only one way to reach them.
    */

    for(int i = 0; i < n; i++){
        paths[0][i] = 1;
    }

    for(int i = 0; i < m; i++){
        paths[i][0] = 1;
    }

    /*
    
    If i != 0 and j != 0, situation gets a bit complicated. But only a bit.

    S - - - - - - - -
    - - - - F - - - -
    - - - - - - - - -    

    Which points lead to point F in ONLY ONE jump?
    From problem statement, we can only move right and down, so 
    the points we need are 
    
    1) one point above
    2) one point left
    of the point F

    S - - - A - - - -
    - - - L F - - - -
    - - - - - - - - - 

    So all unique ways to reach point F, represent the sum of:
    1) all possible ways to reach point A
    2) all possible ways to reach point L

    And that's it!

    */

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++)
            paths[i][j] = paths[i-1][j] + paths[i][j-1];
    }

    return paths[m-1][n-1];
}

int main(){
    cout<<uniquePaths(3, 2)<<"\n";

    return 0;
}