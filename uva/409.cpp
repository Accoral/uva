#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;
char keyword[25][25];
char excuse[25][75];
int main ( ) {
	int k, e, cases = 1;
	while ( scanf ( "%d%d", &k, &e ) != EOF ) {
		for ( int i = 0; i < k; ++i ) scanf ( "%s", keyword[i] );
		getchar ( );
		for ( int i = 0; i < e; ++i ) fgets ( excuse[i], sizeof ( excuse[i] ), stdin );
		//for ( int i = 0;i < k; ++i ) printf ( "%d:	%s\n", i, keyword[i] );
		//for ( int i = 0; i < e; ++i ) printf ( "%d:	%s\n", i, excuse[i] );
		int count[25], max_count = 0;
		memset ( count, 0, sizeof ( count ) );
		for ( int i = 0; i < e; ++i ) {
			char word[75];
			int len = 0;
			for ( int j = 0; excuse[i][j]; ++j )
				if ( isalpha ( excuse[i][j] ) ) {
					word[len++] = tolower ( excuse[i][j] );
				}
				else {
					word[len] = '\0';
					//printf ( "%d:	%s\n", i, word );
					for ( int x = 0; x < k; ++x )
						if ( strcmp ( keyword[x] , word ) == 0 ) {
								++count[i];
								max_count = (max_count < count[i] ? count[i] : max_count);
								break;
						}
					len = 0;
				}
		}
		printf ( "Excuse Set #%d\n", cases++ );
		for ( int i = 0; i < k; ++i ) if ( max_count == count[i] ) printf ( "%s", excuse[i] );
		printf ( "\n" );
	}
}
