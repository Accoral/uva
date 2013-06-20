/*************************************************************************
    > File Name: 1308.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月20日 星期四 15时14分20秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const double eps = 5 * 1e-13;
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
const double PI = acos(-1);
const double TWO_PI = PI * 2;

double NormalizeAngle(double rad, double center = PI ) {
	return rad - TWO_PI * floor((rad+PI-center) / TWO_PI);
}

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

const int maxn = 105;
void debug ( Point p ) {
	printf ( "(%lf,%lf)\n", p.x, p.y );
}
struct Circle {
  Point c;
  double r;
}circle[maxn];
double angle(Vector v) { return atan2(v.y, v.x); }
void getCircleCircleIntersection(Circle C1, Circle C2, vector<double> &rad) {
  double d = Length(C1.c - C2.c);
  if(dcmp(d) == 0) return;
  if(dcmp(C1.r + C2.r - d) < 0) return;
  if(dcmp(fabs(C1.r-C2.r) - d) > 0) return;
  double a = angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  //rad.push_back(NormalizeAngle(a-da)); rad.push_back(NormalizeAngle(a+da));
  rad.push_back(a-da); rad.push_back(a+da);
}

int n;
int topmost ( Point p ) {
	for ( int i = n-1; i >= 0; --i ) if ( Length(circle[i].c-p) < circle[i].r ) return i;
	return -1;
}
int main()
{
	int i, j, k, sz, visible[maxn], ans;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		memset ( visible, 0, sizeof(visible) );
		for ( i = 0; i < n; ++i ) 
			scanf ( "%lf%lf%lf", &circle[i].c.x, &circle[i].c.y, &circle[i].r );
		for ( i = 0; i < n; ++i ) {
			vector < double > rad; rad.push_back(0); rad.push_back(PI*2);
			for ( j = 0; j < n; ++j ) getCircleCircleIntersection(circle[i],circle[j], rad);
			sort ( rad.begin(), rad.end() );
			for ( j = 0; j < rad.size(); ++j ) {
				double mid = (rad[j]+rad[j+1])/2.0;
				for ( int side = -1; side <= 1; side += 2 ) {
					double r2 = circle[i].r - side*eps;
					int t = topmost(Point(circle[i].c.x + cos(mid)*r2, circle[i].c.y + sin(mid)*r2));
					if ( t >= 0 ) visible[t] = true;
				}
			}
		}
		for ( ans = i = 0; i < n; ++i ) if ( visible[i] ) ++ans;
		printf ( "%d\n", ans );

	}
    return 0;
}
