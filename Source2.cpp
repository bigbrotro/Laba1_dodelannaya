#include <iostream>
#include <locale.h>
#include "Headers.h"





int main()
{	
	std::setlocale(LC_ALL, "rus");
	std::cout << "Adding and removing elements at the end of the list" << std::endl;
	LinkedList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.Print();
	std::cout << "The value has been extracted.: " << list.RemoveAt(3) << std::endl;
	list.Print();


}
