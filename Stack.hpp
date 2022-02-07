#include <iostream>
const int kSize = 10; // Maximum index of array

class Stack
{
  protected:
    int top;

  public:
    Stack();
    virtual void Push(int value);
    virtual int Pop();
    bool IsEmpty();
    bool IsFull();
    virtual void Display();
    virtual void TestCode();
};

class Statics: public Stack
{
  private:
    int static_array[kSize];

  public:
    Statics():Stack() {}
    
    void Push(int value);
    int Pop();
    void Display();
    void TestCode();
};

class Dynamic: public Stack
{
  private:
    int *dyn_array;
  public:
    Dynamic():Stack() { dyn_array = new int[kSize]; }
  
    void Push(int value);
    int Pop();
    void Display();
    void TestCode();
};