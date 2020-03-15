
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
int deletion (Node **root , int data) {
        if ( !*root )
		return 0;
	else if ((*root) -> data == data ){
		Node *temp = *root;
		*root = NULL ;
		delete (temp);
		return 0;
	}
	else if ((*root)-> data > data)
      		deletion (&(*root)->left,data );
	else
	      	deletion (&(*root) -> right, data);

}
int main () {
	Node * root = NULL ;
	insertData ( &root , 10 ) ;
	insertData ( &root , 8 ) ;
	insertData ( &root , 22 ) ;
	insertData ( &root , 9 ) ;
	insertData ( &root , 16 ) ;
	insertData ( &root , 30 ) ;
	insertData ( &root , 4 ) ;
	insertData ( &root , 45 ) ;
	insertData ( &root , 23 ) ;
	insertData ( &root , 40 ) ;
	insertData ( &root , 50 ) ;
		cout<<"\nPreOrder Traversing\n " ;
		preOrder ( root );
	// change 9 with a node that you want to delete
	deletion( &root ,9);
		cout<<"\nPreOrder Traversing after deleting 4 from Binary Tree \n " ;
		preOrder ( root );cout << " Nothing ";
	return 0;
}
