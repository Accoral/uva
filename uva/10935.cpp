#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n, i;
int main ( ) {
	while ( scanf ( "%d", &n ) != EOF && n ) {
		queue < int > q;
		vector < int > v;
		for ( i = 1; i <= n; ++i ) q.push ( i );
		//Discarded cards: 1, 3, 5, 7, 4, 2
		printf ( "Discarded cards:" );
		while ( q.size ( ) != 1 ) {
			v.push_back ( q.front ( ) );
			q.pop ( );
			q.push ( q.front ( ) );
			q.pop ( );
		}
		if ( !v.empty ( ) ) {
			for ( i = 0; i < v.size ( ) - 1; ++i ) printf ( " %d,", v[i] ); 
			printf ( " %d", v[i] );
		}
		printf ( "\nRemaining card: %d\n", q.front ( ) );
	}
}
