// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    map<char, int> roman_values;
    roman_values.insert ({'I', 1});
    roman_values.insert ({'V', 5});
    roman_values.insert ({'X', 10});
    roman_values.insert ({'L', 50});
    roman_values.insert ({'C', 100});
    roman_values.insert ({'D', 500});
    roman_values.insert ({'M', 1000});

    int value = roman_values[s[s.size() - 1]];
    int n = s.size() - 1;

    for(int i = n - 1; i >= 0; i--){
        int p = roman_values[s[i]];
        int pp = roman_values[s[i + 1]];
        if(p < pp)
            value -= p;
        else value += p; 
    }
    return value;
}

int main(){
    string s;
    cin>>s;

    cout<<romanToInt(s)<<"\n";

    return 0;
}