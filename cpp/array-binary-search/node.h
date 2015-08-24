#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int key;
    int value;

public:
    Node(int __key, int __value);
    int getKey();
    int getValue();
};

#endif
