#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string rev = "";
    std::istringstream iss(s);   
    for(std::string s; iss >> s; ) 
        rev = s + " " + rev;
    
    return rev.erase(rev.find_last_not_of(" \t\n\r\f\v")  + 1);
}

int main(){
    cout<<reverseWords("  Bob    Loves  Alice   ");

    return 0;
}