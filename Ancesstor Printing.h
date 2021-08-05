//Lowest Common Ancesstor

void getansestorsBST(Node *head, int x, queue<int> &q)
{
	if (head == NULL)
		return;
	else if (head->data == x)
	{
		q.push(head->data);
		return;
	}
	else if (head->data > x)
	{
		q.push(head->data);
		getansestorsBST(head->left, x, q);
	}
	else
	{
		q.push(head->data);
		getansestorsBST(head->right, x, q);
	}
}	

int LCABST(Node *head, int x, int y)
{
	queue <int> q1, q2;
	getancestorsBST(head, x, q1);
	getansestorsBST(head, y, q2);
	int a; bool flag = 0;`	
	while (!q1.empty() && !q2.empty() && flag!=1)
	{
		if (q1.top() == q2.top())
		{
			a = q1.top();
			q1.pop();
			q2.pop();
		}
		else
		{
			flag = 1;
		}
	}
	return a;
}

int LACBSTrecursive(Node *head, int x, int y)
{
	if (head == NULL)
		return;
	if (head->data > x && head->data > y)
		return LACBSTrecursive(head->left, x, y);
	if (head->data < x && head->data < y)
		return LACBSTrecursive(head->right, x, y);
	return head->data;
}

bool findPath(Node *head, int x, vector <Node *> &v)
{
	if (head == NULL)
		return false;
	v.push_back(head);
	if (head->data == x)
	{
		return true;
	}
	if ((head->left && findPath(head->left, x, v))|| (head->right && findPath(head->right, x, v)))
		return true;
	else
	{
		v.pop_back();
		return false;
	}
}


bool printAncesstors(Node *head, int x)
{
	if (head == NULL)
		return false;
	if (head->data == x)
		return true;
	if (printAncesstors(head->left) || printAncesstors(head->right))
	{
		cout << head->data << " ";
		return true;
	}
	else
		return false;
}

	
	
	
	

