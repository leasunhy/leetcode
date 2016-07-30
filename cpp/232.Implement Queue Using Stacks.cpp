// Date: 2016-07-30

#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        ensure();
        q.pop();
    }

    // Get the front element.
    int peek(void) {
        ensure();
        return q.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return q.empty() && s.empty();
    }
    
private:
    stack<int> q;
    stack<int> s;
    
    void ensure() {
        if (q.empty()) {
            while (!s.empty()) {
                q.push(s.top());
                s.pop();
            }
        }
    }
};

