#include <numeric>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <iterator>

/*
    ((()))          --> 6

    ()()()          --> 6

    (()((()         --> 2

    (())((()))      --> 10
*/
/*
(()()())
*/

/*
()(((())))
*/

/*
Pada:
())()() -> 4
(()()   -> 4
*/

int longestValidParentheses(std::string s) {

    std::vector<int> count(s.size(), 0);

    int last_closed = 0;
    bool flag;


    for(int i = 1; i < s.size(); i++){
        flag = false;
        
        if(s[i] == ')'){         
            if(s[i-1] == '('){
                count[i] = (i >= 2 ? count[i - 2] : 0) + 2;
            }else if(i - count[i - 1] > 0 && s[i - count[i - 1] - 1] == '('){
                count[i] = count[i - 1] + (i - count[i - 1] >= 2 ? count[i - count[i -1] - 2] : 0) + 2;
            }
        }

    }

    // std::copy(
    //     count.begin(),
    //     count.end(),
    //     std::ostream_iterator<int>(std::cout, " ")
    // );

    // std::cout<<"\n";

    return std::accumulate(
        count.begin(),
        count.end(),
        0,
        [](int acc, int it){
            if(it > acc)
                return it;
            return acc;
        }
    );
}

int main(int argc, char** argv){
    std::string str;
    
    std::cin>>str;
    std::cout<<longestValidParentheses(str)<<"\n";

    return 0;
}