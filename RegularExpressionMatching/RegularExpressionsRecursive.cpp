#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <string>

bool dp(std::string text, int i, std::string pattern, int j, std::vector<std::vector<int>>& memo){
    if(memo[i][j] != 2)
        return memo[i][j] == true;

    bool ans;

    if(j == pattern.size()){
        ans = i == pattern.size();
    }else{
        bool first_match = (i < text.size() &&
                           (text[i] == pattern[j] || pattern[j] == '.'));
        
        if(j + 1 < pattern.size() && pattern[j + 1] == '*')
            ans = dp(text, i, pattern, j + 2, memo) || first_match && dp(text, i+1, pattern, j, memo);
        else
            ans = first_match && dp(text, i + 1, pattern, j + 1, memo);
    }
    
    memo[i][j] = ans;
    return ans;
}

bool isMatch(std::string text, std::string pattern){
    int text_size = text.size();
    int pattern_size = pattern.size();

    std::vector<std::vector<int>> memo(text_size + 1);
    for(int i = 0; i <= text_size; i++)
        memo[i].resize(pattern_size + 1, 2);

    bool ans =  dp(text, 0, pattern, 0, memo);

    // for(int i = 0; i <= text_size; i++){
    //     for(int j = 0; j <= pattern_size; j++){
    //         std::cout << memo[i][j] <<" ";
    //     }
    //     std::cout<<"\n";
    // }

    // std::cout<<"\n";

    return ans;
}

int main(int argc, char** argv){
    // std::string text = "mississippi";
    // std::string pattern = "mis*is*ip*.";

    std::string text = "anaaaa";
    std::string pattern = "ana*";
    std::cout<<isMatch(text, pattern)<<"\n";
    
    return 0;
}