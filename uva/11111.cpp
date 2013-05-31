#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int a[1000000];
int main ( ) {
	int flag, i, j, sum, len = 0, tmp;
	char c;
	while ( scanf ( "%d%c", &a[len++], &c ) == 2 ) {
		if ( c == '\n' ) {
			//for ( i = 0; i < len; ++i ) printf ( "%d ", a[i] ); printf ( "\n" );
			stack < int > mystack;
			flag = 0;
			for ( i = 0; i < len; ++i ) {
				if ( a[i] < 0 ) mystack.push ( a[i] );
				else {
					sum = 0;
					while ( 1 ) {
						if ( mystack.empty ( ) ) {
							flag = 1;
							break;
						}
						if ( mystack.top ( ) + a[i] == 0 ) break;
						tmp = mystack.top ( );
						if ( tmp < 0 ) { flag= 1; break; }
						sum += tmp;
						mystack.pop ( );
					}
					if ( flag ) break;
					if ( sum < a[i] && sum >= 0 ) {
						mystack.pop ( );
						mystack.push ( a[i] );
					}
					else {
						flag = 1;
						break;
					}
				}
			}
			if ( !flag ) {
				while ( !mystack.empty ( ) ) {
					if ( mystack.top ( ) < 0 ) {
						flag = 1;
						break;
					}
					mystack.pop ( );
				}
			}
			if ( flag ) printf ( ":-( Try again.\n" );
			else printf ( ":-) Matrioshka!\n" );
			len = 0;
		}
	}
}
