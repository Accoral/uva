#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int N, sum, indegree[26], outdegree[26], cnt[26], G[26][26], ok, in_out, out_in, vis[26], joint, total;
void dfs ( int u ) {
	vis[u] = 1;
	for ( int v = 0; v < 26; ++v )
		if ( G[u][v] && !vis[v] ) {
			dfs ( v );
			joint++;
		}
}
int main ( ) {
	string s;
	int T, i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &N );
		memset ( indegree, 0, sizeof ( indegree ) );
		memset ( outdegree, 0, sizeof ( outdegree ) );
		memset ( G, 0, sizeof ( G ) );
		memset ( vis, 0, sizeof ( vis ) );
		memset ( cnt, 0, sizeof ( cnt ) );
		int x, y;
		for ( i = 0; i < N; ++i ) {
			cin >> s;
			x = s[0] - 'a';
			y = s[s.length()-1] - 'a';
			outdegree[x]++; indegree[y]++;
			G[x][y] = G[y][x] = cnt[x] = cnt[y] = 1;
		}
		for ( total = i = 0; i < 26; ++i ) if ( cnt[i] ) total++;
		for ( ok = in_out = out_in = sum = i = 0; i < 26; ++i ) {
			if ( indegree[i] || outdegree[i] )
				if ( indegree[i] != outdegree[i] ) {
					++sum;
					if ( indegree[i] - outdegree[i] == 1 ) in_out = 1;
					else if ( outdegree[i] - indegree[i] == 1 ) out_in = 1;
				}
		}
		//printf ( "sum=%d   %d	%d\n", sum, in_out, out_in );
		if ( ( sum == 2 && in_out && out_in ) || sum == 0 ) {
			joint = 1;
			dfs ( x );
			//printf ( "joint=%d\n", joint );
			if ( total == joint ) ok = 1;
		}
		if ( ok ) printf ( "Ordering is possible.\n" );
		else printf ( "The door cannot be opened.\n" );
	}
}
