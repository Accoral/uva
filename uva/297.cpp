#include <stdio.h>
#include <string.h>
#include <stack>
#include <stdlib.h>
using namespace std;
typedef struct Tnode {
	int v;
	struct Tnode *son[4];
}Node;
Node *root;
Node* newnode ( ) {
	Node *u = (Node*)malloc ( sizeof ( Node) );
	if ( u != NULL ) {
		u->v = 0;
		u->son[0] = u->son[1] = u->son[2] = u->son[3] = NULL;
	}
	return u;
}
int sum;
void dfs ( Node *u1, Node *u2, int x ) {
	if ( u1 == NULL && u2 == NULL ) return;
	if ( u1 == NULL ) {
		if ( u2->v ) {
			sum += 1024 >> ( x * 2 );
			return;
		}
		for ( int i = 0; i < 4; ++i ) dfs ( u1, u2->son[i], x + 1 );
		return;
	}
	if ( u2 == NULL ) {
		if ( u1->v ) {
			sum += 1024 >> ( x * 2 );
			return;
		}
		for ( int i = 0; i < 4; ++i ) dfs ( u1->son[i], u2, x + 1 );
		return;
	}
	if ( u1->v || u2->v ) { //fuck this || && 
		sum += 1024 >> ( x * 2 );
		return;
	}
	for ( int i = 0; i < 4; ++i ) dfs ( u1->son[i], u2->son[i], x + 1 );
	return;
}
void build ( stack < Node* > &st, char *s ) {
	int len = strlen ( s );
	for ( int i = len - 1; i >= 0; --i )
		if ( s[i] == 'p' ) {
			Node *u = newnode ( );
			Node *a = st.top ( );
			st.pop ( );
			Node *b = st.top ( );
			st.pop ( );
			Node *c = st.top ( );
			st.pop ( );
			Node *d = st.top ( );
			st.pop ( );
			u->son[0] = a, u->son[1] = b, u->son[2] = c, u->son[3] = d;
			st.push ( u );
		}
		else if ( s[i] == 'e' ) {
			Node *u = newnode ( );
			st.push ( u );
		}
		else {//s[i] == 'f'
			Node *u = newnode ( );
			u->v = 1;
			st.push ( u );
		}
}
int main ( ) {
	int N, len, i;
	char s[100000];
	while ( scanf ( "%d", &N ) != EOF ) {
		while ( N-- ) {
			scanf ( "%s", s );
			stack < Node* > mystack;
			build ( mystack, s );

			scanf ( "%s", s );
			stack < Node* > mystack1;
			build ( mystack1, s );
			sum = 0; dfs ( mystack.top ( ), mystack1.top ( ), 0 );
			printf ( "There are %d black pixels.\n", sum );
		}
	}
}
