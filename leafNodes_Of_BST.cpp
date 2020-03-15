# include <iostream>
using namespace std;
struct Node {
	int data ;
	Node *left ;
	Node * right ;
};
int insertNode ( Node ** root , int data ) {
	if ( * root == NULL ) {
		Node * newNode = new Node ;
 		if ( !newNode)
			return 1;
		newNode -> data = data ;
		newNode -> left = NULL ;            // To create a Binary Node (2 address + 1 data )
		newNode -> right = NULL ;
		(*root) = newNode ;
		return  0 ;
	}
	else if ( (*root) -> data <  data )
		insertNode ( &((*root) -> right) ,data ) ;
	else if ( (*root) -> data >  data )
		insertNode ( &((*root) -> left ) , data ) ;
	else
		return 1 ;
}
int leaf(Node * root , int * k){
	if ( root ) {
		leaf( root -> left ,k);
		leaf( root -> right ,k);
		if(!(root->left) && !(root->right)){
			cout<<root->data<<" , ";
			(*k)++;
		}
	}
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
	int k=0;
	insertNode( &root  ,10 );	insertNode( &root ,8 );		insertNode( &root , 22);     	insertNode( &root , 9);
	insertNode( &root ,4 );      	insertNode( &root , 17);     	insertNode( &root , 7 );      insertNode( &root , 12);
	insertNode( &root  ,15);     	insertNode( &root  ,20);	insertNode( &root ,100);     	insertNode( &root ,91);
	cout <<"\nPreOrder Traversal\n"; 		preOrder( root ) ;
	cout <<"\nThe Leaf Nodes of the BST are\n";	leaf(root,&k);	cout <<"\nNo. of Leaf Noeds are "<<k<<endl;
	return 0;
}






