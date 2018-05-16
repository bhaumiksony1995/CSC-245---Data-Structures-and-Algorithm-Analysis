#include <cstddef> 
#include <iostream>
using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
   	head = NULL;
	length = 0;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
	makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
	// Post: List is empty; all items have been deallocated.
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode = head;
	//Go through list and delete node one by one starting with head
	while (newNode != NULL)
	{
		head = head -> next;
		delete newNode;
		newNode = head;
	}
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
        if(inList(item) == true)
                deleteLocation(location(item));
	else
		cout << "This item is not in the list" << endl;
	/*NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	if (newNode == head)
	{
		delete newNode;
		newNode -> next = head;
	}
	if (newNode.last())
	{
		delete newNode;
		newNode -> back -> next = NULL;
		newNode -> back = newNode -> back;
	}
	else
	{
		delete newNode;
		newNode -> next -> back = newNode -> back;
		newNode -> back -> next = newNode -> next;
	}*/
}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
	if (location(item) == NULL)
		return false;
	else
		return true;
}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	return (head == NULL);
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
	
	NodeType<ItemType>* headPtr = head;
	while (headPtr != NULL)
	{
		cout << headPtr -> info << endl;
		headPtr = headPtr -> next;
	}
}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	if (head == NULL)
	{
		head = newNode;
		newNode -> back = NULL;
		newNode -> next = NULL;
	}

	else
	{
		newNode -> next = head;
		head -> back = newNode;
		head = newNode;
	}
	
	length++;		
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	newNode -> next = NULL;

	if (head == NULL)
	{
		head = newNode;
		newNode -> back = NULL;
	}
	else
	{
		newNode -> back = last();
	}

	length++;
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
	return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	NodeType<ItemType>* location = head;

        while(location != NULL)
        {
                if(location -> info == item)
                        break;

                else
                        location = location -> next;
        }

        return location;	
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	NodeType<ItemType>* last = head;

        while(last -> next != NULL)
                last = last -> next;

        return last;		
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
 	if(head == delPtr)
        {
                delete head;

                if(head -> next == NULL)
                        head = NULL;

                else
                        head = head -> next;
        }

        else
        {
                NodeType<ItemType>* location = head;

                while(location != NULL)
                {
                        if(location == delPtr)
                        {
                                if(location -> next == NULL)
                                        location -> back -> next = NULL;

                                else
                                {
                                        location -> back -> next = location -> next;
                                        location -> next -> back = location -> back;
                                }

                                delete location;
                                location = NULL;
                                break;
                        }

                        location = location -> next;
                }
        }

        length--;
}

	
