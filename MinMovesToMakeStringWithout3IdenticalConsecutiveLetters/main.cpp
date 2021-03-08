#include <bits/stdc++.h>

int main(int argc, char** argv){
    std::string str;

    std::cin>>str;
    int count = 0;
    int next;

    for(int i = 0; i < str.size() - 1; i++){
        next = i + 1;

        while(next < str.size() && str[i] == str[next])
            next++;
        
        count = (1 + next - i) / 3;
        i = next;
    }

    std::cout<<count<<"\n";

    return 0;
}