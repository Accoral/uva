/*************************************************************************
    > File Name: 10392.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 08时54分02秒
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
typedef vector<i64> I64V;
typedef pair<i64,i64> ii;
typedef vector<ii> iiV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 1000000; //sqrt(2^31)
const int SQRP = 1000; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.reserve ( 78498 );
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void prime_factorize ( i64 n ) {
	i64 sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		//int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		//while ( e-- ) printf ( "    %lld\n", prime ); 
		for ( ; n%prime == 0; printf ( "    %lld\n", prime ), n/= prime );
		sn = sqrt(n);
	}
	if ( n > 1 ) printf ( "    %lld\n", n );
}
int main()
{
	//cout << (int)sqrt ( 9223372036854775807 ) << endl; cout << sqrt ( 2147483647 ) << endl;
	prime_sieve ( );
	//For ( IV, it, primes ) printf ( "%d ", *it ); printf ( "\n" );
	//cout << primes.size() << endl;
	i64 x;
	int cnt;
	while ( scanf ( "%lld", &x ) != EOF && x > 0 ) {
		iiV ans;
		prime_factorize ( x );
		printf ( "\n" );
	}
    return 0;
}
