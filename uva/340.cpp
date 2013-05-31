#include <stdio.h>
#include <string.h>
const int MAXN = 1000 + 10;
int secret[MAXN], guess[MAXN], n, strong, weak;
bool done_secret[MAXN], done_guess[MAXN];;
int main ( ) {
	int game = 1;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "Game %d:\n", game++ );
		for ( int i = 0; i < n; ++i ) scanf ( "%d", secret + i );
		bool flag = 1;
		while ( flag ) {
			for ( int i = 0; i < n; ++i ) scanf ( "%d", guess + i );
			for ( int i = 0; i < n; ++i ) {
				if ( guess[i] == 0 ) flag = 0;
				else flag = 1;
			}
			if ( !flag ) break;
			strong = weak = 0;
			memset ( done_secret, 0, sizeof ( done_secret ) );
			memset ( done_guess, 0, sizeof ( done_guess ) );
			for ( int i = 0; i < n; ++i ) if ( secret[i] == guess[i] ) done_secret[i] = done_guess[i] = 1, ++strong;
			for ( int i = 0; i < n; ++i ) {
				if ( !done_secret[i] )
					for ( int j = 0; j < n; ++j ) if ( !done_guess[j] && secret[i] == guess[j] ) {
						++weak, done_guess[j] = 1;
						break;
					}
			}
			printf ( "    (%d,%d)\n", strong, weak );
		}
	}
}
