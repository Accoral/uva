#include <stdio.h>
long long A, L, A_copy;
int main ( ) {
	int n = 0;
	while ( scanf ( "%lld%lld", &A, &L ) != EOF ) {
		A_copy = A;
		if ( A < 0 && L < 0 ) break;
		int ans = 0;
		while ( A != 1 ) {
			if ( A == 1 || A > L ) break;
			if ( A % 2 == 0 ) A = A / 2;
			else A = 3*A + 1;
			++ans;
			//printf ( "A=%lld\n", A );
		}
		printf ( "Case %d: A = %lld, limit = %lld, number of terms = %d\n", ++n, A_copy, L, A == 1 ? ans + 1 : ans  );
		//printf ( "A=%lld	%d\n", A, ans );
	}
}
