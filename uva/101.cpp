#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;
int n, a, b, i, pos_a, pos_b, list_a, list_b, tmp;
char op1[10], op2[10];
list < int > mylist[30];
list < int > :: iterator it, b_it, e_it, b_it1, e_it1, tmp_it;
int find_list ( int x ) {
	for ( i = 0; i < n; ++i ) for ( it = mylist[i].begin ( ); it != mylist[i].end ( ); ++it ) if ( *it == x ) return i;
}
int main ( ) {
	while ( scanf ( "%d", &n ) != EOF ) {
		for ( i = 0; i < n; ++i ) {
			mylist[i].clear ( );
			mylist[i].push_back ( i );
		}
		while ( scanf ( "%s", op1 ) == 1 && op1[0] != 'q' ) {
			scanf ( "%d%s%d", &a, op2, &b );
			//printf ( "%s %d %s %d\n", op1, a, op2, b );
			if ( a == b ) continue;
			list_a = find_list ( a ); list_b = find_list ( b );
			if ( list_a == list_b ) continue;
			if ( op1[0] == 'm' ) {
				for ( it = mylist[list_a].begin ( ); it != mylist[list_a].end ( ); ++it ) if ( *it == a ) break;
				b_it = it, e_it = mylist[list_a].end ( );
				for ( ++it; it != mylist[list_a].end ( ); ++it ) mylist[*it].push_front ( *it );
				mylist[list_a].erase ( b_it, e_it );
				if ( op2[1] == 'n' ) {
					for ( it = mylist[list_b].begin ( ); it != mylist[list_b].end ( ); ++it ) if ( *it == b ) break;
					++it;
					b_it = it, e_it = mylist[list_b].end ( );
					for ( ; it != mylist[list_b].end ( ); ++it ) mylist[*it].push_front ( *it );
					mylist[list_b].erase ( b_it, e_it );
				}
				mylist[list_b].push_back ( a );
			}
			else {
				for ( it = mylist[list_a].begin ( ); it != mylist[list_a].end ( ); ++it ) if ( *it == a ) break;
				b_it = it, e_it = mylist[list_a].end ( );
				if ( op2[1] == 'n' ) {
					for ( it = mylist[list_b].begin ( ); it != mylist[list_b].end ( ); ++it ) if ( *it == b ) break;
					++it;
					b_it1 = it, e_it1 = mylist[list_b].end ( );
					for ( ; it != mylist[list_b].end ( ); ++it ) mylist[*it].push_front ( *it );
					mylist[list_b].erase ( b_it1, e_it1 );
				}
				mylist[list_b].insert ( mylist[list_b].end ( ), b_it, e_it );
				mylist[list_a].erase ( b_it, e_it );
			}
			//for ( i = 0; i < n; ++i ) { for ( it = mylist[i].begin ( ); it != mylist[i].end ( ); ++it ) printf ( "%d ", *it ); printf ( "\n" ); }
		}
		for ( i = 0; i < n; ++i ) {
			printf ( "%d:", i );
			for ( it = mylist[i].begin ( ); it != mylist[i].end ( ); ++it ) printf ( " %d", *it );
			printf ( "\n" );
		}
		//printf ( "\n" );//****************************************************************//
	}
}
