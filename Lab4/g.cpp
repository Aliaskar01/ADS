#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int data):data(data) , left(nullptr),right(nullptr){}
};

struct BinaryTree{
	Node *root;
	BinaryTree(){
		root = nullptr;
	}
	void insert(int data){
		root = insertRec(root ,data);
	}
	int distance(){
		int maxDiameter = 0;
		height(root , maxDiameter);
		return maxDiameter;
	}
private:
	Node *insertRec(Node *node , int data){
		if(node == nullptr){
			return new Node(data);
		}
		else if(data < node->data){
			node->left = insertRec(node->left , data);
		}
		else if(data > node->data){
			node->right = insertRec(node->right , data);
		}
		return node;
	}
	int height(Node *node , int& maxDiameter){
		if(node == nullptr){
			return 0;
		}
		int left = height(node->left , maxDiameter);
		int right = height(node->right , maxDiameter);

		maxDiameter = max(maxDiameter , left+right);

		return max(left , right)+1;
	}
};	

int main(){

	BinaryTree tree;
	int size;cin >> size;
	for(int i = 0;i < size;++i){
		int num;cin >> num;
		tree.insert(num);
	}
	int result = tree.distance();
	cout << result + 1;

	return 0;
}