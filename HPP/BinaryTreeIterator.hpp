#ifndef BinaryTreeIteratorDef
#define BinaryTreeIteratorDef

class TreeIterator
{
    friend class BinaryTree;

public:

    VarType& data()
    {
        if(ptr == nullptr)
            throw INVALID_ITERATOR;

        return ptr->Data;
    }

    TreeIterator search(const VarType& key)
    {
        return search(ptr, key);
    }

    const VarType& data() const
    {
        if(ptr == nullptr)
            throw INVALID_ITERATOR;

        return ptr->Data;
    }

    TreeIterator& operator++()
    {
        if(ptr->Left == nullptr)
            throw IT_NO_LEFT_CHILD;

        ptr = ptr->Left;
    }

    void GoLeft()
    {
        ++(*this);
    }

    TreeIterator operator++(int)
    {
        if(ptr->Right == nullptr)
            throw IT_NO_RIGHT_CHILD;

        ptr = ptr->Right;
    }

    void GoRight()
    {
        (*this)++;
    }

    bool leaf() const
    {
        if(ptr->Left || ptr->Right)
            return false;
        
        return true;
    }

    void remove_left()
    {
        remove(ptr->Left);
    }

    void remove_right()
    {
        remove(ptr->Right);
    }

private:

    TreeIterator(Tree_Node<VarType>* _ptr)
        : top(_ptr)
        , ptr(_ptr)
    { }

    TreeIterator(Tree_Node<VarType>* _top, Tree_Node<VarType>* _ptr)
        : top(_top)
        , ptr(_ptr)
    { };

    TreeIterator search(Tree_Node<VarType>* node, const VarType& key)
    {
        if(node == nullptr)
            throw NOT_FOUND;

        if(key > node->Data)
            return search(node->Right, key);
        else if(key < node->Data)
            return search(node->Left, key);
        else
            return TreeIterator(top, node);
    }

    Tree_Node<VarType>* FindSmallest(Tree_Node<VarType>*& node)
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

    Tree_Node<VarType>* FindBiggest(Tree_Node<VarType>*& node)
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

    void remove(Tree_Node<VarType>*& node)
    {
        if(node->Left && node->Right)
        {
            Tree_Node<VarType>* temp = node;

            if((size_t)&node & 2) // Some randomness when it choses Left or Right
                node = FindSmallest(node->Right);
            else
                node = FindBiggest(node->Left);

            node->Left = temp->Left;
            node->Right = temp->Right;

            delete temp;
        }
        else if(node->Left || node->Right)
        {
            Tree_Node<VarType>* temp = node;

            if(node->Left)
                node = node->Left;
            else if(node->Right)
                node = node->Right;

            delete temp;
        }
        else
        {
            delete node;

            if(top == node)
                top == nullptr;

            node = nullptr;
        }
    }

    Tree_Node<VarType>*& top;
    Tree_Node<VarType>*  ptr;

};

#endif // BinaryTreeIteratorDef
