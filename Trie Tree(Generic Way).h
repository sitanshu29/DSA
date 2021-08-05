#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		map<char, Node*> m;
		int freq;
		Node()
		{
			freq = 0;
		}
};

void insert(Node *root, string s)
{
	Node *temp = root;
	for(int i = 0; i < s.length(); i++)
	{
		if (temp->m.count(s[i]) == 0)
		{
			temp->m[s[i]] = new Node();
			temp = temp->m[s[i]];
		}
		else
		{
			temp = temp->m[s[i]];
		}	
	}
	temp->freq++;
}

bool search(Node *root, string s)
{
	Node *temp = root;
	for(int i = 0; i < s.length(); i++)
	{
		if (temp->m.count(s[i]) == 0)
		return false;
		else
		temp = temp->m[s[i]];
	}
	if (temp->freq > 0)
	return true;
	else 
	return false;
}

void print(Node *root, string s = "")
{
	if (root->freq > 0)
	cout << s << "("<< root->freq << ")  "; 
	for(auto it: root->m)
	{
		print(it.second, s+it.first);
	}
	
}

Node *deleteString(Node *root, string s, int i = 0)
{
	if(!root)
	return NULL;
	
	if (i == s.size())
	{
		root->freq--;
		if (root->m.size() == 0 && root->freq == 0)
		{
			delete(root);
			root = NULL;
		}
		return root;
	}
	
	root->m[s[i]] = deleteString(root->m[s[i]], s, i+1);
	if (root->m[s[i]] == NULL)
	root->m.erase(s[i]);
	
	if (root->m.size() == 0 && root->freq == 0)
	{
		delete(root);
		return NULL;
	}
	return root;
}

int main()
{
	Node *root = new Node();
	string s;
	while(1)
	{
		cin >> s;
		if (s == "0")
		break;
		insert(root, s);
	}
	print(root); cout << endl;
	while(1)
	{
		cin >> s;
		if (s == "0")
		break;
		deleteString(root, s);
	}
	print(root);
}
