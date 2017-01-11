#ifndef BinaryTreeDec
#define BinaryTreeDec

enum TreeExceptions
{
    NO_SMALLER_ELEMENT,
    INVALID_ITERATOR,
    IT_NO_LEFT_CHILD,
    IT_NO_RIGHT_CHILD,
    NOT_FOUND
};

template <typename VarType>
struct Tree_Node
{
    VarType Data;
    Tree_Node* Left;
    Tree_Node* Right;

    Tree_Node(const VarType& _Data = VarType(), Tree_Node* _Left = nullptr, Tree_Node* _Right = nullptr)
        : Data(_Data)
        , Left(_Left)
        , Right(_Right)
    { }
};

template <typename VarType>
class BinaryTree
{
public:
    // G4
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree<VarType>& source);
    BinaryTree<VarType>& operator=(const BinaryTree<VarType>& rhs);
    /////

    void Add(const VarType& what);
    void Remove(const VarType& key);

#include "../HPP/BinaryTreeIterator.hpp"

    TreeIterator Top()
    {
        return TreeIterator(top);
    }

    TreeIterator Search(const VarType& key)
    {
        return search(top, key);
    }

private:

    Tree_Node<VarType>*& Find(Tree_Node<VarType>*& node, const VarType& key);

    Tree_Node<VarType>* FindSmallest(Tree_Node<VarType>*& node);

    Tree_Node<VarType>* FindBiggest(Tree_Node<VarType>*& node);

    void add(const VarType& what, Tree_Node<VarType>*& node);

    void remove_node(Tree_Node<VarType>*& cur);

    void copy_node(Tree_Node<VarType>*& destination, Tree_Node<VarType>* source);

    TreeIterator search(Tree_Node<VarType>* node, const VarType& key)
    {
        if(node == nullptr)
            throw NOT_FOUND;

        if(key > node->Data)
            return search(node->Right, key);
        if(key < node->Data)
            return search(node->Left, key);

        return TreeIterator(top, node);
    }

    Tree_Node<VarType>* top;
};

#include "../HPP/BinaryTree.hpp"

#endif // BinaryTreeDec
