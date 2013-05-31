/*************************************************************************
    > File Name: 10956.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 12时18分11秒
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
const int MAXP = 65536; //sqrt(2^31)
const int SQRP = 256; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.reserve ( 65536 );
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void prime_seg_sieve ( i64 a, i64 b, vector<u32> &seg_primes ) {
	BV pmap ( b-a+1, true );
	i64 sqr_b = sqrt ( b );
	For ( IV, it, primes ) {
		int p = *it;
		if ( p > sqr_b ) break;
		for ( i64 j = (a+p-1)/p, v=(j==1?p+p:j*p); v <= b; v += p ) pmap[v-a]=false;
	}
	seg_primes.clear ( );
	seg_primes.reserve(b-a+1);
	if ( a == 1 ) pmap[0] = false;
	for ( int i = 0, I = b-a+1; i < I; ++i ) if ( pmap[i] ) seg_primes.push_back(a+i);
}
i64 pow_mod ( i64 a, i64 cnt, i64 mod ) {
	if ( cnt == 0 ) return 1;
	i64 x = pow_mod ( a, cnt/2, mod );
	i64 ans = (u64)x*x%mod;
	if ( cnt&1 ) ans=ans*a%mod;
	return ans;
}
bool suspect ( int b, u32 n ) {
	u32 u = n - 1, t = 0;
	while ( !(u&1) ) u >>= 1, t++;
	u32 x = pow_mod ( b, u, n ), i;
	if ( x == 1 || x == n-1 ) return true;
	for ( i = 0; i < t-1; ++i ) {
		x = (u64)x * x % n;
		if ( x == 1 ) return false;
		if ( x == n-1 ) return true;
	}
	return false;
}
int main()
{
	//cout << sqrt ( 4294967295 ) << endl; cout << sqrt ( 65536 ) << endl;
	prime_sieve ( );

	int b, sz, first = 1;
	u32 x, y;
	while ( scanf ( "%d%u%u", &b, &x, &y ) != EOF ) {
		if ( !b && !x && !y ) break;
		if ( first ) first = 0;
		else printf ( "\n" );
		vector<u32> seg_primes, ans;
		prime_seg_sieve ( x, y, seg_primes );
		sz = seg_primes.size();
		u32 cnt = 0;
		for ( u32 i = x; i <= y; ++i ) if ( i&1 ) {
			++cnt;
			if ( !binary_search(seg_primes.begin(),seg_primes.end(),i) && suspect(b,i) )
				ans.push_back ( i );
		}
		printf ( "There are %u odd non-prime numbers between %u and %u.\n", cnt-sz, x, y );
		sz = ans.size();
		if ( sz ) {
			printf ( "%d suspects fail in base %d:\n", sz, b );
			for ( int i = 0; i < sz; ++i ) printf ( "%u\n", ans[i] );
		}
		else printf ( "There are no failures in base %d.\n", b );
	}

    return 0;
}
