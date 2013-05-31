/*************************************************************************
    > File Name: 10738.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 14时11分04秒
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
const int MAXP = 1000; //sqrt(2^31)
const int SQRP = 32; //sqrt(MAX)
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
const int MAXN = 1000000;
int mu[MAXN+1], M[MAXN+1];
void prepare ( ) {
	prime_sieve ( );
	mu[1] = M[1] = 1;
	IIV f;
	bool square_free;
	int sz, i;
	for ( i = 2; i <= MAXN; ++i ) {
		f.clear ( ); square_free = true;
		prime_factorize ( i, f );
		For ( IIV, it, f ) if ( it->second != 1 ) square_free = false;
		if ( !square_free ) mu[i] = 0;
		else {
			sz = f.size();
			if ( sz&1 ) mu[i] = -1;
			else mu[i] = 1;
		}
		M[i] = mu[i] + M[i-1];
	}
	//for ( i = 1; i <= 20; ++i ) printf ( "x=%d mu[%d]=%d M[%d]=%d \n", i, i, mu[i], i, M[i] );
}
int main()
{
	//cout << sqrt ( 1000 ) << endl;
	prepare ( );
	int x;
	while ( scanf ( "%d", &x ) != EOF && x ) {
		//printf ( "x=%d  mu[x]=%d  %d\n", x, mu[x], M[x] );
		printf ( "%8d%8d%8d\n", x, mu[x],M[x] );
	}
    return 0;
}
