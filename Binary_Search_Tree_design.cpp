/*
	Name: sukhdev singh
	Date: 19-09-18 22:52
	Description: insert , traverse (preOrder/postOrder/inOrder) ,delete , search
*/
# include <iostream>
using namespace std;
struct Node {
	int data ;
	Node *left ;
	Node * right ;
};
int insertNode ( Node ** root , Node *newNode , int data ) {
	if ( * root == NULL ) {
		(*root) = newNode ;
		return  0 ;
	}
	else if ( (*root) -> data <  data )
		insertNode ( &((*root) -> right) , newNode ,data ) ;
	else if ( (*root) -> data >  data )
		insertNode ( &((*root) -> left ), newNode, data ) ;
	else
		return 1 ;
}
int insertData ( Node ** root , int data ) {
 	Node * newNode = new Node ;
 	if ( !newNode)
		return 1 ;
	newNode -> data = data ;
	newNode -> left = NULL ;            // To create a Binary Node (2 address + 1 data )
	newNode -> right = NULL ;
	insertNode ( &( *root ), newNode , data );
	return 0 ;
}
int preOrder (Node * root ) {
	if ( root ) {
		cout << root->data << "-> " ;
		preOrder ( root -> left );
		preOrder ( root -> right );
	}
	return 0;
}
int inOrder ( Node *root ){
	if (root){
		inOrder (root->left);
		cout << root->data << "-> ";
		inOrder (root->right);
	}
}
int postOrder ( Node *root ){
	if (root){
		postOrder (root->left);
		postOrder (root->right);
		cout << root->data << "-> ";
	}
}
search ( Node * root , int data , Node ** ptr ) {
	if (!root){
		Node *ptr = NULL;
		cout<<"\nData not Found \n";
		return 1 ;
	}
	if ( root ->data > data )
		return search ( root->left, data , &(*ptr) );
	else if ( root -> data < data )
		return search (  root->right , data , &(*ptr) ) ;
	if(root->data==data) {      // equal data
		*ptr = root;
		cout<< "\nData Found \n";
		return 0 ;
	}
}
int deletion (Node ** root , int data ) {
	Node * temp = NULL;
	if (!root){
		return 1;
	}
	if ( (*root)->data > data )
		return deletion (&(*root)->left , data);
	else if ( (*root)->data < data)
		return deletion ( &(*root)->right , data);
	else {
		// data found
		if ( !((*root)->left) && !((*root)->right) ){
			temp = *root;
			*root=NULL;
			delete (temp);
			return 0;
		}
		else if ( !(*root)->left ) {
			temp = *root;
			*root = (*root)->right ;
			delete (temp);
			return 0;
		}
		else if ( !((*root)->right) ){
			temp = *root;
			*root = (*root)->left ;
			delete (temp);
			return 0;
		}
		//if both left & right exist, find Greatest minimal or Least maximal & replace data by either Gm or Lm data
		else{
			// if left exist then only we can find G-minimal
			if ( (*root)->left ) {
				temp = (*root)->left;
				while ( temp->right ) {
					temp = temp->right ;
				}
				(*root)->data = temp->data ; // To replace
				return deletion (&((*root)->left), temp->data);
			}
			// if right exist then only we can find L-maximal
			else {
				temp = (*root)->right;
				while ( temp->left )
					temp = temp->left ;
				(*root)->data = temp->data ; // To replace
				return deletion (&((*root)->right), temp->data);
			}
			
		}
	}
}
int main () {
	Node * root = NULL ;Node *ptr = NULL;
	insertData ( &root , 10 ) ;
	insertData ( &root , 8 ) ;
	insertData ( &root , 22 ) ;
	insertData ( &root , 9 ) ;
	insertData ( &root , 16 ) ;
	insertData ( &root , 30 ) ;
	insertData ( &root , 4 ) ;
		cout<<"\nPreOrder Traversing\n " ;
		preOrder ( root );
	cout<<" \nInOrder Traversing\n" ;
	inOrder ( root );
		cout<<"\nPostOrder Traversing\n " ;
		postOrder ( root );
	insertData ( &root, 15 ) ;
	insertData ( &root, 36 ) ;
	insertData ( &root, 18 ) ;
	insertData ( &root, 42 ) ;
	insertData ( &root, 2 ) ;
//searching
	search (root,22,&ptr);cout<<ptr->data<<"\n "; // ptr will change every time after calling search fun.
	search (root,16,&ptr);cout<<ptr->data<<"\n ";
		cout<<" \nAfter search InOrder Traversing\n" ;
		inOrder ( root );
//deleting
	deletion (&root, 22);
	deletion (&root, 4);
	deletion (&root, 30);
	deletion (&root, 16);
	deletion (&root, 8);
	deletion (&root, 10);
	cout<<"\nAfter deletion InOrder Traversing\n " ;
	inOrder (root);
}
