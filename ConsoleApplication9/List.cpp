#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:head(nullptr),tail(nullptr), size(0)
{}

List::~List()
{
	clear();
}

void List::pushBack(int value)
{
	if (head&&tail)
	{
		Node* newNode = new Node(tail, value);
		tail->next = newNode;
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
	}
	size++;
}

void List::pushFront(int value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

void List::clear()
{
	Node* current = head;
	Node* nextNode;

	while (current != nullptr)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}
