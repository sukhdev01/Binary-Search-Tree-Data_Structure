/*
	Name:sukhdev singh
	Date: 28-10-18 12:45
	Description:
*/
#include <iostream>
#include <cmath>
using namespace std;
struct Node {
	int data ;
	Node *left ;
	Node * right ;
};
int insertData ( Node ** root ,int data ) {
	if ( * root == NULL ) {
		Node *newNode = new Node;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = data;
		*root = newNode ;
		return  0 ;
	}
	else if ( (*root) -> data <  data )
		insertData ( &((*root) -> right) ,data ) ;
	else if ( (*root) -> data >  data )
		insertData ( &((*root) -> left ), data ) ;
	else
		return 1 ;
}
int height(Node *root){
	if(root)
		return max( height(root->left), height(root->right) )+1;
	else
		return 0;
}
void levelOrder(Node *root, int level){
	if(level==1)
		cout<<root->data<<endl;
	else if(level>1){
		if(root->left)
			levelOrder(root->left,level-1);
		if(root->right)
			levelOrder(root->right,level-1);
		//cout<<root->data<<" ";
	}
}
int levelTrav(Node *root){
	if(!root)
		return 1;
	int h = height(root);
	for(int i=1; i<=h; i++)
		levelOrder(root,i);
	return 0;
}
int preOrder (Node * root ) {
	if ( root ) {
		cout << root->data << "-> " ;
		preOrder ( root -> left );
		preOrder ( root -> right );
	}
	return 0;
}
int main () {
	Node * root = NULL ;Node *ptr = NULL;
	insertData ( &root , 10) ;	insertData ( &root , 8 ) ;
	insertData ( &root , 22 ) ;	insertData ( &root , 9 ) ;
	insertData ( &root , 16 ) ;	insertData ( &root , 30 ) ;
	insertData ( &root , 4 ) ;	insertData ( &root , 40) ;
	insertData ( &root , 25 ) ;	insertData ( &root , 2 ) ;
	insertData ( &root , 6 ) ;	insertData ( &root , 14 ) ;
	insertData ( &root , 20 ) ;
	cout<<"PreOrder Traversal\n";preOrder(root);
	cout<<"\nlevel Traversal\n";levelTrav(root);

	return 0;
}


