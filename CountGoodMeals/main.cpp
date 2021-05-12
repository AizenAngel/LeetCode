#include <bits/stdc++.h>
using namespace std;

bool is_power_of_two(int num){
    return (num & (num-1) ? false: true);
}

int MODE = 1e9 + 7;

int countPairs(vector<int>& deliciousness) {
    int count = 0;
    map<long long, int> m;

    int n = deliciousness.size();

    for(int i = 0; i < deliciousness.size(); i++){
        m[deliciousness[i]]++;
    }

    int next = 0;

    for(int i = 0; i < 31; i++){
        int key = 1 << i;

        for(int j = 0; j < n; j++){

            
            if(key < deliciousness[j])
                continue;
            
            int k = key - deliciousness[j];
            
            if(m.find(k) == m.end())
                continue;

            else{
                int val = m[k];

                if(k == deliciousness[j])
                    val--;

                if(val % 2 == 0)
                    count += (val / 2);

                else{
                    if(next == 0){
                        count += val / 2;
                        next = 1;
                    }
                    else{
                        count += (val + 1)/2;
                        next = 0;
                    }

                }
            } 

            if (count > MODE)
                count -= MODE;

        }
    }

    return count;

}


int main(){
    vector<int> arr = {1, 3, 5, 7, 9};
//  vector<int> arr = {1,1,1,3,3,3,7};

//vector<int> arr = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
//vector<int> arr= {32, 32, 32, 32, 32};


    cout<<countPairs(arr)<<"\n";

    return 0;
}