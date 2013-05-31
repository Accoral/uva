#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > v;
int main ( ) {
	int n, x, i;
	while ( scanf ( "%d", &n ) != EOF ) {
		v.clear ( );
		for ( i = 0; i < n; ++i ) {
			scanf ( "%d", &x );
			v.push_back ( x );
		}
		sort ( v.begin ( ), v.end ( ) );
		//printf ( "n=%d\n",n );
		if ( n % 2 == 0 ) printf ( "%d %d %d\n", v[n/2-1], upper_bound ( v.begin ( ),v.end ( ),v[n/2] ) - lower_bound ( v.begin ( ),v.end(),v[n/2-1] ), v[n/2]-v[n/2-1]+1 );
		else printf ( "%d %d 1\n", v[n/2], upper_bound ( v.begin(),v.end(),v[n/2] ) - lower_bound ( v.begin(),v.end(),v[n/2] ) );
	}
}
