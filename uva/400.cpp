#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main ( ) {
	int n, max_len, len, col, row;
	vector < string > s;
	while ( scanf ( "%d", &n ) != EOF ) {
		getchar ( );
		max_len = 0;
		for ( int i = 0; i < n; ++i ) {
			string tmp;
			getline ( cin, tmp );
			s.push_back ( tmp );
			len = tmp.length ( );
			if ( max_len < len ) max_len = len;
		}
		col = ( 60 - max_len ) / ( 2 + max_len ) + 1;
		row = n / col;
		if ( n % col ) ++row;
		//printf ( "maxlen = %d	col = %d	row = %d\n", max_len,col ,row);
		for ( int i = 0; i < 60; ++i ) printf ( "-" ); printf ( "\n" );
		sort ( s.begin ( ), s.end ( ) );
		//for ( int i = 0; i < n; ++i ) printf ( "%s\n", s[i].c_str ( ) ); printf ( "\n" );
		int i, j;
		for ( i = 0; i < row; ++i ) {
			for ( j = 0; j < col - 1; ++j )
				if ( i + j * row < n ) printf ( "%-*s", max_len+2, s[i+j*row].c_str() );
			if ( i+j*row < n ) printf ( "%-*s", max_len, s[i+j*row].c_str() );
			printf ( "\n" );
		}
		s.clear ( );
	}
}
