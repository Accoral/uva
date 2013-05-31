#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
int n, i, len, flag;
char s[135];
int main ( ) {
	while ( scanf ( "%d", &n ) != EOF ) {
		getchar ( );
		while ( n-- ) {
			fgets ( s, 135, stdin );
			//scanf ( "%s", s );
			//printf ( "s=%s\n", s);
			stack < char > mystack;
			flag = 0;
			for ( len = strlen ( s ) - 1, i = 0; !flag && i < len; ++i ) {
				if ( s[i] == '(' || s[i] == '[' ) mystack.push ( s[i] );
				else if ( mystack.empty ( ) ) flag = 1;
				else if ( s[i] == ')' ) {
					if ( mystack.top ( ) == '(' ) mystack.pop ( );
					else flag = 1;
				}
				else {
					if ( mystack.top ( ) == '[' ) mystack.pop ( );
					else flag = 1;
				}
				//printf ( "s[%d]=%c	flag=%d\n", i, s[i], flag );
			}
			if ( !mystack.empty ( ) ) flag = 1;
			if ( flag ) printf ( "No\n" );
			else printf ( "Yes\n" );
		}
	}
}
