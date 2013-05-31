#include <stdio.h>
#include <string.h>
char s[25];
int is_reverse ( char x, char y ) {
	if ( ( x == 'A' && y == 'A' ) ||
			( x == 'E' && y == '3' ) ||
			( x == 'H' && y == 'H' ) ||
			( x == 'I' && y == 'I' ) ||
			( x == 'J' && y == 'L' ) ||
			( x == 'L' && y == 'J' ) ||
			( x == 'M' && y == 'M' ) ||
			( x == 'O' && y == 'O' ) ||
			( x == 'S' && y == '2' ) ||
			( x == 'T' && y == 'T' ) ||
			( x == 'U' && y == 'U' ) ||
			( x == 'V' && y == 'V' ) ||
			( x == 'W' && y == 'W' ) ||
			( x == 'X' && y == 'X' ) ||
			( x == 'Y' && y == 'Y' ) ||
			( x == 'Z' && y == '5' ) ||
			( x == '1' && y == '1' ) ||
			( x == '2' && y == 'S' ) ||
			( x == '3' && y == 'E' ) ||
			( x == '5' && y == 'Z' ) ||
			( x == '8' && y == '8' ) )
			return 1;
	else return 0;
}
int mirror ( char x ) {
	if ( x == 'A' ||
			x == 'H' ||
			x == 'I' ||
			x == 'M' ||
			x == 'O' ||
			x == 'T' ||
			x == 'U' ||
			x == 'V' ||
			x == 'W' ||
			x == 'X' ||
			x == 'Y' ||
			x == '1' ||
			x == '8' )
		return 1;
	else return 0;
}
void judge ( char x, char y, bool &palindrome, bool &mirrored) { //1:palindrome 2:mirrored 3:neither
	palindrome = ( x == y );
	mirrored = is_reverse ( x, y );
}
int main ( ) {
	while ( scanf ( "%s", s ) != EOF ) {
		int len = strlen ( s ), flag;
		bool palindrome, mirrored, flag_palindrome, flag_mirrored;
		flag_palindrome = flag_mirrored = 1;
		//palindrome = mirrored = 0;
		for ( int i = 0; i < len / 2; ++i ) {
			judge ( s[i], s[len-i-1], palindrome, mirrored );
			if ( palindrome == 0 ) flag_palindrome = 0;
			if ( mirrored == 0 ) flag_mirrored = 0;
		}
		//printf ( "%d	%d\n", flag_palindrome, flag_mirrored );
		if ( len % 2 && !mirror ( s[len / 2] ) ) flag_mirrored = 0;
		//printf ( "%d	%d\n", flag_palindrome, flag_mirrored );
		if ( !flag_palindrome && !flag_mirrored )
			printf ( "%s -- is not a palindrome.\n", s );
		else if ( flag_palindrome && !flag_mirrored )
			printf ( "%s -- is a regular palindrome.\n", s);
		else if ( !flag_palindrome && flag_mirrored )
			printf ( "%s -- is a mirrored string.\n", s );
		else printf ( "%s -- is a mirrored palindrome.\n", s );
		printf ( "\n" );
	}
}
