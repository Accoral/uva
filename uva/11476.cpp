/*************************************************************************
    > File Name: 11476.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 12时29分50秒
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
typedef pair<u64,u64> uu;
typedef vector<uu> uuV;
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
void print ( u64 n, int cnt ) {
	if ( cnt == 1 ) printf ( "%llu", n );
	else printf ( "%llu^%d", n, cnt );
}
void solve ( u64 n ) {
	bool first = 1;
	u64 sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		if ( first ) first = 0, print(prime,e);
		else printf(" * "),print(prime,e);
		sn = sqrt(n);
	}
	if ( n > 1 ) {
		if ( first ) first = 0, print(n,1);
		else printf(" * "),print(n,1);
	}
	printf ( "\n" );
}
int main()
{
	prime_sieve ( );
	int T;
	u64 x;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%llu", &x );
		printf ( "%llu = ", x );
		solve ( x );
	}
    return 0;
}
