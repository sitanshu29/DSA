#include <iostream>
using namespace std;
#define MAX 100

class twoStacks
{
	private:
		int *arr;
		int size;
		int top1, top2;
	public:
		twoStacks(int n)
		{
			size = n;
			arr = new int[n];
			top1 = -1;
			top2 = size;
		}
		void push1(int x)
		{
			if (top1 < top2-1)
			arr[++top1] = x;
			else
			{
				cout << "Stack 1 overflow";
				exit(1);
			}
		}
		void push2(int x)
		{
			if (top2 > top1+1)
			arr[--top2] = x;
			else
			{
				cout << "Stack 2 overflow";
				exit(1);
			}
		}
		int pop1()
		{
			if (top1 < 0)
			{
				cout << "Stack underflow";
				exit(0);
			}
			else
			{
				int x  = arr[top1--];
				return x;
			}
		}
		int pop2()
		{
			if (top2 >= size)
			{
				cout << "Stack 2 underflow";
				exit(0);
			}
			else
			{
				int x = arr[top2++];
				return x;
			}
		}
};
int main() 
{ 
    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is " << ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2(); 
    return 0; 
} 
