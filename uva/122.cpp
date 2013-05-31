#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;
const int MAXN = 256;
int failed;
typedef struct Tnode {
	int have_value;
	int v;
	struct Tnode *left, *right;
} Node;
Node *root;
Node* newnode ( ) {
	Node *u = ( Node* ) malloc ( sizeof ( Node ) );
	if ( u != NULL ) {
		u -> have_value = 0;
		u -> left = u -> right = NULL;
	}
	return u;
}
void addnode ( int v, char *s ) {
	int len = strlen ( s );
	Node *u = root;
	for ( int i = 0; i < len; ++i )
		if ( s[i] == 'L' ) {
			if ( u -> left == NULL ) u -> left = newnode ( );
			u = u -> left;
		}
		else if ( s[i] == 'R' ) {
			if ( u -> right == NULL ) u -> right = newnode ( );
			u = u -> right;
		}
	if ( u -> have_value ) failed = 1;
	u -> v = v;
	u -> have_value = 1;
}
void remove_tree ( Node *u ) {
	if ( u == NULL ) return;
	remove_tree ( u -> left );
	remove_tree ( u -> right );
	free ( u );
}
char s[MAXN + 10];
int read_input ( ) {
	failed = 0;
	remove_tree ( root );
	root = newnode ( );
	while ( 1 ) {
		while ( scanf ( "%s", s ) == EOF ) return 0;
		if ( !strcmp ( s, "()" ) ) break;
		int v;
		sscanf ( &s[1], "%d", &v );
		addnode ( v, strchr ( s, ',' ) + 1 );
	}
	return 1;
}
int n, ans[MAXN];
int bfs ( ) {
	queue < Node* > myqueue;
	n = 0;
	myqueue.push ( root );
	while ( !myqueue.empty ( ) ) {
		Node *u = myqueue.front ( );
		if ( !u -> have_value ) return 0;
		ans[n++] = u -> v;
		myqueue.pop ( );
		if ( u -> left != NULL ) myqueue.push ( u -> left );
		if ( u -> right != NULL ) myqueue.push ( u -> right );
	}
	return 1;
}
int main ( ) {
	while ( read_input ( ) ) {
		if ( !bfs ( ) ) failed = 1;
		if ( failed ) printf ( "not complete\n" );
		else {
			for ( int i = 0; i < n-1; ++i ) printf ( "%d ", ans[i] );
			printf ( "%d\n", ans[n-1] );
		}
	}
}
