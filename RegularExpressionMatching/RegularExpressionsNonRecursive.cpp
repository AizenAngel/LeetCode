#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <string>

bool dp(std::string text, std::string pattern){

    int text_size = text.size();
    int pattern_size = pattern.size();

    std::vector<std::vector<bool>> dp(text_size + 1);
    for(int i = 0; i <= text_size; i++)
        dp[i].resize(pattern_size + 1, false);

    dp[text_size][pattern_size] = true;

    for(int i = text_size; i >= 0; i--){
        for(int j = pattern_size - 1; j >= 0; j--){

            bool first_match = (i < text_size &&
                               (pattern[j] == text[i] || pattern[j] == '.'));

            if(j + 1 < pattern_size && pattern[j+1] == '*'){
                dp[i][j] = dp[i][j + 2] || (first_match && dp[i+1][j]);  
            }else{
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }

        }
    }

    for(int i = 0; i <= text_size; i++){
        std::cout<<"\n";
        for(int j = 0; j <= pattern_size; j++)
            std::cout<<dp[i][j]<<" ";
    }

    std::cout<<"\n";

    return dp[0][0];

}

int main(int argc, char** argv){
    std::string text = "mississippi";
    std::string pattern = "mis*is*p*.";

    std::cout<<dp(text, pattern)<<"\n";

    return 0;
}