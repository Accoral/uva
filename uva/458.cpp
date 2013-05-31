#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main ( ) {
	string s;
	while ( getline ( cin, s ) ) {
		for ( int i = 0; s[i]; ++i )
			printf ( "%c", s[i] - 7 );
		printf ( "\n" );
	}
}
