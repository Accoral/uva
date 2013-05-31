/*************************************************************************
    > File Name: 10791.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 11时06分04秒
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
void solve ( int x ) {
	IIV f;
	prime_factorize ( x, f );
	int num, cnt;
	u32 ans;
	if ( f.size() == 1 ) ans = 1;
	else ans = 0;
	For ( IIV, it, f ) {
		cnt = it->second;
		num = 1;
		while ( cnt-- ) num *= it->first;
		//cout << num << endl;
		ans += num;
	}
	if ( x == 1 ) ans = 2;
	printf ( "%u\n", ans );
}
int main()
{
	prime_sieve ( );
	int x, ncase = 1;
	while ( scanf ( "%d", &x ) != EOF && x ) {
		printf ( "Case %d: ", ncase++ );
		solve ( x );
	}
    return 0;
}
