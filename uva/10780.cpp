/*************************************************************************
    > File Name: 10780.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 09时33分38秒
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
const int INF = 0x7fffffff;
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
const int MAXP = 10000; //sqrt(2^31)
const int SQRP = 100; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.reserve ( 1229 );
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int get_powers ( int n, int p ) {
	int res = 0; for ( int power = p; power <= n; power *= p ) res += n/power; return res;
}
void solve ( int m, int n ) {
	int res = INF, exp_up, exp_down, ok = 1, x=max(n,m), e;
	For ( IV, it, primes ) {
		if ( *it > x ) break;
		e = 0; for ( ; m%*it == 0; e++, m/= *it );
		exp_up = get_powers(n,*it);
		exp_down = e;
		//printf ( "prime=%d exp_up=%d	exp_down=%d\n", *it, exp_up, exp_down );
		if ( exp_up < exp_down ) {
			ok = 0; break;
		}
		else if ( exp_down ) res = min ( res, exp_up/exp_down );
	}
	if ( !ok ) printf ( "Impossible to divide\n" );
	else printf ( "%d\n", res );
}
int main()
{
	prime_sieve ( );
	//cout << primes.size()<<endl;
	int T, x, ncase = 1, m, n;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &m, &n );
		printf ( "Case %d:\n", ncase++ );
		solve ( m, n );
	}
    return 0;
}
