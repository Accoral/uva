/*************************************************************************
    > File Name: 10139.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 17时05分28秒
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

const int MAXP = 1<<16; //sqrt(2^31)
const int SQRP = 1<<8; //sqrt(MAX)
int _c[(MAXP>>6)+1];
int nprimes;
IV primes;
void prime_sieve() {
    for ( int i = 3; i <= SQRP; i += 2 )
        if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
    primes.push_back ( 2 );
    for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
void prime_factorize ( int n, IIV &f ) {
    int sn = sqrt ( n );
    For ( IV, p, primes ) {
        int prime = *p;
        if ( prime > sn ) break; if ( n % prime ) continue;
        int e = 0; for ( ; n%prime == 0; e++, n/= prime );
        f.push_back ( II(prime,e) );
        sn = sqrt(n);
    }
    if ( n > 1 ) f.push_back( II(n,1) );
}
//Calculates the highest exponent of prime p that divides n!
int pow_div_fact ( int n, int p ) {
    //int sd = 0; for ( int N = n; N; N /= p ) sd += N%p; return (n-sd)/(p-1);
	int ret = 0; for ( int N = n; N; N /= p ) ret += N/p; return ret;
}
bool judge ( int n, int m ) {
	if ( m == 0 ) return false;
	if ( m == 1 ) return true;
	IIV factors;
	prime_factorize ( m, factors );
	For ( IIV, it, factors ) {
		if ( pow_div_fact ( n, it->first ) < it->second )
			return false;
	}
	return true;
}
int main()
{
    prime_sieve ( );
	int n, m;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		if ( judge(n,m) ) printf ( "%d divides %d!\n", m, n );
		else printf ( "%d does not divide %d!\n", m, n );
	}
    return 0;
}         
