#include <iostream>

class CircularQueue
{
  private:
    int front, rear;
    int max_size;
    int queue[10] = {0,};

  public:
    CircularQueue(int);
    ~CircularQueue();
    void Enqueue(int value);
    void Dequeue();
    bool IsEmpty();
    bool IsFull();
    void DisplayCircularQueue();
    void CallCircularQueue();    
    void ThreadEnqueue();
    void ThreadDequeue();
};