#include <iostream>
#include <iomanip>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};


void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value; 
	tmp->link = NULL; 
	if (last != NULL)
		last->link = tmp; 
	last = tmp; 
	if (first == NULL)
		first = tmp; 
}

Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; 
	Info value = first->info; 
	delete first; 
	first = tmp; 
	if (first == NULL)
		last = NULL; 
	return value; 
}

void CleanQueue(Elem*& first, Elem*& last) 
{
	while (first != NULL) {
		Elem* tmp = first->link;
		delete first; 
		first = tmp; 
	}
	if (first == NULL)
		last = NULL; 
}

void SimpleNumber(Elem*& first, Elem*& last, int number)
{
	int div = 2;
	while (number > 1)
	{
		while (number % div == 0)
		{
			enqueue(first, last, div);
			number = number / div;
		}
		div++;
	}
}

bool CheckQueue(Elem*& first, Elem*& last) 
{
	while (first != NULL) {
		int value = dequeue(first, last);
		if (value != 2 && value != 3 && value != 5)
			return false;
	}
	return true;
}

int main()
{
	Elem* first = NULL;
	Elem* last = NULL;

	int number;
	cout << "Enter the value: ";
	cin >> number;
	cout << endl;

	cout << "Numbers that decompose into prime factors multipliers 2, 3, 5." << endl;
	for (int i = 2; i <= number; i++) 
	{
		SimpleNumber(first, last, i);
		if (CheckQueue(first, last)) {
			cout << i << endl;
		}
		
	}
	return 0;
}