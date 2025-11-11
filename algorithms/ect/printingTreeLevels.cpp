#include <iostream>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val)
{
    if(root == nullptr)
    {
        return new Node(val);
    }

    if(val < root->value)
    {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void printLevels(Node* root)
{
    if(!root)
    {
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    int level = 0;

    while(!q.empty())
    {
        int levelSize = q.size();
        std::cout << "Level " << level << ": ";

        for(int i = 0; i < levelSize; i++)
        {
            Node* current = q.front();
            q.pop();
            std::cout << current->value << " ";

            if(current->left)
            {
                q.push(current->left);
            }
            if(current->right)
            {
                q.push(current->right);
            }
        }

        std::cout << std::endl;
        level++;
    }
    
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    printLevels(root);
}