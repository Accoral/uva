#include <stdio.h>
int main ( ) {
	int n, f, size, num, degree, ans;
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%d", &f );
			ans = 0;
			while ( f-- ) {
				scanf ( "%d%d%d", &size, &num, &degree );
				ans += size * degree;
			}
			printf ( "%d\n", ans );
		}
	}
}
