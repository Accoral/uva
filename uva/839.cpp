#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct Tnode {
	int wl, dl, wr, dr;
	struct Tnode *left, *right;
} Node;
Node *root;
Node *newnode ( ) {
	Node *u = (Node*)malloc(sizeof(Node));
	if ( u != NULL ) {
		u->left = NULL;
		u->right = NULL;
	}
	return u;
}
void remove_tree ( Node *u ) {
	if ( u == NULL ) return;
	remove_tree ( u->left );
	remove_tree ( u->right );
	free ( u );
}
int cases, wl, dl, wr, dr, flag;
Node* dfs ( ) {
	scanf ( "%d%d%d%d", &wl, &dl, &wr, &dr );
	Node *u = newnode ( );
	u->wl = wl, u->dl = dl, u->wr = wr, u->dr = dr;
	if ( wl == 0 && wr == 0 ) {
		u->left = dfs ( );
		u->right = dfs ( );
	}
	else if ( wl == 0 ) u->left = dfs ( );
	else if ( wr == 0 ) u->right = dfs ( );
	//if ( wl == 0 ) u->left = dfs ( );
	//if ( wr == 0 ) u->right = dfs ( );
	return u;
}
queue < Node* > q;
void bfs ( ) {
	q.push ( root );
	while ( !q.empty ( ) ) {
		Node *u = q.front ( );
		printf ( "%d %d %d %d\n",u-> wl,u-> dl,u-> wr,u-> dr );
		q.pop ( );
		if ( u->left ) q.push ( u->left );
		if ( u->right ) q.push ( u->right );
	}
}
void judge ( Node* u ) {
	if ( !flag ) return;
	if ( u == NULL ) return;
	if ( u->left != NULL ) {
		judge ( u->left );
		u->wl += u->left->wl + u->left->wr;
	}
	if ( u->right != NULL ) {
		judge ( u->right );
		u->wr += u->right->wl + u->right->wr;
	}
	//printf ( "***%d %d %d %d\n", u->wl, u->dl, u->wr, u->dr );
	if ( u->wl * u->dl != u->wr * u->dr ) flag = 0;
}
int main ( ) {
	while ( scanf ( "%d", &cases ) != EOF ) {
		int first = 0;
		while ( cases-- ) {
			if ( first ) printf ( "\n" );
			else first = 1;
			scanf ( "%d%d%d%d", &wl, &dl, &wr, &dr );
			root = newnode ( );
			root->wl = wl, root->dl = dl, root->wr = wr, root->dr = dr;
			if ( wl == 0 && wr == 0 ) {
				root->left = dfs ( );
				root->right = dfs ( );
			}
			else if ( wl == 0 ) root->left = dfs ( );
			else if ( wr == 0 ) root->right = dfs ( );
			flag = 1;
			judge (root );
			//bfs ( );
			if ( flag ) printf ( "YES" );
			else printf ( "NO" );
			printf ( "\n" );
			remove_tree ( root );
		}
	}
}
