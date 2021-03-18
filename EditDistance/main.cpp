#include <bits/stdc++.h>
using namespace std;

int min_distance(string word1, string word2){
    int n = word1.size();
    int m = word2.size();

    /*
    We're going to solve it using matrix dp.
    dp[i][j] contains minimum number of operations, required to make word1[0...i - 1] and word2[0...j - 1] equal.
    Now, if both strings are empty, we don't need to make any operation to make them equal - because they
    already are.
    So dp[0][0] = 0

    If one of there words is empty, and other has letters, we can
    1) insert all the letters of non-empty word to empty word or
    2) delete all letter of non-empty word.

    Either one of these operations asks for n operations, where n is the length of non-empty word.
    This is why we need 2 for loops before main part of the program. 
    */

    vector<vector<int>> dp(n + 1);
    for(int i = 0; i <= n; i++){
        dp[i].resize(m + 1, 0);
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i][0] = i;
    }

    for(int i = 1; i <= m; i++)
        dp[0][i] = i;

    /*
    Now, inside double for loop, both indexes start from 1, bacause cases where i == 0 and j == 0 are
    already explained.

    In further text, i will use (i - 1) and (j - 1) to access indexes of word1 and word2 (because i and j
    start from 1 and we need to start from 0)

    Now, we have 2 cases:
    
    a) word1[i - 1] == word2[j - 1] - it means these 2 letters are matched. So how many operations
       do we need to match "these two words"? Well we can think about removing these two last letters
       and then checking how to make rest of the strings equal.
       For example, imagine we need to match words: "ana" and "a".
       Since last letters of the words are equal, we can remove them and try to match strings
       "an" and "". This requires 2 operations, so the answer here is 2.
       And we do this in our code by saying 
        
        if(word1[i - 1] == word2[j - 1]){
            dp[i][j] = dp[i-1][j-1];
        }

        It means: "The number of operations to match word1[0..i-1] and word2[0..j-1] is the same as the
        number of operations to match word1[0...i-2] and word2[j..j-2]."

    b) If word1[i-1] != word2[j-1] - here things get a bit more complicated, bacause by problem's statement
       we have 3 choices:
       a) we can remove a letter
       b) make one letter equal to other
       c) insert a letter 

       Main question is, in which one of the strings should these operations be made?
       Answer lies in matrix dp and already visited indexes.

       dp[i][j] - is what we want to find
       dp[i-1][j] - contains  number of operations needed to match word1[0...i-2] and word2[0...j-1]
       dp[i][j-1] - contains  number of operations needed to match word1[0...i-1] and word2[0...j-2] 
       dp[i-1][j-1] - contains  number of operations needed to match word1[0...i-2] and word2[0...j-2] 
    
       So if we need to remove letter (i) from string word1 and try to match it with word2,
       number of operations needed is dp[i-1][j] + 1 (1 for removing letter (i) in string word1 and dp[i-1][j] for matching word1[0..i-2] and word2[0..j-1])  

       Similar thing goes if we want to remove letter in word2 on position j.

       If we make letters on position (i) in word1 and position (j) in word2 equal, or if we
       insert word2[j] on position (i) in word1 or if we insert word1[i] on position (j) in word2,
       it takes 1 + dp[i-1][j-1] operations.

       That's why we need to find minimum of (dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) and increase it by 1
    */

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i-1][j-1] + 1, dp[i][j-1] + 1));
            }
        }
    }

    return dp[n][m];
}

int main(int argc, char** argv){
    string word1 = "intention";
    string word2 = "execution";

    cout<<min_distance(word1, word2)<<"\n";


    return 0;
}