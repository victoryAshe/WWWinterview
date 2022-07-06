#include <iostream>
using namespace std;

#define MAX 50
#define MAX_STACK_SIZE 100

class Node
{
public:
	int data;
	Node* link;

	Node(int d) { data = d; }
	Node() {};
};

Node* graph[MAX], w;
bool visited[MAX];

typedef Node element;

class Stack {
public:
	element data[MAX_STACK_SIZE];
	int top; // Stack Pointer

	Stack() { top = -1; } //생성자 함수

	bool is_Empty()
	{
		return(top == -1);
	}

	bool is_full()
	{
		return (top == (MAX_STACK_SIZE - 1));
	}

	void push(element item) // 삽입 함수
	{
		if (is_full())
		{
			cout << "Error: Stack Overflow" << endl;
			return;
		}
		else
		{
			//cout << item << " was added." << endl;
			data[++top] = item;
		}
	}

	element pop()	// 삭제 함수
	{
		if (is_Empty())
		{
			cout << "Error: Stack Underflow" << endl;
			exit(1);
		}
		else
		{
			//cout << data[top] << " was deleted." << endl;
			return data[top--];
		}
	}

	element peek()	//peek 함수(* 삭제는 하지 않고 반환만 하는 함수)
	{
		if (is_Empty())
		{
			cout << "Error: Stack has no element" << endl;
			exit(1);
		}
		else return data[top];
	}
};	// end of Class Stack

Stack stack = Stack();

void print_node(Node node)
{
	cout << node.data << " ";
}

void DFS(int x)
{
	stack.push(Node(x));
	while (!stack.is_Empty())
	{
		Node node = stack.pop();
		x = node.data;

		if (!visited[x]) continue;
		else visited[x] = true;
		
		print_node(node);
		for (w = *graph[x]; &w; w = *w.link)
			if (!visited[w.data])
				stack.push(Node(w.data));
	}
}

void main()
{
	int s = 1;

	DFS(s);
	
}