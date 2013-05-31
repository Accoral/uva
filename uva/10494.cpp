#include <stdio.h>
#include <string.h>
int main ( ) {
	char s[1000], op;
	int ans[1000];
	long long num;
	while ( scanf ( "%s %c %lld", s, &op, &num ) != EOF ) {
		//printf ( "%s%c%lld\n", s, op, num );
		int len = strlen ( s ), i;
		if ( op == '/' ) {
			long long tmp = 0; 
			int n = 0;
			for ( i = 0; i < len; ++i, ++n ) {
				tmp = tmp * 10 + s[i] - '0';
				ans[n] = tmp / num, tmp %= num;
				//if ( tmp >= num ) ans[n] = tmp / num, tmp %= num; else ans[n] = 0;
				//printf ( "tmp=%d	ans[%d]=%d\n",tmp, n, ans[n]);
			}
			for ( i = 0; i < n-1 && ans[i] == 0; ++i );//remain one bit!!!
			for ( ; i < n; ++i ) printf ( "%d", ans[i] ); putchar ( '\n' );
		}
		else {
			long long ans_mod = 0;
			for ( i = 0; i < len; ++i ) {
				ans_mod = ans_mod * 10 + s[i] - '0';
				ans_mod %= num;
			}
			printf ( "%lld\n", ans_mod );
		}

	}
}
