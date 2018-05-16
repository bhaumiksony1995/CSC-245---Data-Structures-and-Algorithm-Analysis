#include <iostream>

using namespace std;

#include "dictionary.h"
#include "HashTable.h"
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "BinarySearchTree.h"
#include <ctype.h>
#include <sstream>
#include <stdlib.h>

struct BNode
{
	//define operators
	string word;
	int lineNum;
	bool operator < (BNode otherStruct) const
	{
		return (word < otherStruct.word);
	}
};

ostream & operator << (ostream & out, BNode & temp)
{
	out << temp.word << " " << temp.lineNum;
	return out;
}

typedef BinarySearchTree<BNode> BST;
typedef char String[50];

void ReadDict(Dictionary <string>& mainDict);
void ReadFile(Dictionary <string>& mainDict, Dictionary <string>& ignoreDict, string fileName);
void ClearScreen();

int main(int argc, char* args[])
{
	cout << "!@#$%^&*(){} THE SPELL CHECKER PROGRAM {}()*&^%$#@!" << endl;
	cout << "\n";
	Dictionary <string> mainDict("not found", 900);
	Dictionary <string> ignoreDict("not found", 200);
	string fileName = args[1];
	ReadDict(mainDict);
	ReadFile(mainDict, ignoreDict, fileName);

	return 0;
}

void ReadDict(Dictionary <string>& mainDict)
{
	string dict;
	ifstream infile("dict.txt");

	while (getline(infile, dict))
		mainDict.insert(dict);
}

void ReadFile(Dictionary <string>& mainDict, Dictionary <string>& ignoreDict, string fileName)
{
	ifstream infile("myFile.txt");
	string wordLine;
	string str;
	char choice;
	while(getline(infile, wordLine))
	{
		istringstream split(wordLine);
			while(getline(split, str, ' '))
			{
				for (int i = 0; i < str.length(); i++)
				{
					if(!isalpha(str[i]))
					{
						str = str.substr(0, str.length() -1);
					}
					i++;
				}	
					if (mainDict.lookup(str) == "not found")
						{
							cout << "The word (" << str << ")was not found in the dictionary." << endl;
							cout << "\n";
							
							cout << " A) Add the word to the dictionary." << endl;
					        	cout << " B) Do not add the word to the dictionary, but simply ignore it." << endl;
        						cout << " C) Go on to the next word." << endl;
					        	cout << " D) Search for a suggested spelling in the dictionary using the algorithm below." << endl;
					        	cout << " E) Quit spell checking the file." << endl;
					        	cout << " Selection : ";	

							cin >> choice;
							cout << "\n";
							choice = tolower(choice);

							if (choice == 'a')
							{
								ofstream placeOut;
								placeOut.open("dict.txt");
								placeOut << str;
								mainDict.insert(str);
								//break;
							}

							else if (choice == 'b')
							{
								ofstream placeOut;
                                                        	placeOut.open("dict.txt"); //std::ios::app);
                                                        	placeOut << str;
                                                        	ignoreDict.insert(str);
                                                        	//break;
							}

							else if (choice == 'c')
							{	
								continue;
							}

							else if (choice == 'd')
							{

							}	

							else if (choice == 'e')
							{
								exit(0);
							}
						}
			}
	}
cout << "\n ***  All spell checking has been completed  ***" << endl;
cout << "Now exiting program..." << endl;
}

