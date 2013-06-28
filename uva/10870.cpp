/*************************************************************************
    > File Name: 10870.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月28日 星期五 16时39分11秒
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
const int maxn = 20;
typedef i64 Matrix[maxn][maxn];
typedef i64 Vector[maxn];
int sz, mod;
void matrix_mul(Matrix A, Matrix B, Matrix res) {
	Matrix C;
	memset(C, 0, sizeof(C));
	for(int i = 0; i < sz; ++i)
		for(int j = 0; j < sz; ++j)
			for(int k = 0; k < sz; ++k ) C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
	memcpy(res, C, sizeof(C));
}
void matrix_pow(Matrix A, int n, Matrix res) {
	Matrix a, r;
	memcpy(a, A, sizeof(a));
	memset(r, 0, sizeof(r));
	for(int i = 0; i < sz; ++i) r[i][i] = 1;
	while(n) {
		if(n&1) matrix_mul(r, a, r);
		n >>= 1;
		matrix_mul(a, a, a);
	}
	memcpy(res, r, sizeof(r));
}
void transform(Vector d, Matrix A, Vector res) {
	Vector r;
	memset(r, 0, sizeof(r));
	for(int i = 0; i < sz; ++i)
		for(int j = 0; j < sz; ++j) r[j] = (r[j] + d[i]*A[i][j]) % mod;
	memcpy(res, r, sizeof(r));
}
int main()
{
	int d, n, m;
	while ( scanf ( "%d%d%d", &d, &n, &m ) != EOF && d ) {
		Matrix A;
		Vector a, f;
		for(int i = 0; i < d; ++i) { scanf ( "%lld", a+i ); a[i] %= m; }
		for(int i = d-1; i >= 0; --i) { scanf ( "%lld", f+i ); f[i] %= m; }

		memset(A, 0, sizeof(A));
		for(int i = 0; i < d; ++i) A[0][i] = a[i];
		for(int i = 1; i < d; ++i) A[i][i-1] = 1;
		sz = d;
		mod = m;
		matrix_pow(A, n-d, A);
		i64 ans = 0;
		for(int i = 0; i < d; ++i) ans = (ans + f[i]*A[0][i]) % mod;
		printf ( "%lld\n", ans );
		/*
		memset(A, 0, sizeof(A));
		for(int i = 0; i < d; ++i) A[i][0] = a[i];
		for(int i = 1; i < d; ++i) A[i-1][i] = 1;

		sz = d;
		mod = m;
		matrix_pow(A, n-d, A);
		i64 ans = 0;
		for(int i = 0; i < sz; ++i) ans = (ans + f[i]*A[i][0]) % mod; printf("%lld\n",ans);
		//transform(f, A, f); printf ( "%lld\n", f[0] );
		*/
	}
  return 0;
}
