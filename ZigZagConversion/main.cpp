#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1)
        return s;

    vector<string> conv(min(numRows, (int)s.size()));

    int index = 0;
    bool going_down = false;

    for(int i = 0; i < (int)s.size(); i++){
        conv[index] += s[i];

        if(index == 0 || index == numRows - 1)
            going_down = !going_down;
        
        index += (going_down ? 1 : -1);
    }

    string res;
    for(auto str : conv){
        res += str;
    }

    return res;
}

int main(int argc, char** argv){

    cout<<convert("PAYPALISHIRING", 3)<<"\n";

    return 0;
}