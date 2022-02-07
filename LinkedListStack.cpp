#include <iostream>
#include "LinkedListStack.hpp"

LinkedList::LinkedList()
{
  linked_head = nullptr; // initialising
}

void LinkedList::Push(int num)
{
  if(IsFull() == 1)
  {
    std::cout << "Stack is full." << std::endl;
  }
  else
  {
    // alloc memory for next
    Node* next = new Node();

    next->num = num;
    // Null at first. Tail becomes the new value(node)
    next->tail = linked_head;

    linked_head = next;
  }
}

int LinkedList::Pop()
{
  if(IsEmpty() == 1)
  {
    std::cout << "Stack is empty." << std::endl;
  }
  else
  {
    linked_head = linked_head->tail;
  }
}

bool LinkedList::IsEmpty()
{
  if(linked_head == nullptr)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int LinkedList::CountNodes(Node* head)
{
  int count = 0;
  Node* current = head;
  while (current != nullptr)
  {
    count++;
    current = current->tail;
  }
  return count;
}

bool LinkedList::IsFull()
{
  if(CountNodes(linked_head) == kLinkedSize)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void LinkedList::DisplayLinkedList()
{
  next_node = linked_head;

  while(next_node->tail != nullptr)
  {
    std::cout << next_node->num << "  ";
    next_node = next_node->tail; // This will find till the node is empty
  }
  std::cout << next_node->num << std::endl;
}

void LinkedList::CallLinkedList()
{
  LinkedList *linked_list = new LinkedList();
  linked_list->Pop();
  linked_list->Push(1);
  linked_list->Push(2);
  linked_list->Push(3);
  linked_list->Push(4);

  linked_list->DisplayLinkedList();

  linked_list->Pop();
  linked_list->DisplayLinkedList();
  linked_list->Push(5);
  linked_list->Push(6);
  linked_list->Push(7);
  linked_list->Push(8);
  linked_list->Pop();
  linked_list->Push(9);
  linked_list->Push(10);
  linked_list->DisplayLinkedList();
  linked_list->Push(11);
  linked_list->DisplayLinkedList();
  linked_list->Push(12);
  linked_list->DisplayLinkedList();
  linked_list->Push(13);

  delete[] linked_list;
}
