//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <iostream>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
#include <tuple>

int main(int argc, char** argv){
    std::set<int> solution;
    std::unordered_map<char, int> char_map;
    std::string input;

    std::cin>>input;
    
    for(auto it: input){
        auto find_char = char_map.find(it);

        if(find_char == char_map.end()){
            char_map.insert({it, 1});
        }else{
            find_char->second++;
        }
    }

    int count = 0;

    for(auto it : char_map) {
        int value = it.second;

        while(solution.find(value) != solution.end()){
            value--;
            count++;
            if(value == 0)
                break;
        }

        if(value != 0)
            solution.insert(value);
    }

    return 0;
}