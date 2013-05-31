/*************************************************************************
    > File Name: 10539.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 20时23分06秒
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
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<u64> UV;
typedef UV::iterator UVi;
const u64 LIM = 1000000000000LL;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)

#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))

const int MAXP = 1000000; //sqrt(10^12)
const int SQRP = 1000; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
UV almost_primes;
void prepare ( ) {
	prime_sieve ( );
	For ( IV, it, primes ) {
		int prime = *it;
		//for ( u64 i = static_cast<u64>(prime)*prime; i <= LIM; i *= prime ) almost_primes.push_back ( i );
		for ( u64 i = (u64)prime*prime; i <= LIM; i *= prime ) almost_primes.push_back(i);
	}
	sort ( almost_primes.begin(), almost_primes.end() );
}
int main()
{
	prepare ( );
	//for ( int i = 0; i < 10; ++i ) printf ( "%llu ", almost_primes[i] ); printf ( "\n" );
	int T;
	scanf ( "%d", &T );
	while ( T-- ) {
		u64 lo, hi;
		scanf ( "%llu%llu", &lo, &hi );
		UVi i = lower_bound ( almost_primes.begin(), almost_primes.end(), lo );
		UVi j = upper_bound ( almost_primes.begin(), almost_primes.end(), hi );
		printf ( "%d\n", j-i );
	}
    return 0;
}
