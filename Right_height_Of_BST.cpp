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
		insertNode ( &((*root) -> right) , newNode,data ) ;
	else if ( (*root) -> data >  data )
		insertNode ( &((*root) -> left ) , newNode,data ) ;
	else
		return 1 ;
}
Node* insertData ( int data ) {
 	Node * newNode = new Node ;
 	if ( !newNode)
		return NULL;
	newNode -> data = data ;
	newNode -> left = NULL ;            // To create a Binary Node (2 address + 1 data )
	newNode -> right = NULL ;
//	insertNode ( &( *root ), newNode , data );
	return newNode;
}
int height(Node **root){
	if((*root)->right){
		cout<<"\n root : " <<(*root)->data;
		if((*root)->left)
			cout<<"\n root left : "<<(*root)->left->data;
		else
			cout<<"\n Not root Left";
		if((*root)->right)
			cout<<"\n root right : "<<(*root)->right->data<<endl;
		else
			cout<<"\n Not root right \n";
		  return max( height(&(*root)->right), height(&(*root)->right))+1;
	}
	else
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

	insertNode( &root , insertData(10) ,10 );		insertNode( &root , insertData(8) ,8 );
	insertNode( &root , insertData(15) ,15);     	insertNode( &root , insertData(20) ,20);
	insertNode( &root , insertData(7) ,7 );      	insertNode( &root , insertData(12) ,12);
	insertNode( &root , insertData(22) ,22);     	insertNode( &root , insertData(9) ,9);
	insertNode( &root , insertData(4) ,4 );      	insertNode( &root , insertData(50) ,50);
	insertNode( &root , insertData(100) ,100);     	insertNode( &root , insertData(91) ,91);
	cout <<"\nPreOrder Traversal\n"; 		preOrder( root ) ;
	cout<<"\n \n\nNOTE:- Here some times root and its child will print again, this is becoz of recursion\n\n";
	cout << endl<<endl<< height(&root) ;      cout <<" is the Right Height of the BST \n";
	return 0;
}
