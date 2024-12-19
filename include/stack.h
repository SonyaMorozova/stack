#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> stack;

public:

    void push(const T& element) {
        stack.push_back(element);
    }

    void pop() {
        if (is_empty()) throw "Stack is null";
        stack.pop_back();
    }

    T top() const {
        if (is_empty()) throw "Stack is null";
        return stack.back();
    }

    int is_empty() const {
        return stack.empty();
    }

    void clear() {
        stack.clear();
    }

    size_t size() const {
        return stack.size();
    }

    int operator== (const Stack& stack2) {
        return stack == stack2.stack;
    }

    int operator!= (const Stack& stack2) {
        return stack != stack2.stack;
    }

    Stack& operator= (const Stack& stack2) {
        stack.clear();
        if (!stack2.is_empty()) {
            for (auto val : stack2.stack) stack.push_back(val);
        }
        return *this;
    }

    void swap(Stack& stack2) {
        stack.swap(stack2.stack);
    }
};