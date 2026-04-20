#include "List1.h"
#include <iostream>

int main() {
  List1<int> list;

  // 🔹 test push_back
  list.push_back(5);
  list.push_back(10);
  list.push_back(15);

  // 🔹 test push_front
  list.push_front(1);
  list.push_front(0);

  std::cout << "Lista po push_back i push_front: " << std::endl;

  // 🔹 przejście po liście
  Node<int> *cp = list.get_head(); // potrzebujesz accessor 👀
  while (cp != nullptr) {
    std::cout << cp->data << " ";
    cp = cp->next;
  }
  std::cout << std::endl;

  // 🔹 test free
  list.freeList1();

  std::cout << "Po freeList1 (powinno nic nie wypisac): " << std::endl;

  cp = list.get_head();
  while (cp != nullptr) {
    std::cout << cp->data << " ";
    cp = cp->next;
  }
  std::cout << std::endl;

  return 0;
}