#include<iostream>
#include<queue>

using namespace std;

void insertInto(priority_queue<string> myQueue);
void printQueue(priority_queue<string> myQueue);

int main()
{
	priority_queue<string> myQueue;
	insertInto(myQueue);
}

void insertInto(priority_queue<string> Queue)
{
	Queue.push("Emma");
	Queue.push("Noah");
	Queue.push("Olivia");
	Queue.push("Liam");
	Queue.push("Sophia");
	Queue.push("Mason");
	Queue.push("Isabella");
	Queue.push("Jacob");
	Queue.push("Ava");
	Queue.push("William");
	printQueue(Queue);
}

void printQueue(priority_queue<string> Queue)
{
	while(!Queue.empty())
	{
		cout << Queue.top() << endl;
		Queue.pop();
	}
}
