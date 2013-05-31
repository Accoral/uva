/*************************************************************************
    > File Name: 11327.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 15时29分03秒
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
const int MAXP = 448; //sqrt(2^31)
const int SQRP = 22; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void prime_factorize ( int n, IIV &f ) {
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		f.push_back ( II(prime,e) );
		sn = sqrt(n);
	}
	if ( n > 1 ) f.push_back( II(n,1) );
}
int euler_phi ( int n ) {
	int ans = n;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		for ( ; n%prime == 0; n/= prime );
		ans /= prime;
		ans *= (prime-1);
		sn = sqrt(n);
	}
	if ( n > 1 ) ans /= n, ans *= (n-1);
	return ans;
}
const int MAXN = 200002;
u64 ans[MAXN];
void prepare ( ) {
	ans[1] = 0;
	ans[2] = 2;
	for ( int i = 3; i < MAXN; ++i ) ans[i] = ans[i-1] + euler_phi(i-1);
	//printf ( "%llu\n", ans[200000] );
}
int main()
{
	//cout << sqrt ( 200000 ) << endl; cout << sqrt ( 448 ) << endl;
	prime_sieve ( );
	prepare ( );
	u64 x, from, to, i;
	int n, m;
	while ( scanf ( "%llu", &x ) != EOF && x ) {
		n = lower_bound ( ans+1, ans+MAXN, x ) - ans;
		n -= 1;
		from = ans[n]; to = x;
		//printf ( "from=%llu  to=%llu	n=%d\n", from, to, n );
		for ( i = from, m = 0; i < to; ) {
			if ( __gcd ( m, n ) == 1 ) ++i;
			if ( i == to ) break;
			++m;
		}
		printf ( "%d/%d\n", m, n );
	}
    return 0;
}
