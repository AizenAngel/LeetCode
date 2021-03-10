// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    
    if(!s.size())
        return 0;

    vector<int> visited(256, -1);
    vector<int> max_until_i(s.size(), 0);

    visited[(int)s[0]] = 0;

    max_until_i[0] = 1;

    for(int i = 1; i < s.size(); i++){

        int letter = (int)s[i];

        if(visited[letter] == -1){
            visited[letter] = i;
            max_until_i[i] = max_until_i[i-1] + 1;
        }else{
            max_until_i[i] = min(max_until_i[i-1] + 1, i - visited[letter]);
            visited[letter] = i;
        }
    }

    // std::copy(
    //     max_until_i.begin(),
    //     max_until_i.end(),
    //     ostream_iterator<int>(cout, " ")        
    // );

    return accumulate(
        max_until_i.begin(),
        max_until_i.end(),
        0,
        [](auto acc, auto next){
            return max(acc, next);
        }
    );

}

int main(int argc, char** argv){
    string input;

    cin>>input;
    cout<<lengthOfLongestSubstring(input)<<"\n";

    return 0;
}

/*
tmmzuxt
*/
