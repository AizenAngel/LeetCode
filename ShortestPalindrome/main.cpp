//https://leetcode.com/problems/shortest-palindrome/

#include <iostream>
#include <numeric>
#include <functional>
#include <iterator>
#include <vector>

std::vector<int> KMP(std::string str){
    std::vector<int> kmp_arr(str.size(), 0);

    for(int i = 1; i < str.size(); i++){
        int index = kmp_arr[i-1];

        while(index > 0 && str[i] != str[index])
            index = kmp_arr[index-1];
        
        if(str[i] == str[index])
            index++;
        
        kmp_arr[i] = index;
    }

    return kmp_arr;
}

std::string minimal_string(std::string str){
    std::string str_rev(str);
    std::reverse(str_rev.begin(), str_rev.end());
    std::string str_new = str + "#" + str_rev;
    std::vector<int> arr = KMP(str_new);

    int n = str.size();
    int n_new = str_new.size();

    return str_rev.substr(0, n - arr[n_new-1]) + str;
}

int main(int argc, char** argv){
    std::string str = "aacecaaa";
    std::string palindrome = minimal_string(str);

    std::copy(
        palindrome.begin(),
        palindrome.end(),
        std::ostream_iterator<char>(std::cout)
    );

    return 0;
}
