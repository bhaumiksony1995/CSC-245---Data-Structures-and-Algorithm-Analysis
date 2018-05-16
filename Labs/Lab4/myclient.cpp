//  myclient.cpp
//  Lab4
//  Created by Bhaumik Sony on 2/15/16.
//  Copyright © 2016 Bhaumik Sony. All rights reserved.


#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
	BinarySearchTree<int> T(0);

	T.insert(6);
	T.insert(2);
	T.insert(8);
	T.insert(4);
	T.insert(1);
	T.insert(3);
	T.insert(9);

	T.postOrder(); //call to post order traversal
	cout << endl;
	cout << "height = " << T.height() << endl; //call to get height
	cout << "NumLeaves = " << T.NumLeaves() << endl;
	bool result = T.isBalanced();
	if (result == true)
		cout << "It's Balanced!" << endl;
	else
		cout << "Not Balanced!" << endl;
	return 0;
}
