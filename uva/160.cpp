/*************************************************************************
    > File Name: 160.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 12时30分17秒
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
typedef map<int,int> IIM;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 10; //sqrt(2^31)
const int SQRP = 4; //sqrt(MAX)
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
void prime_factorize ( int n, IIM &f ) {
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		f[prime] += e;
		sn = sqrt(n);
	}
	if ( n > 1 ) f[n] += 1;
}
int main()
{
	prime_sieve ( );
	int i, n;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "%3d! =", n );
		IIM f;
		for ( i = 0; i <= n; ++i ) prime_factorize ( i, f );
		//For ( IIM, it, f ) printf ( "%d %d\n", it->first, it->second );
		int cnt = 0;
		For ( IIM, it, f ) {
			if ( cnt && cnt % 15 == 0 ) printf ( "\n      " );
			printf ( "%3d", it->second);
			++cnt;
			//if ( cnt % 15 == 0 ) printf ( "\n      " );
		}
		printf ( "\n" );
	}
    return 0;
}
