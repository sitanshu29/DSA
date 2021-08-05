//Tree Functions
#include <bits/std++.h>
using namespace std;

bool checkcontinuous(Node *head)
{
	int flag  = 0;
	if (head = = NULL)
		return true;
	if (head->left == NULL && head->right == NULL)
		return true;
	if (head->left == NULL)
		return (abs(head->data - head->right->data) && checkcontinuous(head->right));
	if (head->rightt == NULL)
		return (abs(head->data - head->left->data) && checkcontinuous(head->left));
	return (abs(head->data - head->left->data) && abs(head->data - head->right->data) && checkcontinuous(head->right) && checkcontinuous(head->left));
}

bool checkfoldable(Node *head)
{
	if (head == NULL)
		return true;
	if (head->left == NULL && head->right == NULL)
		return true;
	else if (head->left == NULL)
		return false;
	else if (head->right == NULL)
		return false;
	
	static queue <Node*> q;
	q.push(head->left);
	q.push(head->right);
	Node *temp1, *temp2;
	while (!q.empty())
	{
		temp1 = q.front();
		q.pop();
		temp2 = q.front();
		q.pop();
		if (temp1->left == NULL && temp2->right == NULL)
		flag = 1;
		else if (temp1->left!= NULL && temp2->right!= NULL)
		{
			q.push(temp1->left);
			q.push(temp2->right);
		}
		else 
			return false;
		if (temp1->right == NULL && temp2->left == NULL)
		flag = 1;
		else if (temp1->right!= NULL && temp2->left!= NULL)
		{
			q.push(temp1->right);
			q.push(temp2->left);
		}
		else 
			return false;
	}
	return true;
}

int evaluate(Node *head)
{
	if (head == NULL)
		return 0;
	else if (isoperator(head->data))
	{
		char x = head->data;
		switch(x)
		{
			case '+' :
			return evaluate(head->left) + evaluate(head->right);
			case '-' :
			return evaluate(head->left) - evaluate(head->right);
			case '*' :
			return evaluate(head->left) * evaluate(head->right);
			case '/' :
			return evaluate(head->left) / evaluate(head->right);
		}
	}
	else 
		return head->data;
}

int sum(Node *temp)
{
	if (temp == NULL)
		return 0;
	else 
		return temp->data + sum(temp->left) + sum(temp->right);
}

bool checksumTree(Node *head)
{
	int ldata = 0, rdata = 0;
	if (head == NULL)
		return 1;
	if (head->left == NULL && head->right == NULL)
		return 1;
	rdata = sum(head->right);	
	ldata = sum(head->left);
	
	if ((head->data == rdata + ldata) && checksumTree(head->left) && checksumTree(head->right))
		return 1;
	return 0;
}  

bool sumCovUncov(Node *head)
{
	if (head == NULL)
		return 1;
	int uncov = 0, treesum;
	Node *temp = head;
	treesum = sumtree(head);
	while (temp!= NULL)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			uncov += temp->data;
			temp = temp->left;
		}
		else if (temp->left)
		{
			uncov+= temp->data;
			temp = temp->left;
		}
		else if (temp->right)
		{
			uncov+= temp->data;
			temp = temp->right;
		}
	}
	temp = head->right;
	while (temp!= NULL)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			uncov += temp->data;
			temp = temp->right;
		}
		else if (temp->right)
		{
			uncov+= temp->data;
			temp = temp->right;
		}
		else if (temp->left)
		{
			uncov+= temp->data;
			temp = temp->left;
		}
	}
	if (treesum == 2*uncov)
		return true;
	else return false;
}

int level(Node *root, Node *node, int lev)
{
	if (root == NULL)
		return 0;
	if (root == a)
		return lev;
	int l = level(root->left, node, lev+1);
	if (l!=0)
		return l;
	return level(root->right, node, lev+1);
}

bool isSibbling(Node *head, Node *a, Node *b)
{
	if(head == NULL)
		return 0;
	return ((head->left == a && head->right == b) || (head->left == b && head->right == a) || isSibbling(head->left, a, b) || isSibbling(head->right, a, b));
}

bool checkcousin(Node *root, Node *a, Node *b)
{
	if (level(root, a, 1) == level(root, b, 1) && (!isSibbling(root, a, b)))
		return true;
	return false;
}

	
bool checkPerfect(Node *head, int height)
{
	if (head == NULL)
		return true;
	else if ((head->left == NULL && head->right == NULL) && height == 0)
		return true;
	else if (head->left && head->right)
		return (checkPerfect(head->left, height-1) && checkPerfect(head->right, height-1));
	else if (head->left || head->right)
		return false;
}

void postOrder(Node *head, queue <Node*> &q)
{
	if (head == NULL)
		return;
	postOrder(head->left, q);
	postOrder(head->right, q);
	q.push(head);
}

bool checkpostUtil(Node *head, queue <Node*> &q)
{
	if (head == NULL)
		return true;
	checkpostUtil(head->right, q);
	checkpostUtil(head->left, q);
	if(head->data == q.front()->data)
	{
		q.pop();
		return true;
	}
	else
		return false;
}


bool checkMirrorTrees(Node *head1, Node *head2)
{
	queue <Node *> q;
	postOrder(head1, q);
	return checkpostUtil(head2, q);
}

bool checkMirrorTrees2(Node *head1, Node *head2)
{
		if(head1 == NULL && head2 == NULL)
			return true;
		if (head1 == NULL || head2 == NULL)
			return false;
		return (head1->data == heaed2->data && checkMirrorTrees2(head1->left, head2->right) && checkMirrorTrees2(head1->right, head2->left));
}

Node *findNode(Node *head, int x)
{
	if (head == NULL)
      return head;
  queue <Node*> q;
  q.push(head);
  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    if (temp->data == x)
      return temp;
    if (temp->left)
      q.push(temp->left);
    if (temp->right)
      q.push(temp->right);
  }
 	Node *temp = NULL;
  return temp;
}

bool checkRoot2Leaf(Node* head, int arr[], int n)
{
	Node *temp = findNode(head, arr[0]);
	if (temp == NULL)
		return 0;
	for (int i = 1; i < n; i++)
	{
		if (temp->left && temp->left->data == arr[i])
			temp = temp->left;
		else if (temp->right && temp->right->data == arr[i])
			temp = temp->right;
		else
			return false;
	}
	return true;
}

int printPath(Node *head, int key)
{
	static stack <Node *> st;
	Node *temp = head;
	while(temp!= NULL);
	{
		st.push(temp);
		temp = temp->left;
		if (temp->data == key)
		{
			st.push(temp);
			display(st);
			return;
		}
	}
	while(!st.empty())
	{
		temp = st.top();
		if (temp == NULL)
		{
			st.pop();
			st.pop();
		}
		else if (temp->right)
		{
			Node *null = NULL;
			st.push(null);
			temp = temp->right;
			if (temp->data == key)
		{
			st.push(temp);
			display(st);
			return;
		}
			while (temp!= NULL)
			{
				st.push(temp);
				temp = temp->left;
				if (temp->data == key)
		{
			st.push(temp);
			display(st);
			return;
		}
			}
		}
		else
		st.pop();
	}
	return 0;
	
}

int height(Node* head)
{
	if (head == NULL)
		return 0;
	int l = height(head->left);
	int r = height(head->right);
	
	if (l> r)
		return l+1;
	else 
		return r+1;
}

void printFullNode(Node *head)
{
	if (head == NULL)
		return;
	if (head->left && head->right)
	cout << head->data << " ";
	
	printFullNode(head->left);
	printFullNode(head->right);
}

void printLevel(Node *head, int lev)
{
	if (head == NULL)
		return;
	if(lev == 0)
		cout << head->data << " ";
	else
	{
		printLevel(head->left, lev-1);
		printLevel(head->right, lev-1);
	}
}

void printNodesBetweenGivenLevels(Node *head, int l, int h)
{
	if (head == NULL)
		return;
	queue <Node *> q;
	q.push(head);
	Node *null = NULL;
	q.push(null);
	
	while(!q.empty())
	{
		Node *temp = q.front();
		int lev = 1;
		q.pop();
		if (temp == NULL)
		{
			lev++;
			
			if(q.empty() || l > h)
				break;
			q.push(null);
		}
		else
		{
			if (lev >= l)
				cout << temp->data << " ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

void displayUtil(stack <Node *>st, int k)
{
	int x = 0
	while(x!= k)
	{
		if(st.top())
		{
			st.pop();
			x++;
		}
		else
			st.pop();
	}
	while (st.top() != NULL)
		st.pop();
	cout << st.top()->data << " ";
}

void printNodesatKdistfromLeaf(Node *head, int k)
{
	if (head == NULL)
		return;
	stack <Node *> st;
	Node *temp = head;
	while(temp !=NULL)
	{
		st.push(temp);
		temp = temp->left;
	}
	while(!st.empty())
	{
		temp = st.top();
		if (temp == NULL)
		{
			st.pop();
			st.pop();
		}
		else if (temp->left== NULL && temp->right == NULL)
		{
			displayUtil(st, k);
			st.pop();
		}
		else
		{
			st.push(NULL);
			temp = temp->right;
			while(temp !=NULL)
			{
				st.push(temp);
				temp = temp->left;
			}
		}
	}
}

void printTopUtill(Node *head, int x, int y, vector<int> &v1, vector <int> &v2, vector <int> &a1, vector <int> &a2 )
{
	if (x< 0)
	{
		if (-1*x > v1.size())
		{
			v1.push_back(y);
			a1.push_back(head->data);
		}
		else if(v1[-1*x] > y)
		{
			v1[-1*x] = y;
			a1[-1*x] = head->data;
		}
	}
	else
	{
		if (x >= v2.size())
		{
			v2.push_back(y);
			a2.push_back(head->data);
		}
		else if(v2[x] > y)
		{
			v2[x] = y;
			a2[x] = head->data;
		}
	}
	if (head->left)
	printTopUtill(head->left, x-1, y+1, v1, v2, a1, a2);
	if (head->right)
	printTopUtill(head->right, x+1, y+1, v1, v2, a1, a2);

}

void printTop(Node *head)
{
	vector <int> v1, v2, a1, a2;
	printTopUtill(head, 0 , 0, v1, v2, a1, a2);
	for (int i = v1.size()-1; i >=0; i--)
	cout << a1[i] << " ";
	for (int i = 0; i < v2.size(); i++)
	cout << a2[i] << " ";
}
void printBottomUtill(Node *head, int x, int y, vector<int> &v1, vector <int> &v2, vector <int> &a1, vector <int> &a2 )
{
	if (x< 0)
	{
		if (-1*x > v1.size())
		{
			v1.push_back(y);
			a1.push_back(head->data);
		}
		else if(v1[-1*x -1] < y)
		{
			v1[-1*x -1] = y;
			a1[-1*x -1] = head->data;
		}
	}
	else
	{
		if (x >= v2.size())
		{
			v2.push_back(y);
			a2.push_back(head->data);
		}
		else if(v2[x] < y)
		{
			v2[x] = y;
			a2[x] = head->data;
		}
	}
	if (head->left)
	printBottomUtill(head->left, x-1, y+1, v1, v2, a1, a2);
	if (head->right)
	printBottomUtill(head->right, x+1, y+1, v1, v2, a1, a2);

}

void printBottom(Node *head)
{
	vector <int> v1, v2, a1, a2;
	printBottomUtill(head, 0 , 0, v1, v2, a1, a2);
	for (int i = v1.size()-1; i >=0; i--)
	cout << a1[i] << " ";
	for (int i = 0; i < v2.size(); i++)
	cout << a2[i] << " ";
}

void printParenthesisTree(Node *head)
{
	if (head)
		cout << head->data ;
	else
		return;
	if (head->left)
	{
		cout << "(";
		printParenthesisTree(head->left);
		cout << ")";
	}
	else if(head->right)
		cout << "()";
	if (head->right)
	{
		cout << "(";
		printParenthesisTree(head->right);
		cout << ")";
	}
}


void fancyTransversal(NOde *head)
{
	queue <Node *> q1, q2;
	if(head == NULL)
		return;
	if (head->left == NULL && head->right == NULL)
	{
		cout << head->data;
		return;
	}
	Node *temp1 = NULL,*temp2 = NULL;
	cout << head->data << " ";
	q1.push(head->left);
	q2.push(head->right);
	
	int level= 2;
	while ( !q1.empty() && !q2.empty())
	{
		for (int i = 0; i < pow(2,level);) 
		{
			temp1 = q1.front();
			q1.pop();
			temp2 = q2.front();
			q2.pop();
			if(temp1->left)
			{	q1.push(temp1->left); i++;}
			if(temp2->right)
			{	q2.push(temp2->right); i++;}
			if(temp1->right)
			{	q1.push(temp1->right); i++;}
			if (temp2->left)
			{	q2.push(temp2->left); i++;}
			cout << temp1->data << " " << temp2->data << " ";
		}
		level++;
	}
}

// Factor Tree

Node* createTree(int x)
{
	Node *head = newNode(x);
	int p = getPrime(x);
	if (x/p != 1)
	{
		head->left = newNode(p);
		head->right = createTree(x/p);
	}
	
	return head;
}

bool checkBinTreeisHeap(Node *head, int index = 0, int count ) //count = no.of nodes
{
	if (head == NULL)
		return true;
	if (index >= count)
		return false;
	return checkBinTreeisHeap(head->left, 2*index +1, count) && checkBinTreeisHeap(head->right, 2*index+2, count);
}

void MorrisTraversal(Node *root)
{
	if (root == NULL)
		return;
	Node *current = root;
	while(current != NULL)
	{
		if (current->left == NULL)
		{
			cout << current->data << " ";
			current = current->right;
		}
		else
		{
			Node *predecessor = current->left;
			while(predecessor->right != NULL && predecessor != current)
				predecessor = predecessor->right;
			if (predecessor->right == NULL)
			{
				predecessor->right = current;
				current = currenrt->left;
			}
			else
			{
				predecessor->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

bool check(n1, n2)
{
	if (n1 == null && n2 == null)
		return true;
	if (n1 == null || n2 == null)
		return false;
	return (check(n1->left, n2->right)&&check(n1->right, n2->left));
}

			
	

				