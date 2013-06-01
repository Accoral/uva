/*************************************************************************
    > File Name: 10006.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 11时21分45秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef pair<int,int> II;
typedef vector<II> IIV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
const int INF = 0x7FFFFFFF;
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 65000; //sqrt(2^31)
const int SQRP = 255; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
bool is_prime ( int n ) {
	if ( n < 2 || ( n > 2 && n % 2 == 0 ) ) return false;
	return !IsComp(n);
}
int pow_mod ( int a, int cnt, int mod ) {
	if ( cnt == 0 ) return 1;
	int x = pow_mod ( a, cnt/2, mod );
	i64 ans = (i64)x*x%mod;
	if ( cnt&1 ) ans=ans*a%mod;
	return ans;
}
bool fermat_test ( int n ) {
	int tmp, cnt, pre = 1;
	for ( int i = 2; i < n; ++i ) {
		if ( pow_mod(i,n,n) != i ) return false;
	}
	return true;
}
int main()
{
	//cout << sqrt ( 65000 ) << endl;
	prime_sieve ( );
	//cout << primes.size() << endl;
	int x, ans;
	while ( scanf ( "%d", &x ) != EOF && x ) {
		if ( is_prime(x) ) ans = 0;
		else {
			if ( fermat_test(x) ) ans = 1;
			else ans = 0;
		}
		if ( ans ) printf ( "The number %d is a Carmichael number.\n", x );
		else printf ( "%d is normal.\n", x );
	}
    return 0;
}
