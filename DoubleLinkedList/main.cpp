#include <iostream>
#include "tDoubleList.h"

int main()
{
	tDoubleList<int> linkedList;
	
	
	linkedList.push_front(5);
	linkedList.push_front(5);
	linkedList.push_front(2);
	linkedList.push_back(25);
	linkedList.push_back(5);
	linkedList.printList();
	

	linkedList.remove(5);
	

	linkedList.push_front(2);
	linkedList.push_back(2);

	linkedList.printList();

	linkedList.resize(2);

	linkedList.printList();
	linkedList.push_front(7);
	linkedList.push_back(9);

	linkedList.printList();

}