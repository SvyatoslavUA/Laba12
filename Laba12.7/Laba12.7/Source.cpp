#include <iostream>
#include <iomanip>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;

	int value;
	double doubleValue;
};


void Add(Elem*& first, Elem*& last, int number)
{
	Elem* tmp = new Elem;
	tmp->value = number; 
	tmp->doubleValue = NULL; 

	tmp->link = NULL; 
	if (last != NULL)
		last->link = tmp; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}
void Add(Elem*& first, Elem*& last, double number)
{
	Elem* tmp = new Elem; 
	tmp->doubleValue = number; 
	tmp->value = NULL; 

	tmp->link = NULL; 
	if (last != NULL)
		last->link = tmp; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}

void Print(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link; 

	if (first->value != NULL) 
	{
		cout << first->value << endl;
	}
	else 
	{
		cout << first->doubleValue << endl;
	}
	
		
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
}

void MoveToFirsPlace(Elem*& first, Elem*& last) 
{
	Elem* tmp = first;
	while (tmp -> link -> link != NULL) 
	{
		tmp = tmp->link;
	}

	tmp->link->link = first;
	first = tmp->link;
	tmp->link = NULL;
}

bool IsLastElementInteger(Elem*& first, Elem*& last) 
{
	Elem* tmp = first;
	while (tmp->link != NULL) 
	{
		tmp = tmp->link;
	}
	if (tmp ->value != NULL)
		return true;
	return false;
}

void Alternation(int* B, double* T, int const b, int const t, Elem*& first, Elem*& last)
{
	int j = 0;
	if (b > t) 
	{
		for (int i = 0; i < b; i++) 
		{
			Add(first, last, B[i]);
			if (j < t) 
			{
				Add(first, last, T[j]);
				j++;
			}
		}
	}
	else 
	{
		for (int i = 0; i < t; i++) 
		{
			if (j < b) 
			{
				Add(first, last, B[j]);
				j++;
			}
			Add(first, last, T[i]);

		}
	}
}

int main()
{
	int b = 4;
	int t = 3;

	Elem* first = NULL;
	Elem* last = NULL;
	
	int B[4] = { 12, 16, 19, 20 };
	double T[3] = { 7.6, 9.1, 14.8 };


	cout << "List of integers and real numbers: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << B[i] << "\n";
	}
	for (int i = 0; i < 3; i++)
	{
		cout << T[i] << "\n";
	}
	cout << endl;

	cout << "A list in which the numbers alternate: " << endl;
	Alternation(B, T, b, t, first, last);
	if(IsLastElementInteger(first, last))
	MoveToFirsPlace(first, last);

	while (first != NULL)
		Print(first, last);

	return 0;
}