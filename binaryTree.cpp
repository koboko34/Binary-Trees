#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;

    Node(T newData)
    {
        this->data = newData;
        this->left = nullptr;
        this->right = nullptr;
    };
};

template <typename T>
class BinaryTree
{
public:
    Node<T>* root;

    BinaryTree()
    {
        root = nullptr;
    }

    void AddNode(T newData)
    {
        Node<T>* newNode = new Node<T>(newData);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node<T>* focusNode = root;
        Node<T>* parent;

        while (true)
        {
            parent = focusNode;
            if (newData < focusNode->data)
            {
                focusNode = focusNode->left;
                if (focusNode == nullptr)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                focusNode = focusNode->right;
                if (focusNode == nullptr)
                {
                    parent->right = newNode;
                    return;
                }
            } 
        }
    }
};

template <typename T>
void PreOrderTraversal(T* node)
{
    if (node != nullptr)
    {
        std::cout << node->data << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
}

class MyNumber
{
public:
    int m_num;
    MyNumber(int num)
    {
        m_num = num;
    }

    MyNumber()
    {

    }

    bool operator<(MyNumber other)
    {
        return m_num > other.m_num;
    }
};

std::ostream& operator<<(std::ostream& stream, const MyNumber& other)
{
    stream << other.m_num;
    return stream;
}

int main()
{
    BinaryTree<MyNumber> tree;

    tree.AddNode(50);
    tree.AddNode(25);
    tree.AddNode(75);
    tree.AddNode(12);
    tree.AddNode(37);
    tree.AddNode(43);
    tree.AddNode(30);

    PreOrderTraversal(tree.root);
    
    return 0;
}