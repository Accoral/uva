/*************************************************************************
    > File Name: 11524.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月18日 星期二 10时46分46秒
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
const double eps = 1E-10;
const double PI = acos(-1);
int main()
{
	int T;
	double r, m1, n1, m2, n2, m3, n3, ang, a, b, c;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%lf%lf%lf%lf%lf%lf%lf", &r, &m1, &n1, &m2, &n2, &m3, &n3 );
		a = n1/m1 + m3/n3; b = 1 + m3/n3; c = 1 + n1/m1;
		ang = acos ( (c*c + b*b - a*a)/(2*b*c) );
		ang /= 2;
		/*
		double AC = r / tan(ang);
		a *= AC; b *= AC; c *= AC;
		//double p = (a+b+c)/2;
		//printf ( "%.4lf\n", sqrt(p*(p-a)*(p-b)*(p-c)) );
		printf ( "%.4lf\n", (a+b+c)*r/2 );
		*/
		printf ( "%.4lf\n", (a+b+c)*r*r/(2*tan(ang)) );
	}
    return 0;
}
