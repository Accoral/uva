#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int MAX_X = 999 + 10;
const int MAX_Y = 18278 + 10;
int G[MAX_X][MAX_Y], vis[MAX_X][MAX_Y];
map < pair < int, int >, vector < pair < int, int > > > mymap;
int dfs ( int x, int y ) {
	if ( vis[x][y] ) return G[x][y];
	int res = 0;
	for ( int i = 0; i < mymap[make_pair(x,y)].size(); ++i )
		res += dfs ( mymap[make_pair(x,y)][i].first, mymap[make_pair(x,y)][i].second );
	vis[x][y] = 1;
	//printf ( "x=%d	y=%d	res=%d\n", x,y,res );
	G[x][y] = res;
	return res;
}
int main ( ) {
	int T, col, row, i, j, k, tmp, x, y;
	char s[1000];//notice!!!
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &col, &row );
		memset ( G, 0, sizeof ( G ) );
		memset ( vis, 0, sizeof ( vis ) );
		mymap.clear ( );
		for ( i = 1; i <= row; ++i )
			for ( j = 1; j <= col; ++j ) {
				scanf ( "%s", s );
				if ( s[0] != '=' ) {
					sscanf ( s, "%d", &tmp );
					G[i][j] = tmp;
					vis[i][j] = 1;
				}
				else {
					int len = strlen ( s );
					x = y = 0;
					for ( k = 1; k < len; ++k ) {
						if ( isalpha ( s[k] ) ) y = y * 26 + s[k] - 'A' + 1;
						else if ( isdigit ( s[k] ) ) x = x * 10 + s[k] - '0';
						else {
							mymap[make_pair(i,j)].push_back (make_pair(x,y));
							x = y = 0;
						}
					}
					mymap[make_pair(i,j)].push_back (make_pair(x,y));
				}
			}
		for ( i = 1; i <= row; ++i ) {
			for ( j = 1; j <= col; ++j ) {
				if ( vis[i][j] ) printf ( "%d", G[i][j] );
				else {
					//for ( k = 0; k < mymap[make_pair(i,j)].size(); ++k ) printf ( "(%d,%d)", mymap[make_pair(i,j)][k].first, mymap[make_pair(i,j)][k].second );
					dfs ( i, j );
					printf ( "%d", G[i][j] );
				}
				if ( j^col ) printf ( " " );
			}
			printf ( "\n" );
		}
	}
}
