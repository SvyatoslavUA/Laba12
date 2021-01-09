#include <iostream>
using namespace std;
typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
};

Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}
void CountValues(Node* root, int& count)
{
	if (root != NULL)
	{
		++count;
		CountValues(root->right, count);

		CountValues(root->left, count);
	}
}

int main()
{
	int count = 0;
	int N;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	CountValues(root, count);
	cout << endl;
	cout << "Number of elements of binary tree: " << count << endl;
	return 0;
}