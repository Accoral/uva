#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main ( ) {
	int i, n;
	while ( cin >> n ) {
		getchar ( );
		while ( n-- ) {
			string s2, s3, s4, s5, l1, l2;
			getline ( cin, l1 );
			getline ( cin, l2 );
			//cout << l1 << "*l1l2*"  << l2 << endl;
			for ( i = 0; l1[i]; ++i ) if ( l1[i] != '<' && l1[i] != '>' ) printf ( "%c", l1[i] );
			printf ( "\n" );
			for ( i = 0; l1[i] != '<'; ++i );
			++i;
			for ( ; l1[i] != '>'; ++i ) s2 += l1[i];
			++i;
			for ( ; l1[i] != '<'; ++i ) s3 += l1[i];
			++i;
			for ( ; l1[i] != '>'; ++i ) s4 += l1[i];
			++i;
			for ( ; l1[i]; ++i ) s5 += l1[i];
			//cout << "s4:" << s4 << "\n" << "s3:"<<s3<<"\n"<<"s2:"<<s2<<"\n"<<"s5:"<<s5<<endl;
			for ( i = 0; l2[i] != '.'; ++i ) printf ( "%c", l2[i] );
			cout << s4 << s3 << s2 << s5 << "\n";
		}
	}
}
