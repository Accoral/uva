/*************************************************************************
    > File Name: 11817.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月26日 星期三 10时05分50秒
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
double torad(double deg) {
	return deg/180 * PI;
}
void get_coord(double R, double lat, double lng, double &x, double &y, double &z ) {
	lat = torad(lat);
	lng = torad(lng);
	x = R*cos(lat)*cos(lng);
	y = R*cos(lat)*sin(lng);
	z = R*sin(lat);
}
const int RADIUS = 6371009;
int main()
{
	//printf ( "%lf\n", M_PI );
	int n;
	double x1, y1, z1, x2, y2, z2, lat1, lng1, lat2, lng2, d, ans;
	scanf ( "%d", &n );
	while ( n-- ) {
		scanf ( "%lf%lf%lf%lf", &lat1, &lng1, &lat2, &lng2 );
		get_coord(RADIUS, lat1, lng1, x1, y1, z1);
		get_coord(RADIUS, lat2, lng2, x2, y2, z2);
		ans = d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		double ang = 2*asin(d/(2*RADIUS));
		printf ( "%.0lf\n", ang*RADIUS - ans );
	}
  return 0;
}
