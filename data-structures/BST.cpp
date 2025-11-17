#include <iostream>

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr){}
};

void insert(Node* root, int value)
{
    if(root->val > value)
    {
        if(root->left != nullptr)
        {
            insert(root->left, value);
        } else {
            root->left = new Node(value);
            return;
        }
    } else {
        if(root->right != nullptr)
        {
            insert(root->right, value);
        } else {
            root->right = new Node(value);
            return;
        }
    }
}

// Doing Node*& is so dumb and made this so much harder than it really was
void deleteNode(Node*& root, int value)
{
    if(!root) return;
    if(root->val < value)
    {
        deleteNode(root->right, value);
    } else if(root->val > value) {
        deleteNode(root->left, value);
    } else {
        if(!root->left && !root->right)
        {
            delete root;
            root = nullptr;
        } else if(!root->left) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if(!root->right) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* child = root->right;

            while(child->left)
            {
                child = child->left;
            }

            root->val = child->val;
            deleteNode(root->right, child->val);
        }
    }
}

void printInOrder(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    Node* root = new Node(10);
    insert(root, 15);
    insert(root, 5);
    insert(root, 6);
    insert(root, 21);
    insert(root, 20);

    deleteNode(root, 10);

    printInOrder(root);
    return 0;
}