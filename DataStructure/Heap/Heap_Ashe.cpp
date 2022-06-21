#include <iostream>
using namespace std;

typedef int element;
#define MAX_ELEMENT 200

class HeapNode
{
	element key;
public:
	HeapNode(element k = 0) :key(k) {}
	void setKey(element k) { key = k; }
	element getKey() { return key; }
	void display() { cout << key; }

};

class MinHeap
{
	HeapNode node[MAX_ELEMENT];
	int size; // 힙의 전체 요소 개수

public:
	MinHeap() :size(0) {};
	
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1;}

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(element key)
	{
		if (isFull())
		{
			cout << "Error: The heap is full. " << endl;
			return;
		}

		int i = ++size;

		// i가 루트노드가 아니고 key가 i의 부모 노드보다 작으면
		while (i != 1 && key < getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove()
	{
		if (isEmpty())
		{
			cout << "Error: The heap is empty." << endl;
			return NULL;
		}

		HeapNode root = node[1];
		HeapNode last = node[size--];
		int parent = 1, child = 2;
		while (child <= size)
		{
			// 현재 노드의 자식 노드 중 더 작은 노드를 찾아: child를 더 작은 자식 노드의 인덱스로 한다.
			if (child<size && 
				getLeft(parent).getKey() > getRight(parent).getKey()) 
				child++;
			// 마지막 노드가 더 큰 자식보다 작으면 이동을 완료한다.
			if (last.getKey() <= node[child].getKey())
				break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}

	void traverse()
	{
		if (isEmpty())
		{
			cout << "Error: The heap is empty. " << endl;
			return;
		}

		int idx = 0;
		while (idx < size)
		{
			cout << idx+1<<"번째 노드: "<< node[idx].getKey() << endl;
			idx++;
		}
	}
};

void main()
{
	MinHeap heap = MinHeap();
	heap.traverse();

	for (int i = 1; i <= 10; i++)
		heap.insert(i * 10);
	heap.traverse();
	
}