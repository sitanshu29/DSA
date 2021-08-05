// Construction and conversion

void postFromInPre(int in[], int pre[], int n)
{
	int rootIndex = search(in, pre[0], n);
	if (rootIndex!= 0)
		postFromInPre(in, pre+1, rootIndex);
	if (rootIndex != n-1)
		postFromInPre(in+rootIndex+1, pre+rootIndex+1, n-rootIndex-1);
	cout << pre[0] << " ";
}

Node *constructTree(char in[], char pre[], int n) //From Inorder and PreOrder
{
	int rootIndex = search(in, pre[0], n);
	Node *head = newNode(pre[0]);
	if (rootIndex!= 0)
		head->left = constructTree(in, pre+1, rootIndex);
	if (rootIndex != n-1)
		head->right = constructTree(in+rootIndex+1, pre+rootIndex+1, n-rootIndex-1);
	return head;
}

Node *constructTree2(int in[], int lev[], int n) 	//From Inorder and Level Order
{
	int rootIndex = search(in, lev[0], n);
	Node *head = newNode(lev[0]);
	
	if (n==1)
		return head;
	int *l = extract(in,lev, rootIndex, n);
	int *r = extract(in+rootIndex+1, lev, n-rootIndex-1, n);
	
	head->left = constructTree2(in, l, rootIndex);
	head->right = constructTree2(in+rootIndex+1, r, n-rootIndex-1);
	
	return head;
}

Node *constructFromSLL(SLLNode *sllh)
{
	vector <Node *> v;
	while(sllh!= NULL)
	{
		v.pish_back(newNode(sllh->data));
		sllh = sllh->next;
	}
	int size = v.length();
	for (int i = 0; i < size; i++)
	{
		if (2*i +1 < size)
			v[i]->left = v[2*i+1];
		if(2*i+2 < size)
			v[i]->right = v[2*i+2];
	}
	return v[0];
}

Node *construct3(int parent[], int n)    //Construct Binary Tree from given Parent Array representation
{
	Node *createdNode[n] = {NULL};
	for (int i = 0; i < n; i++)
		createdNode[i] = newNode(i);
	Node *head = NULL;
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == -1)
			head = createdNode[i];
		else if (createdNode[parent[i]]->left == NULL)
			createdNode[parent[i]]->left = createdNode[i];
		else if (createdNode[parent[i]]->right == NULL)
			createdNode[parent[i]]->right = createdNode[i];
	}
	return head;
}

Node *TreeUsingString(string s)		//string in the form of 4(2(3)(1)(6(5))
{
	int i =0;
	Node *head = newNode(s[i++] -'0');
	stack <Node*> st;
	st.push(head);
	Node *temp;
	while(i< s.length())
	{
		temp = st.top();
		if (s[i] == '(')
		{
			i++;
			if (!temp->left)
			{
				temp->left = newNode(s[i++] -'0');
				st.push(temp->left);
			}
			else
			{
				temp->right = newNode(s[i++] -'0');
				st.push(temp->right);
			}
		}
		if (s[i] == ')')
		{
			st.pop();
			i++;
		}
	}
	return head;
}

Node *flippedTree(Node *head)		//Using Recursion
{
	if (head == NULL)
		return head;
	if (head->left == NULL && head->right == NULL)
		return head;
	Node *flippedNode = flippedTree(head->left);
	
	head->left->left = head->right;
	head->left->right = head;
	head->left = head->right = NULL;
	return flippedNode;
}


Node *flippedTree2(Node *head)    //Using Iteration





















