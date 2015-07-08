class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        s.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        s.pop_back();
    }

    // Get the top element.
    int top() {
        return s.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return s.empty();
    }
private:
    list<int> s;
};



















