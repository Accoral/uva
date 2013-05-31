/*************************************************************************
    > File Name: 914.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 11时47分29秒
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
typedef map<int,int> IIM;
typedef vector<bool> BV;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 1000000; //sqrt(2^31)
const int SQRP = 1000; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes, ans;
IIM mymap;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int main()
{
	prime_sieve ( );
	int x, y, i, ansi, T;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		vector < int > ::iterator it1, it2, it;
		ans.clear ( );
		it1 = lower_bound ( primes.begin(), primes.end(), x );
		it2 = upper_bound ( primes.begin(), primes.end(), y );
		for ( it = it1; it != it2; ++it ) ans.push_back ( *it );
		//For ( IV, it, ans ) printf ( "%d ", *it ); printf ( "\n" );
		int ok = 1, sz = ans.size(), maxn = 0, cnt = 0;
		if ( sz < 2 ) ok = 0;
		else {
			mymap.clear ( );
			for ( i = 1; i < sz; ++i ) mymap[ans[i]-ans[i-1]]++, maxn = max ( maxn, mymap[ans[i]-ans[i-1]] );
			For ( IIM, itmap, mymap )
				if ( itmap->second == maxn ) {
					ansi = itmap->first;
					++cnt;
					if ( cnt == 2 ) {
						ok = 0;
						break;
					}
				}
		}
		if ( ok ) printf ( "The jumping champion is %d\n", ansi );
		else printf ( "No jumping champion\n" );
	}
    return 0;
}
