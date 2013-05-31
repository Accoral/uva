/*************************************************************************
    > File Name: 10622.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 17时45分50秒
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
const int INF = 0x7FFFFFFF;
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
const int MAXP = 65536; //sqrt(2^32)
const int SQRP = 256; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int prime_factorize ( i64 n ) {
	int flag = 0;
	if ( n < 0 ) flag = 1, n *= -1;
	int res = 0;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		res = __gcd ( res, e );
		sn = sqrt(n);
	}
	if ( n > 1 ) res = __gcd ( res, 1 );
	if ( !res ) return 1;
	if ( flag ) {
		while ( !(res&1) ) res >>= 1;
	}
	return res;
}
//输入有负数。坑！
int main()
{
	prime_sieve ( );
	i64 x;
	while ( scanf ( "%lld", &x ) != EOF && x ) {
		//printf ( "x=%lld\n", x );
		printf ( "%d\n", prime_factorize(x) );
	}
    return 0;
}
