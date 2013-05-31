/*************************************************************************
    > File Name: 11064.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 13时20分45秒
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
int count_divisors ( int n ) {
	int ret = 1;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		ret *= e+1;
		sn = sqrt(n);
	}
	if ( n > 1 ) ret *= 2;
	return ret;
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
int main()
{
	prime_sieve ( );
	int x;
	while ( scanf ( "%d", &x ) != EOF ) {
		printf ( "%d\n", x - euler_phi(x) - count_divisors(x) + 1 );
	}
    return 0;
}
