class Stack {
public:
    class Underflow {};
    class Overflow {};
    virtual void push(char c) = 0;
    virtual char pop() = 0;
};

class Array_stack : public Stack{
    char *p;
    int top;
    int max_size;
public:
    Array_stack(int s);  // constructor
    ~Array_stack();      // destructor

    void push(char c);
    char pop();
};
