/* C++ program to find the median of BST in O(n)
time and O(1) space*/
#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with
given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

int counNodes(struct Node *root){
	struct Node *current, *pre;
	int count = 0;
	if (root == NULL) return count;
	current = root;
	while (current != NULL){
		if (current->left == NULL){
			count++;
			current = current->right;
		}
		else{
			pre = current->left;
			while (pre->right != NULL &&
				pre->right != current)
				pre = pre->right;
			if(pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			else{
				pre->right = NULL;
				count++;
				current = current->right;
			} 
		} 
	} 

	return count;
}

int findMedian(struct Node *root){
if (root == NULL) return 0;
	int count = counNodes(root);
	int currCount = 0;
	struct Node *current = root, *pre, *prev;
	while (current != NULL){
		if (current->left == NULL){
			currCount++;
			if (count % 2 != 0 && currCount == (count+1)/2)
				return prev->data;
			else if (count % 2 == 0 && currCount == (count/2)+1)
				return (prev->data + current->data)/2;
			prev = current;
			current = current->right;
		}
		else{
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;
			if (pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			else{
				pre->right = NULL;
				prev = pre;
				currCount++;
				if (count % 2 != 0 && currCount == (count+1)/2 )
					return current->data;
				else if (count%2==0 && currCount == (count/2)+1)
					return (prev->data+current->data)/2;
				prev = current;
				current = current->right;
			} 
		} 
	} 
}

/* Driver program to test above functions*/
int main()
{

	/* Let us create following BST
				50
			/	 \
			30	 70
			/ \ / \
		20 40 60 80 */
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	cout << "\nMedian of BST is "
		<< findMedian(root);
	return 0;
}