// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <iostream>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
#include <tuple>
#include <vector>
using namespace std;

int maxLen;

void checkCombination(vector<string> str, int index, string& res){

    if(maxLen < res.length())
        maxLen = res.size();

    if (index == str.size())
        return;

    for(int i = index; i < str.size(); i++){
        string temp = res + str[i];
        bool mask[27] = {false};

        for (char c: res)
            mask[c - 'a'] = true;

        bool unique_chars = true;

        for(char ch : str[i]){
            if(mask[ch - 'a']){
                unique_chars = false;
                break;
            }
            mask[ch - 'a'] = true;
        }

        if(unique_chars){
            checkCombination(str, i + 1, temp);
        }
    }
}

int maxLength(vector<string>& str){
    string res;
    checkCombination(str, 0, res);

    return maxLen;
}


int main(){
    vector<string> str = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};

    
    std::cout<<maxLength(str)<<"\n";

    return 0;
}