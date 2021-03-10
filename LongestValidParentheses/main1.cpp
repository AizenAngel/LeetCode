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

    std::stack<int>open;
    int max_ans = 0;

    int last_closed = 0;
    bool flag;

    open.push(-1);

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            open.push(i);
        else{
            open.pop();
            if(open.empty()){
                open.push(i);
            }else{
                max_ans = std::max(max_ans, i - open.top());
            }
        }
    }

    return max_ans;
}

int main(int argc, char** argv){
    std::string str;
    
    std::cin>>str;
    std::cout<<longestValidParentheses(str)<<"\n";

    return 0;
}