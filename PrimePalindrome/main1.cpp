#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    if(n == 1)
        return false;
    
    if(n == 2 || n == 3)
        return true;

    int limit = sqrt(n);
    
    for(int i = 2; i <= limit; i++){
        if (n % i == 0)
            return false;
    }

    return true;
}

int primePalindrome(int n){
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return n;
    
    if(n == 4)
        return 5;
    
    if(n == 6)
        return 7;
    
    if(8 <= n & n <= 11)
        return 11;
    
    for(int i = 1; i < 1e5; i++){
        string s = to_string(i);
        string t(s.rbegin(), s.rend());
        s += t.substr(1);

        int tmp_num = stoi(s);

        if (tmp_num >= n && is_prime(tmp_num)){
            return tmp_num;
        }
    }

    return -1;
}

int main(){

    int n;
    cin>>n;

    cout<< primePalindrome(n) <<"\n";

    return 0;
}


