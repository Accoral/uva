/*************************************************************************
    > File Name: 160_effi.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 13时14分07秒
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
const int MAXP = 100; //sqrt(2^31)
const int SQRP = 10; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
//Calculates the highest exponent of prime p that divides n!
int get_powers ( int n, int p ) {
	int res = 0; for ( int power = p; power <= n; power *= p ) res += n/power; return res;
}
int main()
{
	prime_sieve ( );
	int n;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "%3d! =", n );
		int cnt = 0;
		For ( IV, it, primes ) {
			if ( *it > n ) break;
			if ( cnt && cnt % 15 == 0 ) printf ( "\n      " );
			++cnt;
			printf ( "%3d", get_powers(n,*it) );
		}
		printf ( "\n" );
	}
    return 0;
}
