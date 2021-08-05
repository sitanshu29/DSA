// General Tree + Program to construct tree from given string consisting of elements and parenthesis
#include <bits/stdc++.h>

using namespace std;

class Node
{
	public:
	char data;
	Node *fc, *ns;			//fc -> first child, ns -> next sibbling
};

class NodeTree
{
	public:
	int data;
	vector <NodeTree*> child;
};

NodeTree *newnodeT(char x)
{
	NodeTree *temp = new NodeTree();
	temp->data = x;
}

Node *newnode(char x)
{
	Node *temp = new Node();
	temp->data = x;
	temp->fc = temp->ns = NULL;
	return temp;
}

Node *insert(Node *head, char x)
{
	
	Node *root = newnode(x);
	cout << "Enter first child of " << x << "\n";
	char y;
	cin >> y;
	if (y != '.')
		root->fc = insert(root->fc, y);
	cout << "Enter next sibblings of " << x << "\n";
	char z;
	cin >> z;
	if (z != '.')
	root->ns = insert(root->ns, z);
	return root;
}

void print(Node *head)
{
	static queue<Node *> q;
	if (head == NULL)
		return;
	q.push(head);
	cout << head->data << " ";
	print(head->ns);
	cout << endl;
	if (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		print(temp->fc);
	}
}

NodeTree* createTree(string s)		//Iterative
{
	int index = 0;
	NodeTree *head = newnodeT(s[index++]);
	stack <NodeTree*> st;
	st.push(head);
	NodeTree *temp;
	while(!st.empty() && index < s.length())
	{
		temp = st.top();
		if(s[index] != '*')
		{
			temp->child.push_back(newnodeT(s[index++]));
			st.push(temp->child[head->child.size() -1]);
		}
		else
		{
			index++;
			st.pop();
		}
	}
	return head;
}

void printTree(NodeTree *head)
{
	if (head == NULL)
	return;
	cout << static_cast<char>(head->data)<< " \n";
	stack <NodeTree *> st;
	st.push(head);
	NodeTree *temp;
	while(!st.empty())
	{
		temp = st.top();
		st.pop();
		int i = 0;
		while(i < temp->child.size())
		{
			st.push(temp->child[i]);
			cout << static_cast<char>(temp->child[i++]->data) << " ";
		}
		cout << endl;
	}
}

	
int main()
{
	/*Node *head = NULL;
	cout << "Enter root element of tree";
	char x;
	cin >> x;*/
	string s;
	cin >> s;
	NodeTree *head = createTree(s);
	
	printTree(head);
	return 0;
}
