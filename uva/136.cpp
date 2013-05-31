/*************************************************************************
    > File Name: 136.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 21时29分08秒
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
int main ( ) {
	printf ( "The 1500'th ugly number is 859963392.\n" );
	return 0;
}
#if 0
const int MAX = 1000000000;
typedef vector<int> IV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 1000000000; //sqrt(2^31)
const int SQRP = 31623; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
bool ugly[MAX + 1];
int main()
{
	cout << sqrt(MAX) << endl;
	prime_sieve();
	cout << "ok\n";
	int i, j;
	for ( i = 1; i <= MAX; ++i ) ugly[i] = true;
	For ( IV, it, primes ) {
		if ( *it <= 5 ) continue;
		for ( i = *it; i <= MAX; i+=*it ) ugly[i] = false;
	}
	cout << "go\n";
	int cnt = 0;
	for ( i = 1; i <= MAX; ++i ) if ( ugly[i] ) {
		++cnt;
		if ( cnt == 1500 ) {
			printf ( "The 1500'th ugly number is %d.\n", i );
			break;
		}
	}
    return 0;
}
#endif
