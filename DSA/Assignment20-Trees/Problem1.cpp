// Time Complexity : O(n)
// Space Complexity : O(h) h-> height of tree

#include <bits/stdc++.h>
using namespace std;

class node {
	public:
		int data;
		node *left;
		node *right;

		node(int data) {
			this->data= data;
			this->left= NULL;
			this->right= NULL;
		}

};

int maxSum= INT_MIN;

int sum (node *root) {
	if(!root) return 0;
	int leftSum= sum(root->left);
	int rightSum= sum(root->right);
	maxSum= (maxSum, root->data + leftSum + rightSum);
	return maxSum;
}

int main(){
	node *n1= new node(1);
	node *n2= new node(-2);
	node *n3= new node(3);
	node *n4= new node(4);
	node *n5= new node(5);
	node *n6= new node(6);
	node *n7= new node(7);

	n1->left= n2;
	n1->right= n3;

	n2->left= n4;
	n2->right= n5;

	n3->left= n6;
	n3->right= n7;

	cout << sum(n1) << endl;

	return 0;
}


