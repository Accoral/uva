/*************************************************************************
    > File Name: 10990.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月31日 星期五 14时50分42秒
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
const int MAXP = 1415; //sqrt(2^31)
const int SQRP = 38; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
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
int depthphi[2000001], ans[2000001];
void prepare ( ) {
	depthphi[1] = 1; depthphi[2] = 1;
	ans[1] = 1; ans[2] = 2;
	for ( int i = 3; i < 2000001; ++i ) depthphi[i] = depthphi[euler_phi(i)] + 1, ans[i] = ans[i-1]+depthphi[i];
}
int main()
{
	//cout << sqrt ( 2000000 ) << endl; cout << sqrt ( 1415 ) << endl;
	prime_sieve ( );
	prepare ( );
	int T, x, y;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		printf ( "%d\n", ans[y]-ans[x-1] );
	}
    return 0;
}
