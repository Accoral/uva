#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct Tnode {
	int v;
	struct Tnode *left, *right;
} Node;
stack < Node* > mystack;
Node *newnode ( ) {
	Node *u = (Node*)malloc ( sizeof ( Node ) );
	if ( u != NULL ) u->left = u->right = NULL;
	return u;
}
int find ( int *a, int x ) {
	for ( int i = 0; a[i]; ++i ) if ( a[i] == x ) return i;
}
void build ( int n, int *a, int *b ) {
	if ( n <= 0 ) {
		mystack.push ( NULL );
		return;
	}
	//printf ( "%d ", b[n-1] );
	Node *u = newnode ( );
	u->v = b[n-1];
	mystack.push ( u );
	int p = find ( a, b[n-1] );
	build ( n-p-1, a+p+1, b+p );
	build ( p, a, b );

	//printf ( "size=%d\n", mystack.size ( ) );
	Node *n1 = mystack.top ( );
	mystack.pop ( );
	Node *n2 = mystack.top ( );
	mystack.pop ( );
	Node *tmp = mystack.top ( );
	mystack.pop ( );
	tmp->left = n1;
	tmp->right = n2;
	mystack.push ( tmp );
	//printf ( "newsize=%d\n", mystack.size ( ) );
}
queue < Node* > myqueue;
int ans[10000], m=0;
void bfs ( Node *u ) {
	myqueue.push ( u );
	while ( !myqueue.empty ( ) ) {
		u = myqueue.front ( );
		ans[m++]=u->v;
		myqueue.pop ( );
		if ( u->left ) myqueue.push ( u->left );
		if ( u->right ) myqueue.push ( u->right );
	}
}
vector < pair < int, int > > v;
void dfs ( Node *u, int n ) {
	if ( u->left == NULL && u->right == NULL ) {
		v.push_back ( make_pair ( n, u->v ) );
		return;
	}
	if ( u->left ) dfs ( u->left, n + u->left->v );
	if ( u->right ) dfs ( u->right, n + u->right->v );
}
int main ( ) {
	int x, i, a[10000], b[10000], n;
	char c;
	while ( scanf ( "%d", &x) != EOF ) {
		n = 0;
		a[n++] = x;
		while ( scanf ( "%c", &c ) && c != '\n' ) {
			scanf ( "%d", &x );
			a[n++] = x;
		}
		for ( i = 0; i < n; ++i ) scanf ( "%d", b + i );
		//for ( i = 0; i < n; ++i ) printf ( "%d ", a[i] );printf ( "\n" );
		//for ( i = 0; i < n; ++i ) printf ( "%d ", b[i] );printf ( "\n" );
		while ( !mystack.empty ( ) ) mystack.pop ( );
		build ( n, a, b );
		//printf ( "%d\n", mystack.top ( )->v );
		m = 0;
		//bfs (mystack.top ( ) );
		//for ( i = 0; i < m; ++i ) printf ( "%d ", ans[i] ); printf ( "\n" );
		v.clear ( );
		dfs ( mystack.top ( ), mystack.top ( )->v );
		sort ( v.begin ( ), v.end ( ) );
		//for ( i = 0; i < v.size ( ); ++i )
		//printf ( "path=%d leaf=%d\n", v[i].first, v[i].second );
		//printf ( "\n\n" );
		printf ( "%d\n", v[0].second );
	}
}
