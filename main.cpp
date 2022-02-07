#include <iostream>
#include "Stack.hpp"
#include "LinkedListStack.hpp"
#include "CircularQueue.hpp"

int main(int argc, char *argv[])
{
  bool run = true;
  int number;
  const std::string menu
  (
    "\nSelect a number: \n"
    "1. Static\n"
    "2. Dynamic\n"
    "3. Linked List\n"
    "4. Circular Queue\n"
    "***Enter any character to quit***\n\n"
  );
  while(run)
  {
    std::cout << menu;
    std::cin >> number;
    switch (number)
    {
    case 1:
      {
        Statics st;
        st.TestCode();
        break;
      }

    case 2:
      {
        Dynamic dy;
        dy.TestCode();
        break;
      }

    case 3:
      {
        LinkedList ll;
        ll.CallLinkedList();
        break;
      }

    case 4:
      {
        CircularQueue cq(kSize);
        cq.CallCircularQueue();
        break;
      }

    default:
        std::cout << "Exiting... \n";
        run = false;
        break;
    }
  }
  return 0;
}
