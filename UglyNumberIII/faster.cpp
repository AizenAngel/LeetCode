#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll numOfUglyNumberWithUpperLimit(long m, long a, long b, long c){
    ll lcm_ab = lcm(a, b);
    ll lcm_ac = lcm(a, c);
    ll lcm_bc = lcm(b, c);
    ll lcm_abc = lcm(a, lcm_bc);

    return (m/a + m/b + m/c - m/lcm_ab - m/lcm_ac - m/lcm_bc + m/lcm_abc);
}

int nthUglyNumber(int n, int a, int b, int c){
    ll l = 1;
    ll u = 2*1e9;

    while(l <= u){
        ll m = (l + u)/2;
        if(numOfUglyNumberWithUpperLimit(m, a, b, c) >= n)
            u = m - 1;
        else
            l = m + 1;
    }

    return (int)l;
}

int main(){

    cout<<nthUglyNumber(1000000000, 2, 217983653, 336916467)<<"\n";

    return 0;
}