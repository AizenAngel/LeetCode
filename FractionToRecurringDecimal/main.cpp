#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    bool is_negative = (numerator > 0) ^ (denominator > 0) ? false: true;
    
    long _numerator = abs(numerator);
    long _denominator = abs(denominator);
    long _quotent = _numerator / _denominator;
    long _remainder = _numerator % _denominator;
    
    if(_remainder == 0){
        return is_negative ? "-" + to_string(_quotent) : to_string(_quotent);
    }

    string ret = to_string(_quotent) + ".";
    string s = "";
    unordered_map<int, long> pos_rest;
    int cur_pos = 1;
    pos_rest.insert(make_pair(_remainder, cur_pos));

    while(true){
        long cur_digit = (10 * _remainder) / _denominator;
        _remainder = (10 * _remainder) % _denominator;
        
        if(_remainder == 0){
            s += to_string(cur_digit);
            ret += s;
            return ret;
        }

        if(pos_rest.find(_remainder) != pos_rest.end()){
            s += to_string(cur_digit) + ")";
            s.insert(pos_rest[_remainder] - 1, "(");
            ret += s;
            return ret;
        }

        ++cur_pos;
        pos_rest.insert(make_pair(_remainder, cur_pos));
        s += to_string(cur_digit);
    }

}

int main(int argc, char** argv){

    cout<<fractionToDecimal(4, 333)<<"\n";

    return 0;
}