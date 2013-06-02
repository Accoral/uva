/*************************************************************************
    > File Name: 10105.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月02日 星期日 13时11分37秒
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
u64 fac[13];
void init ( ) {
	u64 res = 1;
	fac[0] = 1;
	for ( int i = 1; i < 13; ++i ) fac[i] = fac[i-1]*i;
}
/*
   C(n,n1)*C(n-n1,n2)*C(n-n1-n2,n3)*…*C(n-n1-n2-n3-…-n(k-1), nk) ==
   n!/(n1!*n2!*n3!*…*nk!)
   */
int main()
{
	init ( );
	int n, k, i, x;
	while ( scanf ( "%d%d", &n, &k ) != EOF ) {
		u64 ans = fac[n];
		for ( i = 0; i < k; ++i ) {
			scanf ( "%d", &x );
			ans /= fac[x];
		}
		printf ( "%llu\n", ans );
	}
    return 0;
}
