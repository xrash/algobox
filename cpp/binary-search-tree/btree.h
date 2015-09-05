#ifndef BST_BTREE_H
#define BST_BTREE_H

#include <stdio.h>
#include "stack.h"

template <typename Key, typename Value>
class BinaryTreeNode
{
public:
    Key key;
    Value value;
    //
    // Not used, but it could make the algorithms
    // easier.
    //
    //    BinaryTreeNode<Key,Value> *parent;
    //
    BinaryTreeNode<Key,Value> *left;
    BinaryTreeNode<Key,Value> *right;
    BinaryTreeNode(Key key, Value value);
};

template <typename Key, typename Value>
    BinaryTreeNode<Key,Value>::BinaryTreeNode(Key __key, Value __value)
{
    key = __key;
    value = __value;
}

template <typename Key, typename Value>
    class BinaryTree
{
private:
    BinaryTreeNode<Key,Value> *root;
public:
    BinaryTree();
    Value lookup(Key key);
    void insert(Key key, Value value);
    void remove(Key key);
    void dump();
};

template <typename Key, typename Value>
    BinaryTree<Key,Value>::BinaryTree()
{
    root = NULL;
}

//
// #########################################
// ### BST lookup - simple binary search ###
// #########################################
//
// Old story, kids: lower keys to the left, larger to the right.
//
template <typename Key, typename Value>
    Value BinaryTree<Key,Value>::lookup(Key key)
{
    BinaryTreeNode<Key,Value> *current = root;

    while (current != NULL) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current->value;
        }
    }

    return 0;
}

//
// #####################
// ### BST insertion ###
// #####################
//
// 1. Do a simple lookup, keeping track of the parent node.
//
// 2. When find a NULL location, insert below the parent node,
//    in the right location (left or right, verify the keys).
//
template <typename Key, typename Value>
    void BinaryTree<Key,Value>::insert(Key key, Value value)
{
    BinaryTreeNode<Key,Value> *node = new BinaryTreeNode<Key,Value>(key, value);

    if (root == NULL) {
        root = node;
        return;
    }

    BinaryTreeNode<Key,Value> *current = root;
    BinaryTreeNode<Key,Value> *parent = NULL;

    while (current != NULL) {
        parent = current;

        if (node->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

//
// ###################
// ### BST removal ###
// ###################
//
template <typename Key, typename Value>
    void BinaryTree<Key,Value>::remove(Key key)
{
    //
    // First, search for the node to be removed.
    //
    BinaryTreeNode<Key,Value> *current = root;
    BinaryTreeNode<Key,Value> *parent = NULL;

    while (current != NULL) {
        if (key < current->key) {
            parent = current;
            current = current->left;
        } else if (key > current->key) {
            parent = current;
            current = current->right;
        } else {
            break;
        }
    }

    // At this point, either the node exists and we found it,
    // or the node does not exist and we must return.
    if (current == NULL) {
        return;
    }

    //
    // Now we found a node.
    // We must check for the three possible cases:
    //
    // 1. The node has no child.
    // 2. The node has only one child.
    // 3. The node has both children.
    //

    //
    // 1. The node has no child:
    //
    //    In this case, we just remove the node.
    //    There is nothing more to do.
    //
    if (current->left == NULL && current->right == NULL) {
        if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }

        return;
    }

    //
    // 2. The node has only one child:
    //
    //    In this case, we remove the node and
    //    set it's single child to the current
    //    node's parent, effectively maintaining
    //    the BST invariant.
    //
    if (current->left == NULL || current->right == NULL) {
        BinaryTreeNode<Key,Value> *child = NULL;

        if (current->left == NULL) {
            child = current->right;
        } else {
            child = current->left;
        }

        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        return;
    }

    //
    // 3. The node has both children.
    //
    //    In this case, we search for the minimum left key
    //    in the right subtree, and then substitute the
    //    current value with it.
    //
    //    After that, we delete that minimum key original node,
    //    using the previous rules for one child or no child.
    //    (note that that minimum node cannot have both children,
    //    or it would not be the minimum child).
    //
    BinaryTreeNode<Key,Value> *cur = current->right;
    parent = current;
    BinaryTreeNode<Key,Value> **parent_ref = &current->right;
    BinaryTreeNode<Key,Value> *min = current->right;
    BinaryTreeNode<Key,Value> *min_parent = current;
    BinaryTreeNode<Key,Value> **min_parent_ref = &current->right;

    while (cur != NULL) {
        if (cur->key < min->key) {
            min = cur;
            min_parent = parent;
            min_parent_ref = parent_ref;
        }

        parent = cur;
        parent_ref = &cur->left;
        cur = cur->left;
    }

    current->value = min->value;

    if (min->right != NULL) {
        *min_parent_ref = min->right;
    } else {
        *min_parent_ref = NULL;
    }

    return;
}

//
// #################################################
// ### BST in-order traversal without recursion. ###
// #################################################
//
// 1. Initialize current node as root.
//
// 2. Set current = current->left, until current is NULL (depth-first 
//    search in the leftmost branch), pushing each node to the stack.
//
// 3. When reach the NULL pointer, pop the top item of the stack,
//    print it, then set current = popped->right.
//
// 4. Loop until (current is NULL) AND (stack is empty).
//
template <typename Key, typename Value>
    void BinaryTree<Key,Value>::dump()
{
    printf("\n=== START BST DUMP ===\n");

    Stack<BinaryTreeNode<Key,Value>*> *s = new Stack<BinaryTreeNode<Key,Value>*>();
    BinaryTreeNode<Key,Value> *current = root;
    BinaryTreeNode<Key,Value> *popped = NULL;

    while (current != NULL || !s->empty()) {
        if (current == NULL) {
            popped = s->pop();
            printf("key %d: value %d\n", popped->key, popped->value);
            current = popped->right;
        } else {
            s->push(current);
            current = current->left;
        }
    }

    printf("=== END BST DUMP ===\n\n");
}

#endif
