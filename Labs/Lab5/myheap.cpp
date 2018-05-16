#include <iostream>
#include "BinaryHeap.h"
using namespace std;

void FillHeap(BinaryHeap<char>& Heap);
void PrintHeap(BinaryHeap<char>& Heap);

int main()
{
	BinaryHeap<char> PQ(50);
	FillHeap(PQ);
	PQ.deleteMin();
	cout << endl;
	//PQ.printLeftSubtree();
	int height = PQ.Height();
	char max = PQ.findMax();

	cout << "Printing Left Subtree of the Root of Heap: ";
	PQ.printLeftSubtree();
	cout << endl;
	cout << "The Height of Heap is : " << height << endl;
	cout << "The Maximum Value of Heap is : " << max << endl;
}

void FillHeap(BinaryHeap<char>& Heap)
{
	char ch;
	for(ch = 'A'; ch <= 'J'; ch++)
	{
		Heap.insert(ch);
	}
}

void PrintHeap(BinaryHeap<char>& Heap)
{
	BinaryHeap<char> localHeap = Heap;
	while (! localHeap.isEmpty())
	{
		cout << localHeap.findMin() << endl;
		localHeap.deleteMin();
	}
}	
