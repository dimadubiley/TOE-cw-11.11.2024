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

List::List(const List& other)
{
	if (other.size == 0)
	{
		return;
	}

	Node* current = other.head;
	Node* x;
	Node* y = new Node(current->value);
	head = y;
	tail = y;
	current = current->next;
	while (current)
	{
		x = y;
		y = new Node(current->value);
		y = new Node(current->value);
		x->next = y;
		tail = y;
		current = current->next;
		size++;
	}
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
	if (head && tail)
	{
		Node* newNode = new Node(value, head);
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
	}
	size++;
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

void List::clear()
{
	if (head && tail)
	{
		return;
	}
		Node* current = tail->prev;
	Node* temp = current->prev;
	while (current)
	{
		delete current;
		current = temp;
		temp = temp ? temp->prev : nullptr;
	}
	tail = nullptr;
	head = nullptr;
	size = 0;
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
