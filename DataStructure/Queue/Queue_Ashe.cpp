#include <iostream>
using namespace std;

typedef int element;

class Node
{
public:
	element data; Node* link;

	Node(element data)
	{
		this->data = data; link = NULL;
	}
};


class Queue
{
	Node* front, *rear;
	int len; int maxSize;
public:
	Queue(int size)
	{
		front = rear = NULL;  len = 0; maxSize = size;
	}
	bool isEmpty() { return (front == NULL); }
	bool isFull() { return(len == (maxSize - 1)); }
	void enQueue(element item)
	{
		Node* newNode = new Node(item);
		if (isFull())
		{
			cout << "Error: 큐 포화 에러" << endl;
			exit(1);
		}
		len++;
		if (front == NULL)
		{
			front = newNode; rear = newNode;
		}
		else
		{
			rear->link = newNode;
			rear = newNode;
		}
	}

	element deQueue()
	{
		element item;
		if (isEmpty())
		{
			cout << "Error: 큐 공백 에러" << endl;
			return NULL;
		}
		len--;
		item = front->data;
		front = front->link;
		if (front == NULL) rear = NULL;
		return item;
	}

	element peek()
	{
		if (isEmpty()) return NULL;
		return front->data;
	}

	void print()
	{
		if(isEmpty())
		{
			cout << "빈 큐입니다." << endl;
			return;
		}
		Node* temp;
		for (temp = front; temp; temp = temp->link)
		{
			cout << temp->data;
			if (temp->link) cout << " -> ";
		}
		cout << endl;
	}

};


void main()
{
	Queue q = Queue(101);
	q.print();

	int i;
	for (i = 1; i <= 10; i++) q.enQueue(i * 10);
	q.print();

	for (i = 0; i < 3; i++) cout << q.deQueue() << "데이터를 삭제했습니다."<<endl;
	q.print();

	return;
}