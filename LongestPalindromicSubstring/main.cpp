//https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <numeric>
#include <functional>
#include <string>
#include <vector>


std::string make_new_string(const std::string str){
    std::string new_string = "$";

    for(int i = 0; i < str.size(); i++){
        new_string += "#" + str.substr(i, 1);
    }

    new_string += "#@";
    return new_string;
}

std::string manacher(const std::string str){
    std::string new_str = make_new_string(str);

    std::vector<int>max_palindrome_vector(new_str.size(), 0);
    int c = 0, r = 0;

    for(int i = 1; i < new_str.size() -1; i++){
        int iMirror = c - (i - c);

        if (r > i){
            max_palindrome_vector[i] = std::min(r - i, max_palindrome_vector[iMirror]);
        }

        while(new_str[i + 1 + max_palindrome_vector[i]] == new_str[i - 1 - max_palindrome_vector[i]]){
            max_palindrome_vector[i]++;
        }

        if(i + max_palindrome_vector[i] > r){
            c = i;
            r = i + max_palindrome_vector[i];
        }

    }

    int max_palindrome = 0;
    int center_index = 0;

    for(int i = 0; i < max_palindrome_vector.size(); i++){
        if(max_palindrome_vector[i] > max_palindrome){
            max_palindrome = max_palindrome_vector[i];
            center_index = i;
        }
    }

    return str.substr((center_index - 1 - max_palindrome) / 2, max_palindrome);
}

int main(int argc, char** argv){

    std::cout<<manacher("milica")<<"\n";

    return 0;
}
