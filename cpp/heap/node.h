#ifndef NODE_H
#define NODE_H

template <typename Value>
class Node
{
private:
    int key;
    Value value;

public:
    Node(int __key, Value __value);
    int getKey();
    Value getValue();
};

template <typename Value>
Node<Value>::Node(int __key, Value __value)
{
    key = __key;
    value = __value;
}

template <typename Value>
int Node<Value>::getKey()
{
    return key;
}

template <typename Value>
Value Node<Value>::getValue()
{
    return value;
}

#endif
