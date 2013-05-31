#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
char s[10][3], vis[10];
char ans[][20] = { "straight-flush","four-of-a-kind","full-house","flush", "straight","three-of-a-kind","two-pairs","one-pair","highest-card"};
vector < pair < int, char > > v;
inline int judge_straight ( vector < pair < int, char > > x ) {
	vector < pair < int, char > > u;
	int tmp;
	for ( int i = 0; i < 5; ++i ) {
		tmp = x[i].first;
		switch ( tmp ) {
			case 0: tmp += 13;
					break;
		}
		u.push_back ( make_pair ( tmp, x[i].second ) );
	}
	sort ( x.begin ( ), x.end ( ) );
	sort ( u.begin ( ), u.end ( ) );
	return ( x[0].first + 1 == x[1].first &&
			x[1].first + 1 == x[2].first &&
			x[2].first + 1 == x[3].first &&
			x[3].first + 1 == x[4].first ) ||
			( u[0].first + 1 == u[1].first &&
			u[1].first + 1 == u[2].first &&
			u[2].first + 1 == u[3].first &&
			u[3].first + 1 == u[4].first );
}
inline int solve ( vector < pair < int, char > > x ) {
	map < int, int > mymap, suit;
	map < int, int > :: iterator it;
	for ( int i = 0; i < 5; ++i ) mymap[x[i].first]++, suit[x[i].second]++;
	if ( judge_straight ( x ) && suit.size ( ) == 1 ) return 0;
	if ( mymap.size ( ) == 2 ) {
		for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
			if ( it->second == 4 ) return 1;
			else if ( it->second == 3 ) return 2;
	}
	if ( suit.size ( ) == 1 ) return 3;
	if ( judge_straight ( x ) ) return 4;
	if ( mymap.size ( ) == 3 ) {
		for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
			if ( it->second == 3 ) return 5;
			else if ( it->second == 2 ) return 6;
	}
	if ( mymap.size ( ) == 4 ) return 7;
	return 8;
}
int main ( ) {
	int i, ok, tmp;
	while ( scanf ( "%s", s[0] ) != EOF ) {
		for ( i = 1; i < 10; ++i ) scanf ( "%s", s[i] );
		for ( i = 0; i < 5; ++i ) vis[i] = 0;
		for ( ; i < 10; ++i ) vis[i] = 1;
		int res, ans_res = 8;
		do {
			for ( i = 9; !vis[i]; --i );
			for ( ok = 1; i > 4; --i ) if ( !vis[i] ) { ok = 0; break; }
			if ( !ok ) continue;
			//for ( i = 0; i < 10; ++i ) if ( vis[i] ) printf ( "%s ", s[i] ); printf ( "\n" );
			for ( v.clear ( ), i = 0; i < 10; ++i ) if ( vis[i] ) {
				switch ( s[i][0] ) {
					case 'A': tmp = 0;
							  break;
					case 'T': tmp = 9;
							  break;
					case 'J': tmp = 10;
							  break;
					case 'Q': tmp = 11;
							  break;
					case 'K': tmp = 12;
							  break;
					default: tmp = s[i][0] - '1';
							 break;
				}
				v.push_back ( make_pair ( tmp, s[i][1] ) );
			}	
			res = solve ( v );
			if ( ans_res > res ) ans_res = res;
		} while ( next_permutation ( vis, vis + 10 ) );
		printf ( "Hand:" );
		for ( i = 0; i < 5; ++i ) printf ( " %s", s[i] );
		printf ( " Deck:" );
		for ( ; i < 10; ++i ) printf ( " %s", s[i] );
		printf ( " Best hand: " );
		printf ( "%s\n", ans[ans_res] );
	}
}
