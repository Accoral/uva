#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <ctype.h>
using namespace std;
typedef struct Tnode {
	int v;
	struct Tnode *left, *right;
} Node;
Node* newnode ( ) {
	Node *u = (Node*)malloc ( sizeof ( Node ) );
	if ( u != NULL ) {
		u -> left = NULL;
		u -> right = NULL;
	}
	return u;
}
int sum, flag;
void dfs ( Node *u, int n ) {
	if ( flag ) return;
	if ( u->left==NULL && u->right==NULL && n == sum ) {
		flag = 1; return;
	}
	if ( u->left!=NULL )dfs ( u->left, n + u->left->v );
	if ( u->right!=NULL)dfs ( u->right, n + u->right->v );
}
int main ( ) {
	int left_count, right_count, n, x, i, sign, c;
	while ( scanf ( "%d", &sum ) != EOF ) {
		n = left_count = right_count = 0;
		char s[10000];
		while ( ( c = getchar ( ) ) ) {
			if ( c == ' ' || c == '\n' ) continue;
			if ( c == '(' ) ++left_count;
			else if ( c == ')' ) ++right_count;
			s[n++] = c;
			if ( left_count == right_count ) break;
		}
		s[n] = '\0';
		if ( s[1] == ')' ) {
			printf ( "no\n" );
			continue;
		}
		//printf ( "sum=%d\n%s\n", sum ,s);
		stack < Node* > mystack;
		for ( i = sign = 1, flag = x = 0; i < n; ++i )
			if ( s[i] == '(' ) {
				if ( s[i-1] == ')' ) continue;
				Node *u = newnode ( );
				u -> v = x * sign;
				mystack.push ( u );
				x = 0;
				sign = 1;
			}
			else if ( s[i] == ')' ) {
				if ( s[i-1] == '(' ) mystack.push ( NULL );
				else {
					Node *n1 = mystack.top ( );
					mystack.pop ( );
					Node *n2 = mystack.top ( );
					mystack.pop ( );
					Node *tmp = mystack.top ( );
					mystack.pop ( );
					tmp -> left = n2;
					tmp -> right = n1;
					mystack.push ( tmp );
				}
			}
			else if ( isdigit ( s[i] ) ) x = x * 10 + ( s[i] - '0' );
			else sign = -1;
		dfs ( mystack.top ( ) , mystack.top()->v);
		if ( flag ) printf ( "yes\n" );
		else printf ( "no\n" );
	}
}
