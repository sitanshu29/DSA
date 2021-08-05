// HuffmanCode 
#include <iostream>
using namespace std;

class MinHeapNode
{
	public:
	char data;
	int frequency;
	MinHeapNode *left, *right;
};

class MinHeap
{
	public:
	int size;
	int capacity;
	MinHeapNode **arr;
};

MinHeapNode *newNode(char x, int f)
{
	MinHeapNode *_new = new MinHeapNode();
	_new->data = x;
	_new->frequency = f;
	_new->left = _new->right = NULL;
	return _new;
}

MinHeap *createMinHeap(int cap)
{
	MinHeap *minheap = new MinHeap();
	minheap->capacity = cap;
	minheap->size = 0;
	minheap->arr = new MinHeapNode*[cap];   // Check
	return minheap;
}

void swapMinHeapNode(MinHeapNode** n1, MinHeapNode** n2)
{
	MinHeapNode *temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void minHeapify(MinHeap *minheap, int i)
{
	int smallest = i;
	int left = 2*i +1;
	int right = 2*i +2;
	if (left < minheap->size && minheap->arr[left]->frequency < minheap->arr[smallest]->frequency)
		smallest = left;
	if ( right < minheap->size && minheap->arr[right]->frequency < minheap->arr[smallest]->frequency)
		smallest = right;
	if (smallest != i)
	{
		swapMinHeapNode(&minheap->arr[i], &minheap->arr[smallest]);
		minHeapify(minheap, smallest);
	}
}


void buildMinHeap(MinHeap *minheap)
{
	if (minheap->size == 1)
		return;
	int n = minheap->size - 1;
	for (int i = n-1 ; i>=0; i--)
		minHeapify(minheap, i);
}

MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
	MinHeap *minheap = createMinHeap(size);
	for (int i = 0; i < size; i++)
		minheap->arr[i] = newNode(data[i], freq[i]);
	minheap->size = size;
	buildMinHeap(minheap);
	return minheap;
}

MinHeapNode* extractMin(MinHeap *minheap)
{
	MinHeapNode* temp = minheap->arr[0];
	minheap->arr[0] = minheap->arr[minheap->size - 1];
	--minheap->size;
	minHeapify(minheap, 0);
	return temp;
}

void insertMinHeap(MinHeap *minheap, MinHeapNode* node)
{
	++minheap->size;
	int i = minheap->size -1;
	while(i && node->frequency < minheap->arr[(i-1)/2]->frequency)
	{
		minheap->arr[i] = minheap->arr[(i-1)/2];
		i = (i-1)/2;
	}
	minheap->arr[i] = node;
}

	

MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
	MinHeapNode *left, *right, *top;
	MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
	while(minHeap->size != 1)
	{
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('*', left->frequency + right->frequency);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
}

void printCode(MinHeapNode* root, int array[], int top)
{
	if (root->left)
	{
		array[top] = 0;
		printCode(root->left, array, top+1);
	}
	if(root->right)
	{
		array[top] = 1;
		printCode(root->right, array, top+1);
		
	}
	if (root->left == NULL && root->right == NULL)
	{
		cout << root->data << "\t";
		for(int i = 0; i< top; i++)
			cout << array[i];
		cout << endl;
	}
}


void HuffmanCodes(char data[], int freq[], int size)
{
	MinHeapNode *root = buildHuffmanTree(data, freq, size);
	int array[100], top = 0;
	printCode(root, array, top);
	
}


int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
  
    return 0; 
}