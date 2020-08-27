#include<iostream>
using namespace std;
//////////////////Singly LL///////////////////////////////

class Node {
	int marks;
	Node* next;
	Node* first;
	Node* current;
	Node* previous;
public:
	Node():marks(0),next(NULL),first(NULL),current(NULL),previous(NULL){}
	void add(int value);
	void getAll();
	void insert(int value);
	void remove(int value);

};
void Node::add(int value) {

		current = new Node;
		current->next = NULL;
		current->marks = value;
		if (first == NULL)
			first = previous = current;
		else
		{
			previous->next = current;
			previous = current;
		}
}
void Node::getAll() {
	current = first;
	do {
		cout << current->marks << "\t";
		current = current->next;
	} while (current != NULL);
	cout << endl;
}
void Node::insert(int value) {
	bool isInserted = false;
	Node *newnode = new Node;
	newnode->next = NULL;
	newnode->marks=value;
	if (newnode->marks <= first->marks)
	{
		newnode->next = first;
		first = newnode;
	}
	else
	{
		current = previous = first;
		while (current)
		{
			if (newnode->marks >= current->marks)
			{
				previous = current;
				current = current->next;
			}
			else
			{
				newnode->next = current;
				previous->next = newnode;
				isInserted = true;
				break;
			}
		}
		if (!isInserted)
			previous->next = newnode;
	}
}
void Node::remove(int value) {

	if (value == first->marks)
	{
		current = first;
		first = first->next;
		delete current;
	}
	else
	{
		current = previous = first;
		while (current)
		{
			if (value == current->marks)
			{
				previous->next = current->next;
				delete current;
				break;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
}

int main() {
	Node node;
	node.add(75);
	node.add(85);
	node.add(90);
	node.insert(82);
	node.remove(90);
	node.getAll();

	system("pause");
	return 0;
}
