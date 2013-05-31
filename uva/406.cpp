/*************************************************************************
    > File Name: 406.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 10时16分22秒
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
const int MAXP = 1000; //sqrt(1000)
const int SQRP = 32; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 1 );
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int main()
{
	//cout << sqrt ( 1000 ) << endl;
	prime_sieve ( );
	int n, c, from, to, len, i;
	while ( scanf ( "%d%d", &n, &c ) != EOF ) {
		printf ( "%d %d:", n, c );
		len = upper_bound ( primes.begin(), primes.end(), n ) - primes.begin();
		if ( len&1 ) from = len/2-(c-1), to = len/2+(c-1);
		else from = len/2-c, to = len/2+(c-1);
		from = max ( 0, from ); to = min ( len-1, to );
		for ( i = from; i < to; ++i ) printf ( " %d", primes[i] );
		printf ( " %d\n\n", primes[i] );
	}
    return 0;
}
