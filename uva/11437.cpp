/*************************************************************************
    > File Name: 11437.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月15日 星期六 18时58分05秒
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
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }

Point GetLineIntersection(const Point& P, const Point& v, const Point& Q, const Point& w) {
  Vector u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

Vector Rotate(const Vector& A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
Point solve ( Point A, Point B, Point C ) {
	Point D = B*2.0/3 + C/3;
	Vector AD = D-A;
	Point E = C*2.0/3 + A/3;
	Vector BE = E-B;
	return GetLineIntersection(A, AD, B, BE);
}
double ConvexPolygonArea(Point *p, int n) {
	double area = 0;
	for ( int i = 1; i < n-1; ++i ) area += Cross(p[i]-p[0], p[i+1]-p[0]);
	return area/2;
}
const double EPS = 1E-10;
int main()
{
	int T;
	Point A, B, C, P[3];
	scanf ( "%d", &T );
	while ( T-- ) {
		A = read_point();
		B = read_point();
		C = read_point();
		P[0] = solve(A, B, C);
		P[1] = solve(B, C, A);
		P[2] = solve(C, A, B);
		double ans = ConvexPolygonArea(P,3);
		/*
		double low = floor(ans);
		double high = ceil(ans);
		if ( ( ans-low ) < ( high-ans ) + EPS ) ans = low;
		else ans = high;
		printf ( "%d\n", (int)ans );
		*/
		printf ( "%.0lf\n", ans );
	}
    return 0;
}
