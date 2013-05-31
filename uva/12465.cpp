/*************************************************************************
    > File Name: 12465.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 10时42分34秒
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
const int MAXP = 31623; //sqrt(2^31)
const int SQRP = 178; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int count_divisors ( int n ) {
	int ret = 1;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		ret *= e+1;
		sn = sqrt(n);
	}
	if ( n > 1 ) ret *= 2;
	return ret;
}
int main()
{
	int x, y;
	prime_sieve ( );

	while ( scanf ( "%d%d", &x, &y ) != EOF ) {
		if ( !x && !y ) break;
		int diff = abs ( x - y );
		/*题中数据不会出现x==y的情况
		  这种情况解是无穷多个
		if ( diff == 0 ) printf ( "%d\n", x );
		else printf ( "%d\n", count_divisors(diff) );
		*/
		printf ( "%d\n", count_divisors(diff) );
	}
    return 0;
}
