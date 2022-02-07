#include <iostream>

const int kLinkedSize = 10; // Maximum size(length) of Node 

// define the structure
class Node
{
  public:
    int num;
    Node* tail;

};

class LinkedList
{
  public:
    Node *linked_head;
    Node *next_node;

    LinkedList();

    void Push(int num);
    int Pop();
    bool IsEmpty();
    bool IsFull();
    int CountNodes(Node* head);
    void DisplayLinkedList();
    void CallLinkedList();
};
