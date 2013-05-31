#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
const int MAXN = 3000;
int a[MAXN];
string ans[1001];
void store ( int x ) {
	int i;
	for ( i = MAXN - 1; a[i] == 0; --i );
	for ( ; i >= 0; --i )
		ans[x] += (char)(a[i] + '0');
}
void init ( ) {
	int n, c, i, j, tmp;
	memset ( a, 0, sizeof ( a ) );
	for ( i = 2, a[0] = 1; i <= 1000; ++i ) {
		for ( j = 0, c = 0; j < MAXN; ++j )
			tmp = a[j] * i + c, a[j] = tmp % 10, c = tmp / 10;
		store ( i );
	}
}
int main ( ) {
	int n, c, i, j, tmp;
	init ( );
	ans[0] = ans[1] = "1";
	while ( scanf ( "%d", &n ) != EOF ) {
		printf ( "%d!\n%s\n", n, ans[n].c_str ( ) );
	}
}
