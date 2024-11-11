#include <iostream>
#include"List.h"

using namespace std;

int main()
{
	List list;
	list.pushFront(19);
	list.pushFront(191);
	list.pushFront(192);
	list.show();

	List list2 = list;
	list2.show();
}