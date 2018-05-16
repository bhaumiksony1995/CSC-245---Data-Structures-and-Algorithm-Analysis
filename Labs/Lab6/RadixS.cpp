#include "Sort.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int maxElemLength(const vector<int>& v);
string intToString(int num);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);

int main()
{
        vector<int> L; //the list to be sorted
        vector<queue<int> > QA(10); //vector of queues indexed 0-9

        L.push_back(49);
        L.push_back(2);
        L.push_back(4569);
        L.push_back(35);
        L.push_back(421);
        L.push_back(12);
        L.push_back(9);
        L.push_back(3269142);
        PrintVector(L);
        int numDigits = maxElemLength(L);
        RadixSort(L, numDigits);
        PrintVector(L);
}

int maxElemLength(const vector<int>& v)
{
        string s;
        s = intToString(v[0]);
        int maxLength = s.length();
        for (int i = 1;  i < v.size();  i++)
        {
                s = intToString(v[i]);
                if (s.length() > maxLength)
                        maxLength = s.length();
        }
        return (maxLength);
}

int maxElemLength(const vector<int>& v)
{       
        string s;
        s = intToString(v[0]);
        int maxLength = s.length();
        for (int i = 1;  i < v.size();  i++)
        {       
                s = intToString(v[i]);
                if (s.length() > maxLength)
                        maxLength = s.length();
        }
        return (maxLength);
}

string intToString(int num)
{       
        string s;
        
        while (num != 0)
        {       
                string empty = "";
                empty = empty + char('0' + (num % 10));
                s = empty + s;
                num /= 10;
        }
        
        return s;
        cout << "after intToString" << endl;
}

int GetDigit(int number, int k)
{
        while (k > 0)
        {
                number/=10;
                k--;
        }

        return (number % 10);
}

vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
        vector<queue<int> > newQueue(10);

        for(int i = 0; i < L.size(); i++)
                newQueue[GetDigit(L[i], k)].push(L[i]);

        return newQueue;
}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
        vector<int> newArray(numVals); //new array that is going to be filled
        int count = 0;

        for(int i = 0; i < 10; i++)
        {
                while(!QA[i].empty())
                {
                        newArray[count] = (QA[i].front());
                        QA[i].pop();
                        count++;
                }
        }
        return newArray;
}

void RadixSort(vector<int>& L, int numDigits)
{
        vector<queue<int> > QA(10);

        for(int i = 0; i <= numDigits; i++)
        {
                QA = ItemsToQueues(L, i);
                L = QueuesToArray(QA, L.size());
        }
}

