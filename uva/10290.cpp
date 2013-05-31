/*************************************************************************
    > File Name: 10290.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 19时54分06秒
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
const int MAXP = 30000000; //sqrt(2^31)
const int SQRP = 5478; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int solve ( i64 n ) {
	int ans = 1;
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int prime = *it;
		if ( prime > sn ) break; if ( n % prime ) continue;
		int e = 0; for ( ; n%prime == 0; e++, n/= prime );
		if ( prime&1 ) ans *= e+1;
		sn = sqrt(n);
	}
	if ( n > 1 ) 
		if ( n&1 ) ans *= 1+1;
	return ans;
}
/*
								中位数	长度
15:	15	-14+...+14+15			15		1
	7+8	-6+...+6+7+8			1		15
	4+5+6	-3+...+3+4+5+6		5		3
	1+2+3+4+5	0+1+2+3+4+5		3		5

	一半奇数长度，一半偶数长度；
	只考虑奇数长度！
	奇数长度(d)的中位数正好是N/d.
	数有多少组，相当于数多少个奇数因子
http://mathblag.wordpress.com/2011/11/13/sums-of-consecutive-integers/

If N is the sum of d consecutive integers, where d is odd, then the middle term must be N/d, hence N/d is an integer. 
Conversely, if d is odd and N/d is an integer, then the sum of d consecutive integers centered at N/d is equal to N. 
Therefore, the number of ways to write N as the sum of an odd number of consecutive integers is equal to the number of odd positive divisors of N.
*/
int main()
{
	//cout << (int)sqrt ( 9e14 ) << endl; cout << sqrt(30000000) << endl;
	prime_sieve ( );
	i64 x;
	while ( scanf ( "%lld", &x ) != EOF ) {
		printf ( "%d\n", solve(x) );
	}
    return 0;
}
