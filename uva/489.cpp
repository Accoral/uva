#include <stdio.h>
#include <string.h>
int main ( ) {
	int n, stroke, flag_win, flag_lose;
	char word[2000],guess[2000], copy[2000], unique[26];
	while ( scanf ( "%d", &n ) != EOF && n != -1 ) {
		scanf ( "%s%s", word, guess );
		memcpy ( copy, word, sizeof ( word ) );
		memset ( unique, 0, sizeof ( unique ) );
		printf ( "Round %d\n", n );
		stroke = 0;
		flag_lose = false;
		for ( int i = 0; guess[i]; ++i ) {
			if ( unique[guess[i] - 'a'] ) continue;
			else unique[guess[i] - 'a'] = 1;
			if ( strchr ( word, guess[i] ) ) {
				for ( int j = 0; copy[j]; ++j ) if ( copy[j] == guess[i] ) copy[j] = 'Y';
			}
			else stroke++;
			flag_win = true;
			for ( int j = 0; copy[j]; ++j )
				if ( copy[j] != 'Y' ) { flag_win = false; break; }
			if ( flag_win ) {
				printf ( "You win.\n" );
				flag_win = true;
				break;
			}
			if ( stroke == 7 ) {
				printf ( "You lose.\n" );
				flag_lose = true;
				break;
			}
		}
		if ( !flag_win && !flag_lose ) printf ( "You chickened out.\n" );
	}
}
