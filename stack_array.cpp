#include <iostream>
using namespace std;
#define MAX 100;

class stack
{
	int head;
	public:
		int a[MAX];
		stack()
		{
			temp = -1;
		}
		bool push(int x);
		int pop();
		bool isEmpty();
};

bool stack::push(int x)
{
	if (head = MAX-1)
	{
		cout << "Overflow\n";
		return;
	}
	else
	a[++head] = x;
	cout << "Element pushed\n";
	return true;
}

int stack::pop()
{
	if (temp < 0)
	{
		cout << "Underflow\n";
		return;
	}
	else
	int x = a[temp--];
	return x;
}

bool stack::isEmpty()
{
	return (top < 0);
}

int main()
{
	stack s;
	s.push(4);
	s.push(3);
	
}
