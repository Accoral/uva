/*************************************************************************
    > File Name: 11977.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 21时43分45秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<int> IV;
typedef long long i64;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 100000; //sqrt(2^31)
const int SQRP = 317; //sqrt(MAX)
const int MOD = 10000019;
int _c[(MAXP>>6)+1], n, t;
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int get_powers ( int n, int p ) {
	int res = 0; for ( int power = p; power <= n; power *= p ) res += n/power; return res;
}
/*
   P181 分治法优化
*/
int pow_mod ( int a, int cnt ) {
	if ( cnt == 0 ) return 1;
	int x = pow_mod ( a, cnt/2 );
	i64 ans = (i64)x*x%MOD;
	if ( cnt&1 ) ans=ans*a%MOD;
	return ans;
}
int solve ( ) {
	int ans = 1, exp;
	For ( IV, it, primes ) {
		exp = get_powers(n,*it);
		if ( exp < t ) break;
		//for ( int i = 0; i < ba; ++i ) ans = (i64)ans*(*it)%MOD;
		ans = (i64)ans * pow_mod ( *it, exp/t )%MOD;
	}
	if ( ans == 1 ) return -1;
	return ans;
}
/*
   如果在b进制下t,阶乘末尾有1个0，那么在十进制下，阶乘要是b的倍数
   如果在b进制下,阶乘末尾有t个0，那么在十进制下，阶乘要是b^t的倍数
   t = 4;
   阶乘: 2^10		3^12	 5^15
   --------------------------------
   base: (2^2)^4    (3^3)^4  (5^3)^5
   此时结果应该是：(2^2) * (3^3) * (5^3)
*/
int main()
{
	prime_sieve ( );
	int T, ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &n, &t );
		printf ( "Case %d: %d\n", ncase++, solve() );
	}
    return 0;
}
