#include <stdio.h>
#include <string>
using namespace std;
int main ( ) {
	int n, ans;
	while ( scanf ( "%d", &n ) != EOF ) {
		char s[10];
		sprintf ( s, "%08X", n );
		char v[10];
		v[0] = s[6]; v[1] = s[7]; v[2] = s[4]; v[3] = s[5]; v[4] = s[2]; v[5] = s[3]; v[6] = s[0]; v[7] = s[1]; v[8] = '\0';
		sscanf ( v, "%x", &ans );
		printf ( "%d converts to %d\n", n, ans );
	}
}
