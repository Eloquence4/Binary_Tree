#ifndef BinaryTreeDef
#define BinaryTreeDef

////////////////////////////////////////////// G4

template<typename VarType>
inline BinaryTree<VarType>::BinaryTree()
    : top(nullptr)
{ }

template<typename VarType>
inline BinaryTree<VarType>::~BinaryTree()
{
    remove_node(top);
}

template<typename VarType>
inline BinaryTree<VarType>::BinaryTree(const BinaryTree<VarType>& source)
    : top(nullptr)
{
    copy_node(top, source.top);
}

template<typename VarType>
inline BinaryTree<VarType>& BinaryTree<VarType>::operator=(const BinaryTree<VarType>& rhs)
{
    if(this != &rhs)
        copy_node(top, rhs.top);
    return *this;
}

////////////////////////////////////////////// Public

template<typename VarType>
inline void BinaryTree<VarType>::add(const VarType& what)
{
    add(what, top);
}

////////////////////////////////////////////// Private

template<typename VarType>
inline Tree_Node<VarType>* BinaryTree<VarType>::FindSmallest(Tree_Node<VarType>*& node)
{
    if(node->Left != nullptr)
        return FindSmallest(node->Left);
    else
    {
        Tree_Node<VarType>* temp = node;

        node = nullptr;

        return temp;
    }
}

template<typename VarType>
inline Tree_Node<VarType>* BinaryTree<VarType>::FindBiggest(Tree_Node<VarType>*& node)
{
    if(node->Right != nullptr)
        return FindSmallest(node->Left);
    else
    {
        Tree_Node<VarType>* temp = node;

        node = nullptr;

        return temp;
    }
}

template<typename VarType>
inline void BinaryTree<VarType>::add(const VarType& what, Tree_Node<VarType>*& node)
{
    if(node == nullptr)
        node = new Tree_Node<VarType>(what);
    else
        if(what < node->Data)
            add(what, node->Left);
        else
            add(what, node->Right);
}

template<typename VarType>
inline void BinaryTree<VarType>::remove_node(Tree_Node<VarType>*& cur)
{
    if(cur == nullptr)
        return;

    if(cur->Left != nullptr)
        remove_node(cur->Left);
    if(cur->Right != nullptr)
        remove_node(cur->Right);
    delete cur;
}

template<typename VarType>
inline void BinaryTree<VarType>::copy_node(Tree_Node<VarType>*& destination, Tree_Node<VarType>* source)
{
    if(source == nullptr)
    {
        remove_node(destination);
        destination = nullptr;
    }
    else
    {
        if(!destination)
            destination = new Tree_Node<VarType>(source->Data);
        else
            destination->Data = source->Data;

        copy_node(destination->Left, source->Left);
        copy_node(destination->Right, source->Right);
    }
    
}

#endif // BinaryTreeDec
