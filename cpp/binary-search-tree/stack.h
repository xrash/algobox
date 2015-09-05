#ifndef BST_STACK_H
#define BST_STACK_H

#include <stdio.h>

template <typename Value>
class StackElement
{
public:
    Value value;
    StackElement<Value> *below;
};

template <typename Value>
class Stack
{
private:
    StackElement<Value> *top;
public:
    Stack();
    void push(Value);
    Value pop();
    bool empty();
    void dump();
};

template <typename Value>
Stack<Value>::Stack()
{
    top = NULL;
}

template <typename Value>
void Stack<Value>::push(Value value)
{
    StackElement<Value> *newTop = new StackElement<Value>();
    newTop->value = value;
    newTop->below = top;
    top = newTop;
}

template <typename Value>
Value Stack<Value>::pop()
{
    if (top == NULL) {
        return NULL;
    }

    StackElement<Value> *tmp = top;
    top = top->below;
    return tmp->value;
}

template <typename Value>
bool Stack<Value>::empty()
{
    return top == NULL;
}

template <typename Value>
void Stack<Value>::dump()
{
    printf("\n=== START STACK DUMP ===\n");

    StackElement<Value> *current = top;
    int i = 0;

    while (current != NULL) {
        printf("%d: %s\n", i++, current->value);
        current = current->below;
    }

    printf("\n=== END STACK DUMP ===\n");
}

#endif
