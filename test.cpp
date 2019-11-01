#include<iostream>
#include<assert.h>
#include<queue>

using namespace std;

template<typename Key, typename Value>
class BST{
private:
	struct Node{
		Node(Key key, Value value){
			left = nullptr;
			right = nullptr;
			this->key = key;	
			this->value = value;
		}
		Node *left;
		Node *right;
		Value  value;
		Key key;
	};
	Node *root;
	int count;
	
	Node* insert(Node *node, Key key, Value value){
		if(node == nullptr){
			count++;
			return new Node(key, value);
		}
		if(node->key == key){
			node->value = value;
			return node;
		}
		else if(node->key > key){
			node->left = insert(node->left, key, value);
			return node;
		}
		else{
			node->right = insert(node->right, key, value);
			return node;
		}

	}		

	Node* Search(Node *node, Key key){
		if(node == nullptr){
			return nullptr;
		}
		
		if(node->key == key){
			return node;
		}

		else if(node->key > key){
			return Search(node->left, key);
		}

		else{
			return Search(node->right, key);
		}
	}
				

	void preOrder(Node *node){
		if(node == nullptr)
			return;
		cout<<node->key<<endl;
		preOrder(node->left);
		preOrder(node->right);
	}


	void inOrder(Node *node){
		if(node == nullptr)
			return;
		inOrder(node->left);
		cout<<node->key<<endl;
		inOrder(node->right);
	}


	void postOrder(Node *node){
		if(node == nullptr)
			return;
		postOrder(node->left);
		postOrder(node->right);
		cout<<node->key<<endl;
	}


	Node* minValue(Node *node){
		if(node->left == nullptr){
			return node;
		}
		return minValue(node->left);
	}

	Node* maxValue(Node *node){
		if(node->right == nullptr){
			return node;
		}
		return maxValue(node->right);
	}

public:
	BST(){
		count = 0;
		root = nullptr;
	}

	~BST(){
	}
	
	void insert(Key key, Value value){
		root = insert(root, key, value);
	}

	Value* Search(Key key){
		assert(count != 0);
		Node *node = Search(root, key);
		return &(node->value);
	}

	void preOrder(){
		preOrder(root);
	}

	void inOrder(){
		inOrder(root);
	}


	void postOrder(){
		postOrder(root);
	}

	
	void levelOrder(){
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			Node *node = q.front();
			cout<<node->key<<endl;
			q.pop();
			if(node->left != nullptr){
				q.push(node->left);
			}
			if(node->right != nullptr){
				q.push(node->right);
			}
		}
	}

	Key minValue(){
		assert(count != 0);
		return minValue(root)->key;
	}

	Key maxValue(){
		assert(count != 0);
		return maxValue(root)->key;
	}


	void deleteMinValue(){
	}

	void deleteMaxValue(){
	}

	int size(){
		return count;
	}

	bool isEmpty(){
		return count == 0;
	}

};



int main(){
	BST<int, int> bst;
	bst.insert(5,50);
	bst.insert(4,40);
	bst.insert(3,30);
	bst.insert(6,60);
	bst.insert(7,70);
	//cout<<bst.size()<<endl;
	//bst.inOrder();
	//bst.preOrder();
	//bst.postOrder();
	//bst.levelOrder();
	cout<<bst.minValue()<<endl;
	cout<<bst.maxValue()<<endl;
	cout<<*bst.Search(4)<<endl;
	return 0;	
}
	
		
