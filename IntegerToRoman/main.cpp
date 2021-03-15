// https://leetcode.com/problems/integer-to-roman/

#include <bits/stdc++.h>
using namespace std;

string roman(int n){
    if(n == 0)
        return "";

    vector<vector<string>> vec{{"I", "V", "X"}, {"X", "L", "C"}, {"C", "D", "M"}, {"M"}};
    
    string res = "";

    for(int i = 0;;i++){

        if(n == 0)
            break;

        int pom = n % 10;
        n = n / 10;

        if(pom == 0)
            continue;

        if(pom < 4){
            for(int j = 0; j < pom; j++)
                res = vec[i][0] + res; 
        }

        else if(pom == 4){
            res = (vec[i][0] + vec[i][1] + res);
        }

        else if(pom == 5){
            res = (vec[i][1] + res);
        }

        else if(pom < 9){
            for(int j = 0; j < pom - 5; j++){
                res = vec[i][0] + res;
                //cout<<vec[i][0]<<"\n";
            }
            
            //cout<<vec[i][1]<<"\n";
            res = vec[i][1] + res;
        }

        else if(pom == 9)
            res = vec[i][0] + vec[i][2] + res;
    }

    return res;
}

int main(){
    int number;
    string result;

    cin>>number;
    cout<<roman(number)<<"\n";

    return 0;
}