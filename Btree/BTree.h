#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "VectorImplementation.cpp"
using namespace std;
template <class T, int Order>
class BTreeNode
{
private:
    Vector<T> elements;
    Vector<BTreeNode<T, Order> *> nodes;
    bool leaf;
    int realSize;

public:
    void addNode(BTreeNode<T, Order> *node);
    BTreeNode();
    bool isLeaf();
    int keysNum();
    void insertIntoElements(T element);
    Vector<T> &getElements();
    Vector<BTreeNode<T, Order> *> &getNodes();
    void split(int mid, BTreeNode<T, Order> *&newSibling, T &pushedUpElement);
    void printNode();
    void setLeaf(bool newLeaf);
};
template <class T, int Order>
class BTree
{
private:
    BTreeNode<T, Order> *root;
    BTreeNode<T, Order> *insertHandler(T element, BTreeNode<T, Order> *currentNode);
    void deleteTree(BTreeNode<T, Order> *node);
    void printHandler(BTreeNode<T, Order> *currentnode, string s);

public:
    BTree();
    ~BTree();
    void Insert(T element);
    void Print();
};

#endif
