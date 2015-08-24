#include "node.h"

Node::Node(int __key, int __value)
{
    key = __key;
    value = __value;
}

int Node::getKey()
{
    return key;
}

int Node::getValue()
{
    return value;
}
