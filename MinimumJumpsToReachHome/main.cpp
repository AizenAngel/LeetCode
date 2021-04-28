#include <bits/stdc++.h>
using namespace std;

struct Step{
    int position;
    int count;
    bool is_backward;
};

struct Compare{
    bool operator()(const Step& left, const Step& right){
        return left.count < right.count;
    }
};

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    if(x == 0)
        return 0;

    priority_queue<Step, vector<Step>, Compare> step_queue;
    set<int> forbidden_set(forbidden.begin(), forbidden.end());

    if (forbidden_set.find(a) != forbidden_set.end())
        return -1;

    step_queue.push({a, 1, false});

    while (!step_queue.empty()){
        Step current = step_queue.top();
        step_queue.pop();

        std::cout<<"Pozicija: "<<current.position<<"\n";

        if(current.position == x)
            return current.count;

        Step next_step_forward = {current.position + a, current.count + 1, false};

        if(next_step_forward.position < 6000 && forbidden_set.find(next_step_forward.position) == forbidden_set.end()){
            step_queue.push(next_step_forward);
            forbidden_set.insert(next_step_forward.position);
        }

        if(current.is_backward)
            continue;
        
        Step next_step_backward = {current.position - b, current.count + 1, true};
        if (next_step_backward.position > 0 && forbidden_set.find(next_step_backward.position) == forbidden_set.end()){
            step_queue.push(next_step_backward);
            forbidden_set.insert(next_step_forward.position);
        }
    }

    return -1;
} 

int main(){
    vector<int> forbidden = {8, 3, 16, 6, 12, 20};
    int a = 15;
    int b = 13;
    int x = 11;

    cout<<minimumJumps(forbidden, a, b, x)<<"\n";

    return 0;
}