//https://leetcode.com/problems/wildcard-matching/

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <numeric>

bool is_match(char match_ch, char pattern_ch){
    return match_ch == (pattern_ch) || (pattern_ch == '*') || (pattern_ch == '?');
}

bool dp(std::string text, int i, std::string pattern, int j, std::vector<std::vector<int>>& memo){

    if(i > text.size()){
        return false;
    }

    if(j < pattern.size() && memo[i][j] != 2)
        return memo[i][j];

    int ans;

    if(j == pattern.size())
        ans = i == text.size();

    else{
        if(pattern[j] == '*') {
            ans = dp(text, i + 1, pattern, j, memo) || 
                  dp(text, i, pattern, j + 1, memo);
        } else if (pattern[j] == '?') {
            ans = dp(text, i, pattern, j + 1, memo) || 
                  dp(text, i + 1, pattern, j + 1, memo);
        } else {
            ans = (pattern[j] == text[i]) && (dp(text, i + 1, pattern, j + 1, memo));
        }
    }

    memo[i][j] = ans;

    //std::cout<<i<<" "<<j<<" "<<ans<<"\n";

    return ans;
}

bool isMatch(std::string text, std::string pattern){

    int text_size = text.size();
    int pattern_size = pattern.size();

    std::vector<std::vector<int>> memo(text_size + 1);
    for(int i = 0; i <= text_size; i++)
        memo[i].resize(pattern_size + 1, 2);

    bool res = dp(text, 0, pattern, 0, memo);

    std::cout<<"  ";

    // for(int i = 0; i < pattern.size(); i++)
    //     std::cout<<pattern[i]<<" ";

    // for(int i = 0; i < memo.size(); i++){
    //     std::cout<<"\n";
    //     i < text.size() ? std::cout<<text[i]<<" " : std::cout<<"  ";
    //     for(int j = 0; j < memo[0].size(); j++)
    //         std::cout<<memo[i][j]<<" ";
    // }
    // std::cout<<"\n";

    return res;
}

int main(int argc, char** argv){

    std::string text    = "acdcb";
    std::string pattern = "a*c?b";

    std::cout<<isMatch(text, pattern)<<"\n";

    return 0;
}
