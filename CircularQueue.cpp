#include <iostream>
#include <thread>
#include <chrono>
#include "CircularQueue.hpp"

CircularQueue::CircularQueue(int max_size):max_size(max_size)
{
  front = 0;
  rear = 0;
  max_size = 10;
}

CircularQueue::~CircularQueue() { }

void CircularQueue::Enqueue(int value)
{
  if (IsFull() == 1)
  {
    std::cout << "Queue is full!" << std::endl;
  }
  else
  {
    rear = (rear + 1) % max_size;
    queue[rear] = value;
    std::cout << value << " is inserted at " << rear << std::endl; 
  }
}

void CircularQueue::Dequeue()
{
  if (IsEmpty() == 1)
  {
    std::cout << "Queue is empty!" << std::endl;
  }
  else
  {
    front = (front + 1) % max_size;
    queue[front] = 0;
  }
}

bool CircularQueue::IsEmpty()
{
  if(front == rear)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool CircularQueue::IsFull()
{
  if(front == (rear + 1) % max_size)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void CircularQueue::DisplayCircularQueue()
{
  if (IsEmpty() == 1)
  {
    std::cout << "Queue is empty!" << std::endl;
  }
  else
  {
    std::cout << "List of Circular Queue: " << std::endl;
    for (int i = 0; i < max_size; i++)
    {
      std::cout << queue[i] << "  ";
    }
    std::cout << std::endl;
  }
}

void CircularQueue::ThreadEnqueue()
{
  while(IsFull() == 0){
    int random = std::rand()%100;
    Enqueue(random);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  DisplayCircularQueue();
}

void CircularQueue::ThreadDequeue()
{
  while(IsEmpty() == 0) {
    Dequeue();
    std::cout << "Popping..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  DisplayCircularQueue();
}

void CircularQueue::CallCircularQueue()
{
  int choice;
  int value = 0;
  bool run = true;
  const std::string menu
  (
    "\nSelect a number: \n"
    "1. Enqueue\n"
    "2. Dequeue\n"
    "3. Display queue\n"
    "4. Generate enqueue\n"
    "5. Generate dequeue\n"
    "***Enter any character to quit***\n\n"
  );

  while(run)
  {
    std::cout << menu;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
      {
        std::cout << "Insert a number:\n";
        std::cin >> value;
        Enqueue(value);
        break;
      }
      
    case 2:
      {
        Dequeue();
        break;
      }

    case 3:
      {
        DisplayCircularQueue();
        break;
      }

    case 4:
      {
        ThreadEnqueue();
        break;
      }
      
    case 5:
      {
        ThreadDequeue();
        break;
      }

    default:
      std::cout << "Exiting... \n";
      run = false;
      break;
    }
  }
}
