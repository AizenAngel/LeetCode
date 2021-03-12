// https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<int>& vec){
    copy(
        vec.begin(),
        vec.end(),
        ostream_iterator<int>(cout)
    );
    cout<<"\n";
}

long long convert_vec_to_int(vector<int>& vec, int sign, int count_first_zeros){

    if(count_first_zeros >= vec.size())
        return 0;

    sign = (sign == -1 ? -1 : 1);
    return accumulate(
        vec.begin() + 1 + count_first_zeros,
        vec.end(),
        (long long)(vec[count_first_zeros] * sign),
        [sign](long long acc, int next){
            return acc * 10 + sign * next;
        } 
    );
}

int main(int argc, char** argv){
        std::vector<int>numbers;
        std::vector<int> limit_pos = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        std::vector<int> limit_neg = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
        int sign = 0;
        string input;

        cin>>input;
        
        for(int i = 0; i < input.size(); i++){
            char ch = input[i];

            if(ch == ' ' && numbers.empty())
                continue;

            else if(!isdigit(ch) && ch != '+' && ch != '-')
                break;

            else if(ch == '-'){
                if(!sign && numbers.empty()){
                    if(!isdigit(input[i+1]))
                        break;
                    sign = -1;
                }
                else break;
            }
                

            else if(ch == '+'){
                if(!sign && numbers.empty()){
                    if(!isdigit(input[i+1]))
                        break;
                    sign = 1;
                }
                    
                else break;
            }
                

            else if(isdigit(ch))
                numbers.push_back(ch - '0');
        }

        //print_vector(numbers);

        if(numbers.empty()){
            return 0;
        }

        int count_first_zeros = 0;

        for(;count_first_zeros < numbers.size() && numbers[count_first_zeros] == 0; count_first_zeros++);

        if(numbers.size() - count_first_zeros < limit_pos.size()){
            cout<<convert_vec_to_int(numbers, sign, count_first_zeros);
            return 0;
        }

        if(numbers.size() - count_first_zeros > limit_pos.size()){
            cout<<convert_vec_to_int((sign == -1 ? limit_neg: limit_pos), sign, count_first_zeros);
            return 0;
        }

        bool is_greater;

        const auto limit = (sign == -1 ? limit_neg : limit_pos);

        for(int i = 0; i < numbers.size(); i++){
            //cout<<numbers[i + count_first_zeros]<<" "<<limit[i]<<"\n";
            if(numbers[i + count_first_zeros] < limit[i]){
                is_greater = false;
                break;
            }else if(numbers[i + count_first_zeros] > limit[i]){
                is_greater = true;
                break;
            }
        }

        if(is_greater){
            cout<< convert_vec_to_int((sign == -1 ? limit_neg : limit_pos), sign, count_first_zeros);
        }
            
        else cout<< convert_vec_to_int(numbers, sign, count_first_zeros);

    return 0;
}

//91283472332
//00000-42a1234
//  0000000000012345678
// 00000-42a1234
// -2147983648
// 1095502006p8
// -2147483647
// 2147483800
// 1095502006p8
// 2147483648







