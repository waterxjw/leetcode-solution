#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int current=stack1.top();
                stack1.pop();
                stack2.push(current);
            }
        }
        int ans=stack2.top();
        stack2.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int current=stack1.top();
                stack1.pop();
                stack2.push(current);
            }
        }
        int ans=stack2.top();
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty()&&stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */