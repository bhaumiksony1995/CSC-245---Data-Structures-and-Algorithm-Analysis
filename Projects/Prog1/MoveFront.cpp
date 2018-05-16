#include<iostream>
#include<list>
#include "dlist.h"
#include <cstdlib>
#include <exception>
using namespace std;

void printMenu(char& sel);
void HeadInsert(DList<int>& list);
void TailInsert(DList<int>& list);
void AccessItem(DList<int>& list);
void FindandMove(DList<int>& list);
void Delete(DList<int>& list);
void PrintList(const DList<int>& list);
void PrintLength(const DList<int>& list);

int main ()
{
	DList<int> list;
	char sel;
	do
	{
		printMenu(sel);
		cin >> sel;
		switch(toupper(sel))
		{
			case 'H' :	HeadInsert(list);	break;
			case 'T' :	TailInsert(list);	break;
			case 'A' :	AccessItem(list);	break;
			case 'D' :	Delete(list);		break;
			case 'P' :	PrintList(list);	break;
			case 'L' :	PrintLength(list);	break;
			case 'Q' :	cout << "\tExiting Program...\n";	exit(0);
			default  : 	cout << "\tError. Try Again." << endl;
		}
	} while(sel != 'Q');

	return 0;
}

void printMenu(char& sel)
{
	cout << "---------------------------------------" << endl;
	cout << "|       Move to Front Algorithm       |" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	cout << "******* Please Select Operation *******" << endl;
	cout << endl;
	cout << " H : Insert an item at front of list" << endl;
	cout << " T : Insert an item at back of list" << endl;
	cout << " A : Access an item in list" << endl;
	cout << " D : Delete an item in list" << endl;
	cout << " P : Print all items in list" << endl;
	cout << " L : Retrieve length of list" << endl;
	cout << " Q : Quit program" << endl;
	cout << endl;
	cout << " Enter Selection: ";
}

void HeadInsert(DList<int>& list)
{
	int num;
        cout << "What number would you like to insert?  ->  ";
	cin >> num;

	if(list.inList(num))
                cout << "This item is already in the list." << endl;
	else
        {
		//cout << "client 1" << endl;
		list.insertHead(num);
		cout << "Done." << endl;
        }
}

void TailInsert(DList<int>& list)
{
	int num;
	cout << "What number would you like to insert?  ->  ";
	cin >> num;

	if (list.inList(num))
                cout << "This item is already in the list." << endl;
        else
        {
                list.appendTail(num);
                cout << "Done." << endl;
        }	
}

void AccessItem(DList<int>& list)
{
	if (list.isEmpty())
	{
		cout << "This list is empty, a number must be entered before accessing" << endl;
	}
	else
	{
		cout << "What number in the list would you like to access?  ->  ";
                FindandMove(list);
	}
}

void FindandMove(DList<int>& list)
{
	int Num;
	cin >> Num;
	if (list.inList(Num))
	{
		list.deleteItem(Num);
		list.insertHead(Num);
		cout << "Item successfully moved." <<  endl;
	}
	else
	{
		cout << "This item is not in the list, please try again." << endl;
	}
}
	
void Delete(DList<int>& list)
{
	int num;
	cout << "What number would you list to delete?  ->  " << endl;
	cin >> num;

	if (list.inList(num))
	{
		list.deleteItem(num);
		cout << "Number successfully deleted" << endl;
	}
	else
	{
		cout << "This item is not in the list, please try again." << endl;
	}
}

void PrintList(const DList<int>& list)
{
	if (!list.isEmpty())
	{
		cout << "Printing list..." << endl;
		list.print();
	}
	else
		cout << "This list is empty, a number must be entered before accessing" << endl;
}

void PrintLength(const DList<int>& list)
{
	int length;
	length = list.lengthIs();
	cout << "The list contains " << length << " item(s)" << endl;
}

