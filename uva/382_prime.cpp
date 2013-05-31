/*************************************************************************
    > File Name: 382_prime.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 14时27分00秒
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
const int MAXP = 245; //sqrt(2^31)
const int SQRP = 16; //sqrt(MAX)
//const int MAX_NP = 5435; //1.26*MAXP/log(MAXP)
int _c[(MAXP>>6)+1];
//int primes[MAX_NP];
//int nprimes;
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void divisors ( int n, IV &ds ) {
	ds.clear ( );
	ds.push_back ( 1 );
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int p = *it;
		if ( p > sn ) break;
		if ( n % p != 0 ) continue;
		IV aux ( ds.begin(), ds.end() );
		int q = 1;
		while ( n % p == 0 ) {
			q *= p; n /= p;
			For ( IV, v, ds ) aux.push_back ( *v * q );
		}
		sn = sqrt ( n ); ds = aux;
	}
	if ( n > 1 ) {
		IV aux ( ds.begin(), ds.end() );
		For ( IV, v, ds ) aux.push_back ( *v * n );
		ds = aux;
	}
}
int main()
{
	prime_sieve ( );
	int n;
	puts ( "PERFECTION OUTPUT" );
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "%5d  ", n );
		IV ds;
		divisors ( n, ds );
		int sum = 0;
		For ( IV, it, ds ) if ( *it < n ) sum += *it;
		if ( sum == n ) puts ( "PERFECT" );
		else if ( sum < n ) puts ( "DEFICIENT" );
		else puts ( "ABUNDANT" );
	}
	puts ( "END OF OUTPUT" );
    return 0;
}
