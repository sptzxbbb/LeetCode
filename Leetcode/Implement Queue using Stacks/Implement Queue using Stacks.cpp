class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        q.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        while (!q.empty()) {
            temp.push(q.top());
            q.pop();
        }

        temp.pop();

        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
        return;
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        while (!q.empty()) {
            temp.push(q.top());
            q.pop();
        }

        int ans = temp.top();

        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
        return ans;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return q.empty();
    }
private:
    stack<int> q;
};


