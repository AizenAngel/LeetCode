// https://leetcode.com/problems/integer-to-english-words/

#include <bits/stdc++.h>
using namespace std;

string remove_right_whitespaces(string& str){
    int i = str.size() - 1;
    for(;i >= 0 && str[i] == ' '; i--);

    return str.substr(0, i + 1);
}

string three_digits_num(int n, string degree){
    if(n == 0)
        return "";

    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
    "Seventy", "Eighty", "Ninety"};

    vector<string> first_twenty{
        "", "One", "Two", "Three", "Four", "Five", "Six", 
       "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", 
       "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
       "Eighteen", "Nineteen"
    };

    string num = "";

    int f_digit = n / 100;
    int second_digit = (n / 10) % 10;
    int third_digit = n % 10;

    if(f_digit != 0)
        num += first_twenty[f_digit] + " Hundred ";
    
    int last_two_digits = second_digit * 10 + third_digit;

    if(last_two_digits != 0){
        if(last_two_digits < 20)
            num += first_twenty[last_two_digits];
        else{
            num += tens[second_digit] + (third_digit == 0 ? "" : " " + first_twenty[third_digit]);
        }
            
    }
    
    num = remove_right_whitespaces(num);

    if(!num.empty()){
        num += (" " + degree);
    }

    return num;
}

string entire_num(int n){
    if(n == 0)
        return "Zero";

    std::vector<string> degrees{"", "Thousand", "Million", "Billion"};
    string num = "";

    int MODE = 1000;

    for(int i = 0; i < degrees.size(); i++){
        int new_num = n % MODE;
        n = n / MODE;
        string ret = three_digits_num(new_num, degrees[i]);
        num = (ret.empty() ?"" : ret + " ") + num;

        if(n == 0)
            break;
    }

    return remove_right_whitespaces(num);
}

int main(){
    int n;
    cin>>n;
    cout<<entire_num(n)<<"\n";

    return 0;
}