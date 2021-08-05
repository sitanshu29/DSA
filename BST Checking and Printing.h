class NodeDetails
{
	public:
	int data, min , max;
};

bool levelOrderIsOfBST(int arr[], int n)		//Check that a given level Order Is OF BST
{
	if (n == 0)
		return true;
	queue <NodeDetails> q;
	NodeDetails temp;
	int i = 0;
	temp.data = arr[i++];
	temp.min = INT_MIN;
	temp.max = INT_MAX;
	q.push(temp);
	while (i < n && !q.empty())
	{
		temp = q.front();
		q.pop();
		if ( arr[i] < temp.data && arr[i] > temp.min)
		{
			NodeDetails newnode;
			newnode.data = arr[i++];
			newnode.max = temp.data;
			newnode.min = temp.min;
			q.push(newnode);
		}
		if ( arr[i] > temp.data && arr[i] < temp.max)
		{
			NodeDetails newnode;
			newnode.data = arr[i++];
			newnode.max = temp.max;
			newnode.min = temp.data;
			q.push(newnode);
		}
	}
	if (i < n && q.empty())
		return false;
	return true;
}

int searchNextGreater(int x, int arr[] , int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > x)
		{
			max = i;
			break;
		}
	}
	for (int i = max+1; i < n; i++)
	{
		if (arr[i] < x)
		return -1;
	}
	return max;
}

bool preOrderIsOfBST(int arr[], int n)
{
	if (n == 0 || n==1)
	return 1;
	int k = searchNextGreater(arr[0], arr, n);	//Returns -1 if the if there is smaller element than arr[0] after getting 1st bigger one else the index of bigger number
	if (k == -1)
		return false;
	else if ( k == 1 || k == 0)
		return preOrderIsOfBST(arr+1, n-1);
	else if (k == n-1)
		return preOrderIsOfBST(arr+1, n-2);
	else
	return preOrderIsOfBST(arr+1, k-1) && preOrderIsOfBST(arr+k, n-k);
}

class NodeDetails
{
	public:
	Node *node;
	int min, max;
}

bool checkBST(Node *head)
{
	if (head== NULL)
		return 1;
	queue <NodeDetails> q;
	NodeDetails nd;
	nd.node = head;
	nd.min = INT_MIN;
	nd.max = INT_MAX;
	NodeDetails temp;
	q.push_back(nd);
	while(q!= NULL)
	{
		nd = q.front();
		q.pop();
		if (nd.node->left)
			if ((nd.node->left->data < nd.node->data) && (nd.node->left->data > nd.min))
			{
				temp.node = nd.node->left;
				temp.min = nd.min;
				temp.max = nd.node->data;
				q.push(temp);
			}
			else
				return 0;
		if (nd.node->right)
			if ((nd.node->right->data > nd.node->data) && (nd.node->right->data < nd.max))
			{
				temp.node = nd.node->right;
				temp.max = nd.max;
				temp.min = nd.node->data;
				q.push(temp);
			}
			else
				return 0;
	}
	return 1;
}

bool checkBSTRec(Node *root, int min, int max) 	//Recuxsrsive function to check for BST... Intial min = INT_Min and max = INT_MAX
{
	if (root == NULL)
		return 1;
	if (root->data < min || root->data > max)
		return 0;
	return checkBSTRec(root->left, min, root->data-1) && checkBSTRec(root->right, root->data+1, max);

}

bool checkDeadEnd(Node *root, int min, int max)
{
	if (root == NULL)
		return 0;
	if (min - max == 1 || min -max == -1)
		return true;
	return (checkDeadEnd(root->left, min, root->data-1) || checkDeadEnd(root->right, root->data+1, max));
}

	
	
	
	
	
	
	
	
	

			