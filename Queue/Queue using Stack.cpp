
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    stack<int> s1,s2;
    
    void push(int val){
        s1.push(val);
    }
    
    void pop() {
        if(s2.empty()) {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(s2.empty()){
            cout<<"Queue is empty:"<<endl;
        }
        else
            s2.pop();
    }
    
    int top() {
        
        if(s2.empty()) {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(s2.empty()){
            cout<<"Queue is empty:";
            return -1;
        }
        else
            return s2.top();
    }
};

int main() {
    // your code goes here
    Queue queue;
    queue.push(5);
    queue.push(6);
    queue.push(3);
    queue.push(2);
    cout<<queue.top()<<endl;
    queue.pop();
    cout<<queue.top()<<endl;
    queue.pop();
    queue.push(15);
    cout<<queue.top()<<endl;
    queue.pop();
    return 0;
}
