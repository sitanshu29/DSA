#include <bits/stdc++.h>
using namespace std;

class treeNode
{
	public:
	int data;
	treeNode *left, *right;
};

void levelOrder(treeNode *root) 
{ 
	if (root == NULL) return; 

	// Create an empty queue for 
	// level order tarversal 
	queue<treeNode *> q; 
	
	// to store front element of 
	// queue. 
	treeNode *curr; 

	// Enqueue Root and NULL node. 
	q.push(root); 
	q.push(NULL); 

	while (q.size() > 1) 
	{ 
		curr = q.front(); 
		q.pop(); 
		
		// condition to check 
		// occurrence of next 
		// level. 
		if (curr == NULL) 
		{ 
		q.push(NULL); 
		cout << "\n"; 
		} 
		
		else { 
			
			// pushing left child of 
			// current node. 
			if(curr->left) 
			q.push(curr->left); 
			
			// pushing rigth child of 
			// current node. 
			if(curr->right) 
			q.push(curr->right); 
			
			cout << curr->data << " "; 
		} 
	} 
} 


treeNode *newnode(int x)
{
	treeNode *temp = new treeNode();
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
}


treeNode* winner(vector<treeNode *> v)
{
	if(v.size() == 1)
		return v.front();
	vector<treeNode*> win;
	int i = 0;
	while( i < v.size())
	{
		if (i+1 < v.size())
		{
			treeNode *temp = newnode(max(v[i]->data, v[i+1]->data));
			temp->left = v[i];
			temp->right = v[i+1];
			win.push_back(temp);
			i +=2;
		}
		else
		{
			treeNode *temp = newnode(v[i]->data);
			temp->left = v[i];
			temp->right = newnode(INT_MIN);
			win.push_back(temp);
			i++;
		}
	}
	return winner(win);
}

		

treeNode *buildWinnerTree(vector<int> arr)
{
	vector <treeNode *> v;
	for(int i = 0; i < arr.size(); i++)
	{
		v.push_back(newnode(arr[i]));
	}
	return winner(v);
}



int findWinner(vector <int> arr)
{
	treeNode *node = buildWinnerTree(arr);
	levelOrder(node);
	cout << endl;
	return node->data;
}

int main()
{
	vector<int> arr;
	bool flag = 1;
	while(flag)
	{
		int x;
		cin >> x;
		if (x == -1)
			flag = 0;
		else
			arr.push_back(x);
	}
	cout << findWinner(arr) << endl;
	return 0;
}

