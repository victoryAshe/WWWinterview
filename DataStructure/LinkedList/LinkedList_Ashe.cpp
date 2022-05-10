#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head = NULL;
	void insert_Node_front(int data)
	{
		Node* node = new Node(data);
		node->next = head;
		head = node;
	}
	

	void insert_Node_back(int data)
	{
		Node* node = new Node(data);
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			Node* temp = head;

			while (temp->next) temp = temp->next;
			temp->next = node;
		}
		

	}
	void remove_Node(int data)
	{
		if (head == NULL)
		{
			cout << "LinkedList가 비어있습니다." << endl;
			return;
		}
		
		Node* temp;
		for (Node* temp = head; temp; temp = temp->next)
		{
			if (temp->next->data == data)
			{
				temp->next = temp->next->next;
				cout << data << " 노드가 삭제되었습니다." << endl;
				return;
			}
		}

		cout << "해당 데이터를 가진 노드가 없습니다." << endl;

	}
	
	void print()
	{
		if (head == NULL)
		{
			cout << "LinkedList가 비어있습니다." << endl;
			return;
		}

		for (Node* temp = head; temp; temp = temp->next)
		{
			cout << temp->data;
			if (temp->next) cout << " -> ";
		}
		cout << endl;
	}

	LinkedList()
	{
		head = NULL; 
	}
};


void main()
{
	LinkedList list = LinkedList();
	list.print();

	int i;
	for (i = 1; i <= 10; i++)
		list.insert_Node_back(i * 10);
	list.print();

	list.remove_Node(30);
	list.print();

	return;
}