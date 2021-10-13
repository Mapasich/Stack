#include <iostream>
using namespace std;
const int n = 25;
struct Stack
{
	int M[n];
	int count;
};

void Create(Stack* p)
{
	p->count = 0;
}
void Push(Stack* p)
{
	int value;
	cout << "Enter the element "; cin >> value;
	p->M[p->count] = value;
	p->count++;
}
void Pop(Stack* p)
{
	p->count--;
}
int Full(Stack* p)
{
	if (p->count == 0) return 1;
	else if (p->count == n) return -1;
	else return 0;
}
int Top(Stack* p)
{
	return p->M[p->count - 1];
}
void print(Stack* p)
{
	for (int i = 0; i < p->count; i++)
	{
		printf("%d  ", p->M[i]);
	}
}
int Size(Stack* p)
{
	return p->count;
}

void main()
{
	Stack stack;
	Create(&stack);
	char number;
	do
	{
		cout << "1) Add element" << endl;
		cout << "2) Remove element" << endl;
		cout << "3) Show first element" << endl;
		cout << "4) Size of stack" << endl;
		cout << "5) Show stack on screen" << endl;
		cout << "6) Exit" << endl;
		cout << "Number of comand>"; cin >> number;
		switch (number)
		{
		case '1':
			if (Full(&stack) == -1) cout << endl << "Stack is full\n\n";
			else
			{
				Push(&stack);
				cout << endl << "Element is add to stack\n\n";
			} break;

		case '2':
			if (Full(&stack) == 1) cout << endl << "Stack is empty\n\n";
			else
			{
				Pop(&stack);
				cout << endl << "Element remove from stack\n\n";
			} break;

		case '3':
			if (Full(&stack) == 1) cout << endl << "Stack is empty\n\n";
			else cout << "\nFirst element:" << Top(&stack) << "\n\n";
			break;

		case '4':
			if (Full(&stack) == 1) cout << endl << "Stack is empty\n\n";
			else cout << "\nSize of stack:" << Size(&stack) << "\n\n";
			break;

		case '5':

			cout << "Stack:";
			print(&stack);
			cout << "\n\n";
			break;

		case '6': break;
		default: cout << endl << "Command not found\n\n";
			break;
		}
	} while (number != '0');
	system("pause");
}