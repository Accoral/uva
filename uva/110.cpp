#include <cstdio>
#include <cstring>
int n;
void output ( int x ) {
	while ( x-- ) {
		printf ( "  " );
	}
}
void dfs ( int s[], int len ) {
		//for ( int k = 0; k < len; ++k ) printf ( "%d ", s[k] ); printf ( "\n" );
	if ( len == n ) {
		output ( len );
		printf ( "writeln(" );
		for ( int i = 0; i < len-1; ++i ) printf ( "%c,", 'a'+s[i] );
		printf ( "%c)\n", 'a'+s[len-1] );
		return;
	}
	int i, j, tmp[len+1];
	for ( j = 0; j < len; ++j ) tmp[j] = s[j];
	tmp[j] = len;
	output ( len );
	printf ( "if %c < %c then\n", s[len-1]+'a', len+'a' );
	dfs ( tmp, len+1 );
	for ( i = len-2; i >= 0; --i ) {
		for ( j = 0; j <= i; ++j ) tmp[j] = s[j];
		tmp[j] = len;
		for ( ++j; j < len+1; ++j ) tmp[j] = s[j-1];
		//printf ( "this..");for ( int k = 0; k < len+1; ++k ) printf ( "%d ", tmp[k] ); printf ( "\n" );
		output ( len );
		printf ( "else if %c < %c then\n", s[i]+'a', len+'a' );
		dfs ( tmp, len+1 );
	}
	j = 0;
	tmp[j] = len;
	for ( ++j; j < len+1; ++j ) tmp[j] = s[j-1];
	output ( len );
	printf ( "else\n" );
	dfs ( tmp, len+1 );
}
int main ( ) {
	int t, i;
	scanf ( "%d", &t );
	while ( t-- ) {
		scanf ( "%d", &n );
		printf ( "program sort(input,output);\n" );
		printf ( "var\na" );
		for ( i = 1; i < n; ++i ) printf ( ",%c", i+'a' );
		printf ( " : integer;\n" );
		printf ( "begin\n" );
		printf ( "  readln(a" );
		for ( i = 1; i < n; ++i ) printf ( ",%c", i+'a' );
		printf ( ");\n" );

		int s[] = { 0 };
		dfs ( s, 1 );
		printf ( "end.\n" );
		if ( t ) printf ( "\n" );
	}
}
