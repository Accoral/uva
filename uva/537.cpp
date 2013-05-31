#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main ( ) {
	int n, i;
	double num, P, U, I;
	string s, s_tmp;
	while ( cin >> n ) {
		getchar ( );
		for ( int k = 1; k <= n; ++k ) {
			printf ( "Problem #%d\n", k );
			getline ( cin, s );
			P = U = I = -1;
			for ( i = 0; s[i] != '='; ++i );
			char op = s[i-1];
			s_tmp.clear ( );
			for ( ++i; !isalpha ( s[i] ); ++i ) {
				if ( isdigit ( s[i] ) || s[i] == '.' ) s_tmp += s[i];
			}
			num = 0.0;
			sscanf ( s_tmp.c_str ( ), "%lf", &num );
			//printf ( "num = %lf\n", num );
			switch ( s[i] ) {
				case 'm': num *= 0.001;
						  break;
				case 'k': num *= 1000;
						  break;
				case 'M': num *= 1000000;
						  break;
			}
			switch ( op ) {
				case 'P': P = num;
						  break;
				case 'U': U = num;
						  break;
				case 'I': I = num;
						  break;
			}
			for ( ; s[i] != '='; ++i );
			op = s[i-1];
			s_tmp.clear ( );
			for ( ++i; !isalpha ( s[i] ); ++i ) {
				if ( isdigit ( s[i] ) || s[i] == '.' ) s_tmp += s[i];
			}
			num = 0.0;
			sscanf ( s_tmp.c_str ( ), "%lf", &num );
			//printf ( "num = %lf\n", num );
			switch ( s[i] ) {
				case 'm': num *= 0.001;
						  break;
				case 'k': num *= 1000;
						  break;
				case 'M': num *= 1000000;
						  break;
			}
			switch ( op ) {
				case 'P': P = num;
						  break;
				case 'U': U = num;
						  break;
				case 'I': I = num;
						  break;
			}
			//printf ( "U = %lf	I = %lf	P = %lf\n", U, I, P );
			if ( P < 0 ) printf ( "P=%.2lfW\n", U*I );
			else if ( I < 0 ) printf ( "I=%.2lfA\n", P/U );
			else printf ( "U=%.2lfV\n", P/I );
			printf ( "\n" );
		}
	}
}

