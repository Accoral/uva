#include <stdio.h>
#include <list>
#include <vector>
using namespace std;
list < int > mylist;
list < int > :: iterator it, it1, it2;
vector < pair < int, int > > ans;
int main ( ) {
	int i, k, m, n;
	while ( scanf ( "%d%d%d", &n, &k, &m ) == 3 && ( n || k || m ) ) {
		ans.clear ( );
		for ( i = 1; i <= n; ++i ) mylist.push_back ( i );
		it1 = mylist.begin ( ); it2 = mylist.end ( ); --it2;
		while ( mylist.size ( ) ) {
			for ( i = 1; i < k; ++i ) {
				++it1;
				if ( it1 == mylist.end ( ) ) it1 = mylist.begin ( );
			}
			for ( i = 1; i < m; ++i ) {
				if ( it2 == mylist.begin ( ) ) it2 = mylist.end ( );
				--it2;
			}
			if ( it1 == it2 ) {
				ans.push_back ( make_pair ( *it1, *it1 ) );
				//printf ( "  %d,", *it1 );
				it1 = mylist.erase ( it1 );
				if ( it1 == mylist.end ( ) ) it1 = mylist.begin ( );
				it2 = it1;
				if ( it2 == mylist.begin ( ) ) it2 = mylist.end ( );
				--it2;
			}
			else {
				ans.push_back ( make_pair ( *it1, *it2 ) );
				//printf ( "  %d  %d,", *it1, *it2 );
				it1 = mylist.erase ( it1 );
				if ( it1 == mylist.end ( ) ) it1 = mylist.begin ( );
				if ( it1 == it2 ) {
					++it1;
					if ( it1 == mylist.end ( ) ) it1 = mylist.begin ( );
				}
				it2 = mylist.erase ( it2 );
				if ( it2 == mylist.begin ( ) ) it2 = mylist.end ( );
				--it2;
			}
			//for ( it = mylist.begin ( ); it != mylist.end ( ); ++it ) printf ( "%d ", *it ); printf ( "\n" );
		}
		for ( i = 0; i < ans.size ( ) - 1; ++i )
			if ( ans[i].first != ans[i].second ) printf ( "%3d%3d,", ans[i].first, ans[i].second );
			else printf ( "%3d,", ans[i].first );
		if ( ans[i].first != ans[i].second ) printf ( "%3d%3d\n", ans[i].first, ans[i].second );
		else printf ( "%3d\n", ans[i].first );
	}
}
