/*************************************************************************
    > File Name: 516.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 10时49分54秒
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
const int MAXP = 182; //sqrt(2^31)
const int SQRP = 14; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.reserve ( MAXP );
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
int pow_mod ( int a, int cnt ) {
	if ( cnt == 0 ) return 1;
	int x = pow_mod ( a, cnt/2 );
	int ans = x*x;
	if ( cnt&1 ) ans=ans*a;
	return ans;
}
IV v;
int main()
{
	//cout << sqrt ( 32768 ) << endl; cout << sqrt ( 182 ) << endl;
	prime_sieve ( );

	char s[1000];
	int len, i, num, sz;
	while ( fgets ( s, 1000, stdin ) ) {
		if ( s[0] == '0' ) break;
		len = strlen ( s );
		num = 0; v.clear();
		for ( i = 0; i < len; ++i )
			if ( isdigit(s[i]) ) num = num*10+s[i]-'0';
			else v.push_back(num), num = 0;
		sz = v.size(); num = 1;
		for ( i = 1; i < sz; i+=2 ) num *= pow_mod ( v[i-1], v[i] );
		//cout << num << endl;
		IIV f;
		IV ans;
		prime_factorize ( num-1, f );
		sz = f.size();
		for ( i = sz-1; i >= 0; --i )
			ans.push_back ( f[i].first ), ans.push_back ( f[i].second );
		sz = ans.size();
		for ( i = 0; i < sz-1; ++i ) printf ( "%d ", ans[i] );
		printf ( "%d\n", ans[i] );
	}
    return 0;
}
