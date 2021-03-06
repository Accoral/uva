/*************************************************************************
    > File Name: 294.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 15时54分15秒
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
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 31623; //sqrt(10^9)
const int SQRP = 178; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
    for ( int i = 3; i <= SQRP; i += 2 )
        if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
    primes.push_back ( 2 );
    for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int count_divisors ( int n ) {
	int ret = 1;
    int sn = sqrt ( n );
    For ( IV, p, primes ) {
        int prime = *p;
        if ( prime > sn ) break; if ( n % prime ) continue;
        int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		ret *= e+1;
        sn = sqrt(n);
    }
	if ( n > 1 ) ret *= 2;
	return ret;
}
int main()
{
    prime_sieve ( );
	int T, i, L, U, P, D, tmp;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &L, &U );
		D = 0;
		for ( i = L; i <= U; ++i ) {
			tmp = count_divisors(i);
			if ( tmp > D ) {
				D = tmp;
				P = i;
			}
		}
		printf ( "Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D );
	}
    return 0;
}
