#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1024;
int dp[MAXN][MAXN];
void LCS ( char* x, char *y, int x_len, int y_len ) {
	int i, j;
	for ( i = 0; i <= x_len; ++i ) dp[i][0] = 0;
	for ( j = 0; j <= y_len; ++j ) dp[0][j] = 0;
	for ( i = 1; i <= x_len; ++i )
		for ( j = 1; j <= y_len; ++j )
			if ( x[i-1] == y[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
}
int main ( ) {
	char x[MAXN], y[MAXN];
	while ( fgets ( x, MAXN, stdin ) ) {
		fgets ( y, MAXN, stdin );
		int x_len = strlen ( x )-1;
		int y_len = strlen ( y )-1;
		LCS ( x, y, x_len, y_len );
		/*
		for ( int i = 0; i < x_len; ++i ) {
			for ( int j = 0; j < y_len; ++j ) 
				printf ( "%d ", dp[i][j] );
			printf ( "\n" );
		}
		*/
		printf ( "%d\n", dp[x_len][y_len] );
	}
}
