#include <stdio.h>
#include <list>
#include <map>
#include <string.h>
using namespace std;
map < int, int > mymap;
char op[10];
int count[1000+10];
int main ( ) {
	int t, n, i, x, team_num, cases = 1;
	while ( scanf ( "%d", &t ) != EOF && t ) {
		printf ( "Scenario #%d\n", cases++ );
		mymap.clear ( );
		for ( i = 0; i < t; ++i ) {
			scanf ( "%d", &n );
			while ( n-- ) {
				scanf ( "%d", &x );
				mymap[x] = i;
			}
		}
		memset ( count, 0, sizeof ( count ) );
		list < int > mylist;
		list < int > :: iterator it, tmp_it;
		list < int > :: iterator team_last[1000+10];
		for ( i = 0; i < t; ++i ) team_last[i] = mylist.end ( );
		while ( scanf ( "%s", op ) == 1 && op[0] != 'S' ) {
			if ( op[0] == 'E' ) {
				scanf ( "%d", &x );
				//printf ( "%s	%d\n", op, x );
				team_num = mymap[x];
				//printf ( "x = %d	team = %d\n", x, team_num );
				//printf ( "team_last[%d] = %d	mylist.end ( ) = %d\n", team_num,team_last[team_num], mylist.end ( ) );
				if ( team_last[team_num] == mylist.end ( ) ) {
					mylist.push_back ( x );
					it = mylist.end ( );
					--it;
					team_last[team_num] = it;
				}
				else {
					tmp_it = team_last[team_num]; 
					++tmp_it;
					it = mylist.insert ( tmp_it, x );
					team_last[team_num] = it;
				}
				//for ( it = mylist.begin ( ); it != mylist.end ( ); ++it ) printf ( "%d ",*it );printf ( "\n" );
			}
			else if ( op[0] == 'D' ) {//print
				it = mylist.begin ( );
				printf ( "%d\n", *it );
				team_num = mymap[*it];
				if ( it == team_last[team_num] ) team_last[team_num] = mylist.end ( );
				mylist.pop_front ( );
			}
		}
		printf ( "\n" );
	}
}
