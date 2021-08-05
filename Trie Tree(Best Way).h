#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26;

class Node
{
public:
	int end;
	Node *arr[SIZE];
	Node()
	{
		this->end = 0;
		for (int i = 0; i < SIZE; i++)
			this->arr[i] = NULL;
	}
};

void insert(Node *root, string &s)
{
	Node *curr = root;
	for (int i = 0; i < s.length(); i++)
	{
		if (curr->arr[s[i] - 'a'] == NULL)
			curr->arr[s[i] - 'a'] = new Node();

		curr = curr->arr[s[i] - 'a'];
	}
	curr->end++;
}

bool search(Node *root, string &s)
{
	Node *curr = root;
	for (int i = 0; i < s.length(); i++)
	{
		if (curr->arr[s[i] - 'a'] == NULL)
			return false;

		curr = curr->arr[s[i] - 'a'];
	}
	if (curr->end == 0)
		return false;

	return true;
}

void print(Node *root, string &s)
{
	if (root->end > 0)
		cout << s << "-" << root->end << " ";
	for (int i = 0; i < SIZE; i++)
	{
		if (root->arr[i] != NULL)
		{
			s.push_back('a' + i);
			print(root->arr[i], s);
			s.pop_back();
		}
	}
}

Node *deleteString(Node *root, string &s, int i = 0)
{
	if (root == NULL)
		return root;

	if (i == s.length())
	{
		if (root->end == 0)
			return root;

		root->end--;
		if (root->end == 0)
		{
			bool c = 0;
			for (int j = 0; j < SIZE; j++)
			{
				if (root->arr[j] != NULL)
					c = 1;
			}
			if (c == 0)
			{
				delete (root);
				root = NULL;
			}
		}

		return root;
	}

	root->arr[s[i] - 'a'] = deleteString(root->arr[s[i] - 'a'], s, i + 1);

	if (i == 0)
		return root;

	bool c = 0;
	for (int j = 0; j < SIZE; j++)
		if (root->arr[j] != NULL)
		{
			c = 1;
			break;
		}

	if (c == 0 && root->end == 0)
	{
		delete (root);
		root = NULL;
	}
	return root;
}

int main()
{
	Node *root = new Node();
	string s;
	int op;
	while (1)
	{
		cin >> op;
		if (op == -1)
			break;
		else if (op == 1)
		{
			cin >> s;
			insert(root, s);
		}
		else if (op == 2)
		{
			cin >> s;
			root = deleteString(root, s);
			if (root == NULL)
				cout << "YES" << endl;
		}
		else
		{
			s = "";
			print(root, s);
			cout << endl;
		}
	}
}
