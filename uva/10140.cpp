/*************************************************************************
    > File Name: 10140.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 19时42分42秒
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
const int INF = 0x7FFFFFFF;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef long long i64;
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
int main()
{
    prime_sieve ( );
	int x, y, closest, distant, x1, y1, x2, y2;
	while ( scanf ( "%d%d", &x, &y ) != EOF ) {
		IV v;
		prime_seg_sieve ( x, y, v );
		int sz = v.size ( );
		if ( sz < 2 ) printf ( "There are no adjacent primes.\n" );
		else {
			closest = INF; distant = 0;
			for ( int i = 1; i < sz; ++i ) {
				int dis = v[i] - v[i-1];
				if ( dis < closest ) closest = dis, x1 = v[i-1], y1 = v[i];
				if ( dis > distant ) distant = dis, x2 = v[i-1], y2 = v[i];
			}
			printf ( "%d,%d are closest, %d,%d are most distant.\n", x1, y1, x2, y2 );
		}
	}
    return 0;
}
