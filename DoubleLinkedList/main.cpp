#include <iostream>
#include "tDoubleList.h"

int main()
{
	tDoubleList<int> linkedList;
	

	linkedList.push_front(5);
	linkedList.push_front(5);
	linkedList.push_front(2);
	linkedList.push_back(25);
	linkedList.printList();
	

	
	linkedList.remove(5);

	linkedList.push_front(3);
	linkedList.printList();
}