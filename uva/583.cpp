/*************************************************************************
    > File Name: 583.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 14时51分40秒
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
const int MAXP = 46341; //sqrt(2^31)
const int SQRP = 216; //sqrt(MAX)
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
int main()
{
	//cout << sqrt ( 2147483647 ) << endl;
	prime_sieve ( );
	int x, flag, cnt;
	while ( scanf ( "%d", &x ) != EOF && x ) {
		flag = 0;
		if ( x < 0 ) flag = 1, x *= -1;
		IIV f; IV ans;
		if ( flag ) ans.push_back ( -1 );
		prime_factorize ( x, f );
		For ( IIV, it, f ) {
			cnt = it->second;
			while ( cnt-- ) ans.push_back ( it->first );
		}
		int sz = ans.size ( );
		if ( flag ) x *= -1;
		printf ( "%d = %d", x, ans[0] );
		for ( int i = 1; i < sz; ++i ) printf ( " x %d", ans[i] );
		printf ( "\n" );
	}
    return 0;
}
