
#include "BTree.h"
#define all(v) v.begin(), v.end()
// BTreeNode implementation
template <class T, int Order>
void BTreeNode<T, Order>::setLeaf(bool newLeaf)
{
    leaf = newLeaf;
}

template <class T, int Order>
BTreeNode<T, Order>::BTreeNode()
{
    leaf = true;
    realSize = 0;
}

template <class T, int Order>
bool BTreeNode<T, Order>::isLeaf()
{
    return leaf;
}
template <class T, int Order>
int BTreeNode<T, Order>::keysNum()
{
    return realSize;
}

template <class T, int Order>
void BTreeNode<T, Order>::insertIntoElements(T element)
{
    int left = 0, right = elements.Size() - 1, mid, place = elements.Size();
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (elements[mid] >= element)
        {
            place = mid, right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    elements.insert(place, element);
    realSize++;
}

template <class T, int Order>
Vector<T> &BTreeNode<T, Order>::getElements()
{
    return elements;
}

template <class T, int Order>
Vector<BTreeNode<T, Order> *> &BTreeNode<T, Order>::getNodes()
{
    return nodes;
}
template <class T, int Order>
void BTreeNode<T, Order>::split(int mid, BTreeNode<T, Order> *&newSibling, T &pushedUpElement)
{
    newSibling = new BTreeNode<T, Order>();
    pushedUpElement = elements[mid];
    newSibling->elements.assign(elements.begin() + mid + 1, elements.end());
    elements.resize(mid);
    if (!leaf)
    {
        newSibling->nodes.assign(nodes.begin() + mid + 1, nodes.end());
        nodes.resize(mid + 1);
    }
    newSibling->realSize = newSibling->elements.Size();
    realSize = elements.Size();
    newSibling->setLeaf(leaf);
}

template <class T, int Order>
void BTreeNode<T, Order>::printNode()
{
    for (int i = 0; i < realSize - 1; i++)
    {
        cout << elements[i] << ", ";
    }
    if (realSize > 0)
        cout << elements[realSize - 1];
    cout << endl;
}
template <class T, int Order>
void BTreeNode<T, Order>::addNode(BTreeNode<T, Order> *node)
{
    nodes.push_back(node);
}
// BTree implementation
template <class T, int Order>
BTree<T, Order>::BTree()
{
    root = new BTreeNode<T, Order>();
}
template <class T, int Order>
void BTree<T, Order>::deleteTree(BTreeNode<T, Order> *node)
{
    if (!node)
        return;
    Vector<BTreeNode<T, Order> *> children = node->getNodes();
    for (int i = 0; i < children.Size(); i++)
    {
        if (children[i])
        {
            deleteTree(children[i]);
        }
    }
    delete node;
}

template <class T, int Order>
BTree<T, Order>::~BTree()
{
    deleteTree(root);
}
template <class T, int Order>
void BTree<T, Order>::Insert(T element)
{
    BTreeNode<T, Order> *currentRoot = insertHandler(element, root);
    if (currentRoot)
    {
        T newRootelement;
        BTreeNode<T, Order> *sibling;
        currentRoot->split((Order - 1) / 2, sibling, newRootelement);
        BTreeNode<T, Order> *newRoot = new BTreeNode<T, Order>();
        newRoot->insertIntoElements(newRootelement);
        newRoot->addNode(currentRoot);
        newRoot->addNode(sibling);
        newRoot->setLeaf(false);
        root = newRoot;
    }
}
template <class T, int Order>
BTreeNode<T, Order> *BTree<T, Order>::insertHandler(T element, BTreeNode<T, Order> *currentNode)
{
    if (currentNode->isLeaf())
    {
        currentNode->insertIntoElements(element);
        if (currentNode->keysNum() >= Order)
            return currentNode;
        return nullptr;
    }
    Vector<T> &elements = currentNode->getElements();
    Vector<BTreeNode<T, Order> *> &nodes = currentNode->getNodes();
    int left = 0, right = elements.Size(), index = elements.Size();
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (elements[mid] >= element)
        {
            index = mid, right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    BTreeNode<T, Order>* nextNode =nodes[index];
    BTreeNode<T, Order> *needSplit = insertHandler(element, nextNode);
    if (needSplit)
    {
        BTreeNode<T, Order> *newSibling;
        T pushedUpElement;
        needSplit->split((Order - 1) / 2, newSibling, pushedUpElement);
        currentNode->insertIntoElements(pushedUpElement);
        currentNode->getNodes().insert(index + 1, newSibling);
        if (currentNode->keysNum() >= Order)
        {
            return currentNode;
        }
    }
    return nullptr;
}

template <class T, int Order>
void BTree<T, Order>::printHandler(BTreeNode<T, Order> *currentNode, string s)
{
    if (!currentNode)
        return;
    currentNode->printNode();
    Vector<BTreeNode<T, Order> *> children = currentNode->getNodes();
    if (!currentNode->isLeaf())
    {
        s += " ";
    }
    int j = currentNode->keysNum();
    for (int i = 0; i < min(j + 1, (int)children.Size()); i++)
    {
        cout << s;
        printHandler(children[i], s);
    }
}
template <class T, int Order>
void BTree<T, Order>::Print()
{
    printHandler(root, "");
}
