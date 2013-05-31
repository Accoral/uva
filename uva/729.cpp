#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int h;
vector < string > v;
void dfs ( int n, int* vis, int cur ) {
	int cnt = 0;
	for ( int i = 0; i < n; ++i ) if ( vis[i] ) ++cnt;
	if ( cnt > h ) return;

	if ( cur == n ) {
		int cnt = 0;
		for ( int i = 0; i < n; ++i ) if ( vis[i] ) ++cnt;
		if ( cnt != h ) return;
		string s;
		for ( int i = 0; i < n; ++i )
			if ( vis[i] ) s += "1";
			else s += "0";
		v.push_back ( s );
		//cout << s << "\n";
		return;
	}
	vis[cur] = 1;
	dfs ( n, vis, cur + 1 );
	vis[cur] = 0;
	dfs ( n, vis, cur + 1 );
}
int main ( ) {
	int T, n;
	int vis[20];
	while ( scanf ( "%d", &T ) != EOF ) {
		while ( T-- ) {
			scanf ( "%d%d", &n, &h );
			memset ( vis, 0, sizeof ( vis ) );
			v.clear ( );
			dfs ( n, vis, 0 );
			sort ( v.begin ( ), v.end ( ) );
			for ( int i = 0; i < v.size ( ); ++i ) cout << v[i] << "\n";
			if ( T ) printf ( "\n" );
		}
	}
}
