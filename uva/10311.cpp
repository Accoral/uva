/*************************************************************************
    > File Name: 10311.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 16时02分30秒
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
const int MAXP = 100000000; //sqrt(2^31)
const int SQRP = 10000; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
bool is_prime ( int n ) {
	if ( n < 2 || ( n > 2 && n % 2 == 0 ) ) return false;
	return !IsComp(n);
}
int main()
{
	prime_sieve ( );
	int x, ok;
	while ( scanf ( "%d", &x ) != EOF ) {
		ok = 1;
		if ( x < 5 ) printf ( "%d is not the sum of two primes!\n", x );
		else if ( x & 1 ) {
			if ( is_prime(x-2) ) printf ( "%d is the sum of %d and %d.\n", x, 2, x-2 );
			else printf ( "%d is not the sum of two primes!\n", x );
		}
		else {
			IV :: iterator it = upper_bound ( primes.begin(), primes.end(), x/2 );
			for ( ; it != primes.end(); ++it )
				if ( is_prime(x-*it) ) {
					printf ( "%d is the sum of %d and %d.\n", x, x-*it, *it );
					ok = 0;
					break;
				}
			if ( ok ) printf ( "%d is not the sum of two primes!\n", x );
		}
	}
    return 0;
}
