/*************************************************************************
    > File Name: 10879.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 12时11分11秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef pair<int,int> II;
typedef vector<int> IV;
typedef vector<II> IIV;
typedef vector<bool> BV;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 3163; //sqrt(2^31)
const int SQRP = 57; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void solve ( int n ) {
	int x = n, cnt = 0, prime, e;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		if ( cnt == 2 ) break;//
		prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		e = 0; for ( ; n%prime == 0; e++, n/= prime );
		printf ( " = %d * %d", prime, x / prime ), ++cnt;
		if ( cnt == 2 ) break;//
		if ( e > 1 ) {
			prime *= prime;
			printf ( " = %d * %d", prime, x / prime ), ++cnt;
		}
		sn = sqrt(n);
	}
	printf ( "\n" );
}
/*
   特殊样例
   18 
   32
*/
int main()
{
	//cout << sqrt ( 10000000 ) << endl; cout << sqrt ( 3163 ) << endl;
	prime_sieve ( );
	int T, x, ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &x );
		printf ( "Case #%d: %d", ncase++, x );
		solve ( x );
	}

    return 0;
}
