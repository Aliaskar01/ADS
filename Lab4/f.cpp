#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int data):data(data),left(nullptr),right(nullptr){}
};

struct BinaryTree{
	Node *root;
	BinaryTree(){
		root = nullptr;
	}
	void insert(int data){
		root = insertRec(root , data);
	}
	void sumTriangle(){
		findTriangle(root);
	}
private:
	Node *insertRec(Node *node , int data){
		if(node == nullptr){
			return new Node(data);
		}
		else if(data < node->data){
			node->left = insertRec(node->left , data);
		}
		else{
			node->right = insertRec(node->right , data);
		}
		return node;
	}
	void  findTriangle(Node *node){
		if(node == nullptr) return ;
		queue<Node*> q;
		q.push(node);
		int sumOfTriangle = 0;
		while(!q.empty()){
			int levelSize = q.size();
			for(int i = 0;i < levelSize;++i){
				Node *current= q.front();
				q.pop();
				if(current->left && current->right){
					sumOfTriangle++;
				}
				if(current->left) q.push(current->left);
				if(current->right)q.push(current->right);
			}
		}
		cout << sumOfTriangle;
		
	}
};

int main(){

	BinaryTree tree;
	int size;cin >> size;
	for(int i = 0;i < size;++i){
		int num;cin >> num;
		tree.insert(num);
	}
	tree.sumTriangle();

	return 0;
}