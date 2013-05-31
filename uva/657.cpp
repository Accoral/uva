#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 55;
int w, h, vis[MAXN][MAXN], cnt;
char mat[MAXN][MAXN];
vector < int > ans;
void dfs1 ( int x, int y ) {
	if ( mat[x][y] != 'X' || vis[x][y] == -1 ) return;
	vis[x][y] = -1;
	dfs1 ( x - 1, y     );
	dfs1 ( x + 1, y     );
	dfs1 ( x    , y - 1 );
	dfs1 ( x    , y + 1 );
}
void dfs ( int x, int y ) {
	if ( mat[x][y] == '.' || vis[x][y] == 1 ) return;
	if ( mat[x][y] == 'X' && vis[x][y] != -1 ) {
		++cnt;
		dfs1 ( x, y );
	}
	vis[x][y] = 1;
	dfs ( x - 1, y     );
	dfs ( x + 1, y     );
	dfs ( x    , y - 1 );
	dfs ( x    , y + 1 );
}
int main ( ) {
	int i, j, throws = 1;
	char s[MAXN];
	while ( scanf ( "%d%d", &w, &h ) != EOF ) {
		if ( w == 0 && h == 0 ) break;
		memset ( vis, 0, sizeof ( vis ) );
		memset ( mat, '.', sizeof ( mat ) );
		for ( i = 0; i < h; ++i ) {
			scanf ( "%s", s );
			//puts ( s );
			for ( j = 0; j < w; ++j ) mat[i+1][j+1] = s[j];
		}
		ans.clear ( );
		for ( i = 1; i <= h; ++i )
			for ( j = 1; j <= w; ++j )
				if ( mat[i][j] != '.' && vis[i][j] == 0 ) {
					//printf ("i=%d j=%d\t\t",i,j);
					cnt = 0;
					dfs ( i, j );
					//printf ("cnt=%d\n",cnt);
					ans.push_back ( cnt );
					/*
					for ( int ii=1;ii<=h;++ii){
						for (int jj=1;jj<=w;++jj)
							printf ( "%d",vis[ii][jj]);
						printf ( "\n" );
					}
					*/
				}
		printf ( "Throw %d\n", throws++ );
		sort ( ans.begin ( ), ans.end ( ) );
		for ( i = 0; i < ans.size ( ) - 1; ++i )
			printf ( "%d ", ans[i] );
		printf ( "%d\n", ans[i] );
		putchar ( '\n' );
	}
}
