//https://leetcode.com/discuss/interview-question/351783/

#include <iostream>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
#include <tuple>
#include <vector>

int min_swaps(std::string str){
    std::vector<int>alphabet(26, 0);

    for(auto it: str){
        alphabet[it - 'a']++;
    }

    int odd_count = std::accumulate(alphabet.begin(),
                                    alphabet.end(),
                                    0,
                                    [](auto acc, const auto it){
                                        return (it % 2 ? acc + 1 : acc);
                                    });

    if(odd_count > 1)
        return -1;
    
    int end = str.size() - 1;
    int count = 0;

    for(int i = 0; i <= str.length() / 2; i++){
        if(str[i] == str[end - i])
            continue;
        
        int j, k;

        for(j = i + 1; j <= end - i && str[j] != str[end - i]; j++);
        for(k = end - i - 1; k >= i && str[i] != str[k]; k--);

        count += std::min(j - i, end - i - k);

        if(j - i <= end - i - k){
            for(int p = j; p > i; p--)
                std::swap(str[p], str[p - 1]);
        }else{
            for(int p = k; p < end - i; p++)
                std::swap(str[p], str[p + 1]);
        }
    }

    //std::cout<<str<<"\n";

    return count;
}

int main(int argc, char** argv){

    std::cout<<min_swaps("mamad")<<"\n";

    return 0;
}