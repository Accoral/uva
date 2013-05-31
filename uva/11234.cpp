#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <ctype.h>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 10000 + 10;
class Tnode {
	public:
		char data;
		Tnode *left, *right;
};
queue < Tnode* > myqueue;
vector < char > ans;
void bfs ( Tnode *root ) {
	myqueue.push ( root );
	while ( !myqueue.empty ( ) ) {
		Tnode *tmp;
		tmp = myqueue.front ( );
		ans.push_back ( tmp -> data );
		myqueue.pop ( );
		if ( tmp -> left ) myqueue.push ( tmp -> left );
		if ( tmp -> right ) myqueue.push ( tmp -> right );
	}
}
int main ( ) {
	int T, n, i;
	char s[MAXN], c1, c2;
	while ( scanf ( "%d", &T ) != EOF ) {
		while ( T-- ) {
			scanf ( "%s", s );
			stack < Tnode* > mystack;
			ans.clear ( );
			for ( i = 0; s[i]; ++i )
				if ( islower ( s[i] ) ) {
					Tnode *tmp = new Tnode;
					tmp -> data = s[i];
					tmp -> left = tmp -> right = NULL;
					mystack.push ( tmp );
				}
				else {
					Tnode *n1 = mystack.top ( );
					mystack.pop ( );
					Tnode *n2 = mystack.top ( );
					mystack.pop ( );
					Tnode *tmp = new Tnode;
					tmp -> data = s[i];
					tmp -> left = n2;
					tmp -> right = n1;
					mystack.push ( tmp );
				}
			while ( !myqueue.empty ( ) ) myqueue.pop ( );
			bfs ( mystack.top ( ) );
			for ( int i = ans.size ( ) - 1; i >= 0; --i ) printf ( "%c", ans[i] );printf ( "\n" );
		}
	}
}
