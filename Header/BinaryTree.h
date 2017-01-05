#ifndef BinaryTreeDec
#define BinaryTreeDec

enum TreeExceptions
{
    NO_SMALLER_ELEMENT
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

    void add(const VarType& what);
    void remove(const VarType& key);

#include "../HPP/BinaryTreeIterator.hpp"

    TreeIterator top() const;

    TreeIterator search(const VarType& key) const;

    private:

    Tree_Node<VarType>* FindSmallest(Tree_Node<VarType>*& node);

    Tree_Node<VarType>* FindBiggest(Tree_Node<VarType>*& node);

    void add(const VarType& what, Tree_Node<VarType>*& node);

    void remove_node(Tree_Node<VarType>*& cur);

    void copy_node(Tree_Node<VarType>*& destination, Tree_Node<VarType>* source);

    Tree_Node<VarType>* top;
};

#include "../HPP/BinaryTree.hpp"

#endif // BinaryTreeDec
