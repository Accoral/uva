/*************************************************************************
    > File Name: numtheory.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 14时41分11秒
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
/*
   在区间中筛素数
   */
void prime_seg_sieve ( i64 a, i64 b, IV &seg_primes ) {
	BV pmap ( b-a+1, true );
	i64 sqr_b = sqrt ( b );
	For ( IV, it, primes ) {
		int p = *it;
		if ( p > sqr_b ) break;
		for ( i64 j = (a+p-1)/p, v=(j==1?p+p:j*p); v <= b; v += p ) pmap[v-a]=false;
	}
	seg_primes.clear ( );
	if ( a == 1 ) pmap[0] = false;
	for ( int i = 0, I = b-a+1; i < I; ++i ) if ( pmap[i] ) seg_primes.push_back(a+i);
}
/*
   n的因子，存入vector<pair<int,int>>中
   例如：n=90
   ---------
   素数 指数
   2	1
   3	2
   5	1
   ---------
   */
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
/*
   n的因子的个数
   */
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
/*
   欧拉函数， 小于n且与n互素的个数 P185
   */
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
/*
   n的因子，存入vector<int>中
   */
void divisors ( int n, IV &ds ) {
	ds.clear ( );
	ds.push_back ( 1 );
	int sn = sqrt ( n );
	For ( IV, it, primes ) {
		int p = *it;
		if ( p > sn ) break;
		if ( n % p != 0 ) continue;
		IV aux ( ds.begin(), ds.end() );
		int q = 1;
		while ( n % p == 0 ) {
			q *= p; n /= p;
			For ( IV, v, ds ) aux.push_back ( *v * q );
		}
		sn = sqrt ( n ); ds = aux;
	}
	if ( n > 1 ) {
		IV aux ( ds.begin(), ds.end() );
		For ( IV, v, ds ) aux.push_back ( *v * n );
		ds = aux;
	}
}
bool is_prime ( int n ) {
	if ( n < 2 || ( n > 2 && n % 2 == 0 ) ) return false;
	return !IsComp(n);
}
/*
    Calculates the highest exponent of prime p that divides n!
	求n！中素数p的指数.
	即：对n！进行因数分解后，素数p的指数
*/
int get_powers ( int n, int p ) {
	int res = 0; for ( int power = p; power <= n; power *= p ) res += n/power; return res;
}
/*
   P181 分治法优化 (a^cnt)%m
   使用时，注意变量类型
*/
int pow_mod ( int a, int cnt, int mod ) {
	if ( cnt == 0 ) return 1;
	int x = pow_mod ( a, cnt/2, mod );
	i64 ans = (i64)x*x%mod;
	if ( cnt&1 ) ans=ans*a%mod;
	return ans;
}
int main()
{
	prime_sieve ( );
	cout << get_powers ( 9, 3 ) << endl;
	/*
	IV ans;
	prime_seg_sieve ( 100000, 100100, ans );
	For ( IV, it, ans ) printf ( "%d ", *it ); printf ( "\n" );
	IIV ans;
	prime_factorize ( 105, ans );
	For ( IIV, it, ans ) printf ( "%d %d\n", it->first, it->second ); printf ( "\n" );
	IV ans;
	divisors ( 105, ans );
	For ( IV, it, ans ) printf ( "%d ", *it ); printf ( "\n" );
	*/
	//cout << count_divisors(105 ) <<endl;

    return 0;
}
