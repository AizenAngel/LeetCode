#include <bits/stdc++.h>
using namespace std;

int trap(std::vector<int>& height){

    stack<int> st;
    int current = 0;
    int ans = 0;

    while(current < height.size()){
        while(!st.empty() && height[current] > height[st.top()]){
            int top = st.top();
            st.pop();

            if(st.empty())
                break;
            
            int distance = current - st.top() - 1;
            int volume = min(height[current], height[st.top()]) - height[top];
            ans += distance * volume;
        }

        st.push(current++);
    
    }

    return ans;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin>>n;
    std::vector<int>height(n);

    for(int i = 0; i < n; i++){
        std::cin>>height[i];
    }

    std::cout<<trap(height)<<"\n";

    return 0;
}

/*
12
0 1 0 2 1 0 1 3 2 1 2 1

6
4 2 0 3 2 5

5
6 4 3 0 5
*/