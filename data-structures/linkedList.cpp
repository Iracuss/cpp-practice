#include <iostream>

struct Node
{
    int val;
    Node* next;

    Node(int v) : val(v), next(nullptr) {}
};

void insert(Node* root, int val)
{
    Node* current = root;


    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(val);
}

void printList(Node* root)
{
    Node* current = root;

    int i = 1;
    while(current != nullptr)
    {
        std::cout << i++ << ". " << current->val << '\n';
        current = current->next;
    }
}

int main()
{
    Node* root = new Node(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 72);
    insert(root, 6);
    insert(root, 100);
    insert(root, 42);

    printList(root);

    return 0;
}