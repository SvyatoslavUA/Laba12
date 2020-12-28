#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef int Info;
	
struct Elem
{
	Elem* link;
	Info info;
};

void push(Elem*& top, Info value)
{
		Elem* tmp = new Elem;
		tmp->info = value;
		tmp->link = top;
		top = tmp;
}
void ReadStackFromeFile(Elem*& top, char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		Elem* tmp = new Elem;
		tmp->info = atoi(s.c_str());
		tmp->link = top;
		top = tmp;
	}
}

Info pop(Elem*& top)
{
		Elem* tmp = top->link;
		Info value = top->info;
		delete top;
		top = tmp;
		return value;
}

void InverStack(Elem*& firstTop, Elem*& secondTop) 
{
		if (firstTop == NULL)
			return;
		Elem* tmp = firstTop;
		while (tmp != NULL)
		{
			push(secondTop, tmp->info);
			tmp = tmp->link;
		}
}

void PrintStack(Elem*& top)
{
	Elem* tmp = top;

	while (tmp != NULL) 
	{
		Info value = tmp->info;
		tmp = tmp->link;
		cout << value <<" ";
	}
	cout << endl;
}

int main()
{
	Elem* top = NULL;
	Elem* secondTop = NULL;

	char fname[100];
	int menuItem;
	do {
		cout << endl;
		cout << "Select an action: " << endl << endl;
		cout << " [1] - enter stack from the keyboard" << endl;
		cout << " [2] - read stack from the file" << endl;
		cout << " [3] - output reversed stack to the screen" << endl << endl;
		cout << " [0] - exit and end the program" << endl << endl;

		cout << "Enter a value: "; cin >> menuItem;
		cout << endl;

		switch (menuItem)
		{
		case 1:
			top = NULL;
			secondTop = NULL;
			int value;
			int N;
			cout << "Enter number of elements: ";
			cin >> N;

			cout << "Enter numbers: " << endl;
			for (int i = 1; i <= N; i++) {
				cin >> value;
				push(top, value);
			}
			cout << endl << endl;
			break;
		case 2:
			top = NULL;
			secondTop = NULL;
			cout << "Enter file name: ";
			cin >> fname;
			ReadStackFromeFile(top, fname);
			cout << "File contents: " << endl;
			PrintStack(top);
			cout << endl<< endl;
			break;
		case 3:
			cout << "Reversed stack:" << endl;
			InverStack(top, secondTop);
			PrintStack(secondTop);
			cout << endl << endl;
			break;
		case 0:
			break;
		default:
			cout << "You have entered an incorrect value! "
				"You must enter the number - the number of the selected menu item" << endl;
		}
	} while (menuItem != 0);

	return 0;
}