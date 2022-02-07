#include <iostream>
#include "Stack.hpp"

Stack::Stack() 
{
  top = -1;
}

bool Stack::IsEmpty()
{
  if(top == -1)
  {
    return 1;
  } 
  else
  {
    return 0;
  }
}

bool Stack::IsFull()
{
  if(top == kSize - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void Stack::Push(int value)
{
  std::cout << "Push" << std::endl;
}

void Statics::Push(int value)
{
  if(IsFull() == 1)
  {
    std::cout << "\nStack is full." << std::endl;
  }
  else
  {
    static_array[++top] = value;
  }
}

void Dynamic::Push(int value)
{
  if(IsFull() == 1)
  {
    std::cout << "\nStack is full." << std::endl;
  }
  else
  {
    dyn_array[++top] = value;
  }
}

int Stack::Pop()
{
  std::cout << "Pop" << std::endl;
  return 0;
}

int Statics::Pop()
{
  if(IsEmpty() == 1)
  {
    std::cout << "\nStack is empty." << std::endl;
  }
  else
  {
    return static_array[top--];
  }
}

int Dynamic::Pop()
{
  if(IsEmpty() == 1)
  {
    std::cout << "\nStack is empty." << std::endl;
  }
  else
  {
    return dyn_array[top--];
  }
}

void Stack::Display()
{
  std::cout << "Array: " << std::endl;
}

void Statics::Display()
{
  std::cout << "\nStatic array: " << std::endl;
  for(int i = 0; i < top + 1; ++i)
  {
    std::cout << static_array[i] << "  ";
  }
  std::cout << std::endl;
}

void Dynamic::Display()
{
  std::cout << "\nDynamic array: " << std::endl;
  for(int i = 0; i < top + 1; ++i)
  {
    std::cout << dyn_array[i] << "  ";
  }
  std::cout << std::endl;
}

void Stack::TestCode() { }

void Statics::TestCode()
{
  Statics static_array;
  static_array.Display();
  std::cout << "Nothing is pushed." << std::endl;
  std::cout << "Try Pop(): " << std::endl;
  static_array.Pop();

  static_array.Push(1);
  static_array.Push(2);
  static_array.Push(3);
  static_array.Push(4);
  static_array.Push(5);
  static_array.Push(6);
  static_array.Push(7);
  static_array.Push(8);
  static_array.Push(9);
  static_array.Display();

  static_array.Push(10);
  static_array.Display();

  std::cout << "\nPush more than 10" << std::endl;
  static_array.Push(11);
  static_array.Display();

  std::cout << "\nProve FILO: (pop() 4 times)" << std::endl;
  static_array.Pop();
  static_array.Pop();
  static_array.Pop();
  static_array.Pop();
  static_array.Display();
}

void Dynamic::TestCode()
{
  Dynamic *dyn_array = new Dynamic();

  dyn_array->Display();
  std::cout << "Nothing is pushed." << std::endl;
  std::cout << "Try Pop(): " << std::endl;
  dyn_array->Pop();

  dyn_array->Push(1);
  dyn_array->Push(2);
  dyn_array->Push(3);
  dyn_array->Push(4);
  dyn_array->Push(5);
  dyn_array->Push(6);
  dyn_array->Push(7);
  dyn_array->Push(8);
  dyn_array->Push(9);
  dyn_array->Display();

  dyn_array->Push(10);
  dyn_array->Display();

  std::cout << "\nPush more than 10" << std::endl;
  dyn_array->Push(11);
  dyn_array->Display();

  std::cout << "\nProve FILO: (pop() 5 times)" << std::endl;
  dyn_array->Pop();
  dyn_array->Pop();
  dyn_array->Pop();
  dyn_array->Pop();
  dyn_array->Pop();
  dyn_array->Display();

  delete[] dyn_array;
}
