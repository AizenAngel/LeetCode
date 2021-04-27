#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    long long dividend_ = dividend, divisor_ = divisor;

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend_ = abs(dividend_);
    divisor_ = abs(divisor_);

    long long quotient = 0, temp = 0;   

    //cout<<dividend_<<" "<<divisor_<<"\n";

    for (int i = 31; i >= 0; --i) {
        if (temp + (divisor_ << i) <= dividend_) {
            temp += divisor_ << i;
            quotient |= 1LL << i;
        }
    }

    long long res = sign * quotient;
    if (res == 2147483648)
        res--; 

    return res;
}

int main(){
    cout<<divide(-2147483648, 1)<<"\n";

    return 0;
}