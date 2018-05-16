#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>

using namespace std;

#include "SeparateChaining.h"


struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

void insertionSort(string cities[], int numVertices);
void checkInFile(int argc);
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[]);
void printCities(int numVertices, string cities[]);
string setStart(string start, Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
void printRow(int location, VertexType myVertices[]);
int findMin(VertexType myVertices[], int numVertices);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
bool allMarked(int numVertices, VertexType myVertices[]);
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo);
int main(int argc, char* argv[])
{
	checkInFile(argc);	// Checks to see if Filename is given

	// Creation of Input File:
	string filename = argv[1];

	Graph<string> dGraph; 
	int numVertices;
	int numEdges;
	VertexType myVertices [50];
	string cities [50];
	buildDGraph(dGraph, filename, cities, numVertices, numEdges, myVertices);	// Builds the Graph using the data from the external file.
	//printCities(numVertices, cities);	// Prints Cities found in file
	dijkstra(dGraph, numVertices, myVertices);	// Computes Dijkstra's Algorithm:
}

// Checks to see if Filename is given:
void checkInFile(int argc)
{
	if (argc != 2)
	{
		cout << "Please enter file name" << endl;
		exit(1);
	}
}

// Computes Dijkstra's Algorithm:
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[])
{
	int firstNum;
	int counter = 0;
	Queue<string> vertices;
	string origin = setStart(origin, dGraph, numVertices, myVertices);
	cout << "------------------------------------------------" << endl;
        cout << "\tVertex \t\tDistance \tPrevious" << endl;
	cout << "\n";

	while (counter < numVertices)
	{
		if (myVertices[counter].name.compare(origin) == 0)
			firstNum = counter;
		counter++;
	}
		for(int i = 0; i < numVertices; i++)
		{
			dGraph.GetToVertices(origin, vertices);
			assignWeights(dGraph, numVertices, myVertices, firstNum, vertices);
			printRow(firstNum, myVertices);
			
			if(!allMarked(numVertices, myVertices))
			{
				firstNum = findMin(myVertices, numVertices);
				myVertices[firstNum].marked = true;
				origin = myVertices[firstNum].name;
			}
		}
	
}

// Assign weights based on the starting location
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo)
{
	int counter = getTo.size();

	while (counter > 0)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if(myVertices[i].name.compare(getTo.getFront()) == 0 && !myVertices[i].marked)
			{
				if (myVertices[i].distance > myVertices[startingLocation].distance + dGraph.WeightIs(myVertices[startingLocation].name, myVertices[i].name))
				{
					myVertices[i].distance = dGraph.WeightIs(myVertices[startingLocation].name, myVertices[i].name);
					myVertices[i].distance += myVertices[startingLocation].distance;
					myVertices[i].previous = myVertices[startingLocation].name;
					dGraph.MarkVertex(myVertices[i].name);
				}
			}
		}
	getTo.dequeue();
	counter--;
	}
}	

// Checks to see if all Vertices have been marked:
bool allMarked(int numVertices, VertexType myVertices[])
{
	int i = 0;
	
	for (int i = 0; i < numVertices; i++)
	{
		if (myVertices[i].marked == false)
			return false;
	}
	return true;
}

// Builds the Graph using the data from the External File:
void buildDGraph(Graph<string> &dGraph, string filename, string cities[], int &numVertices, int &numEdges, VertexType myVertices[])
{
	ifstream file(filename.c_str());
	string input;
	while (getline(file, input))
	{
		istringstream is(input); //istringstream from input
		string origin; //stores first string as origin
		getline (is, origin, ';');
		string destination; //stores second string as dest
		getline (is, destination, ';');
		string length; //stores last string as length
		getline (is, length, ';');
		int weight = atoi(length.c_str()); // records weight after converting string to int
		bool found = false; //if city is not found
		for (int i = 0; i < numVertices; i++)
		{
			if (myVertices[i].name == origin)
				found = true;
		}
		if (!found)
		{
			VertexType firstVertex = {origin, false, INT_MAX, "N/A"};
			myVertices[numVertices] = firstVertex;
			cities[numVertices] = origin;
			dGraph.AddVertex(origin);
			numVertices++;
		}

		found = false;

		for (int i = 0; i < numVertices; i++)
		{
			if (myVertices[i].name == destination)
				found = true;
		}

		if (!found)
		{
			VertexType secondVertex = {destination, false, INT_MAX, "N/A"};
			myVertices[numVertices] = secondVertex;
			cities[numVertices] = destination;
			dGraph.AddVertex(destination);
			numVertices++;
		}

		dGraph.AddEdge(origin, destination, weight);	
		numEdges++;
	}
	cout << "^^^^^^^^^^^^^   Dijkstra's Algorithm   ^^^^^^^^^^^^^\n" << endl;
	cout << "A weighted graph has been built for these " << numVertices <<  " Cities." << endl;
	//nsertionSort(cities, numVertices);
	printCities(numVertices, cities);
}	



// Prints Cities found in External File:
void printCities(int numVertices,string cities[])
{
	for(int i = 0; i < numVertices; i++)
	{
		if(i%3 != 0)
		{
			if(cities[i].length() > 7)
				cout << cities[i] << "\t";
			else
				cout << cities[i] << "\t\t";
		}
		else
			cout << endl << "\t" << cities[i] << "\t\t" ;
	}
	cout << "\n" << endl;
}

// Sorts the Cities Alphabetically:
void insertionSort(string cities[], int numVertices)
{
	string temp;
	for (int i = 0; i < numVertices; i++)
	{
		temp = cities[i];
		int x = 0;
		for (x = i; x > 0; x--)
		{
			if(temp < cities[x - 1])
				cities[x] = cities[x - 1];		}
	cities[x] = temp;
	}
	printCities(numVertices, cities);
//	cout << "here1" << endl;
}
//Sets the Starting Value in Dijsktra's Algorithm:
string setStart(string start, Graph<string> &dGraph, int numVertices, VertexType myVertices[])
{
	cout << " Please input your starting vertex: ";
	string response;
	getline(cin,response);
	bool isThere = false;
	for (int i = 0;	i < numVertices; i++)
	{
		if (myVertices[i].name.compare(response) == 0)
		{
			start = response;
			myVertices[i].distance = 0;
			myVertices[i].marked = true;
			return start;
		}
	}
	while (!isThere)
	{
		cout << " Starting location does not exist..." << endl;
		cout << " Please input your new vertex: ";
        	string response;
        	cin >> response;
		for (int i = 0; i < numVertices; i++)
        	{
                	if (myVertices[i].name.compare(response) == 0)
			{
                        	start = response;
                        	return start;
                	}
        	}
	}
}

// Finds the minimum non-marked values in VertexType Array:
int findMin(VertexType myVertices[], int numVertices)
{
 		int minWeight = INT_MAX - 1;
                int minThing = -1;
		for (int i = 0; i < numVertices; i++)
                {
                        if (myVertices[i].distance < minWeight && !myVertices[i].marked)
                        {
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }
			else if (myVertices[i].distance == minWeight && !myVertices[i].marked)
        		{
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }

		}        
		return minThing;
}

// Prints a given row in a Summary Table:
void printRow(int location, VertexType myVertices[])
{
	if (myVertices[location].distance != -1)
	cout << setw(14) << myVertices[location].name << setw(18) << myVertices[location].distance << setw(16) << myVertices[location].previous << endl;
	else
	 cout << setw(14) << myVertices[location].name << setw(18) << "Not On Path" << setw(16) << myVertices[location].previous << endl;
}

