#include <queue>
using namespace std;
class MyStack {
    private:
    queue<int> q1,q2;
    int top_val;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> *current;
        if(q1.empty()){
            current=&q2;
        }else{
            current=&q1;
        }
        top_val=x;
        current->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> *from,*to;
        if(q1.empty()){
            from=&q2;
            to=&q1;
        }else{
            from=&q1;
            to=&q2;
        }
        while(!from->empty()){
            int val=from->front();
            if(from->size()==1){
                from->pop();
                return val;
            }else if(from->size()==2){
                top_val=val;
            }
            from->pop();
            to->push(val);
        }
        return 0;
    }
    
    /** Get the top element. */
    int top() {
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */