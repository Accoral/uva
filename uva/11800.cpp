/*************************************************************************
    > File Name: 11800.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月16日 星期日 12时34分23秒
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
const double eps = 1e-10;
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
bool operator < (const Point& a, const Point& b) {//精度高的版本
  return dcmp(a.x-b.x) < 0 || (dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) < 0);
}
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
bool judge_parallel ( Vector A, Vector B ) {
	return dcmp(Cross(A,B)) == 0;
}
const char *shape[] = { "Square", "Rectangle", "Rhombus", "Parallelogram", "Trapezium", "Ordinary Quadrilateral" };
int main()
{
	set < double > s;
	int T, ans, is_parallel1, is_parallel2, cases = 1, sz, flag;
	Point A, B, C, D;
	scanf ( "%d", &T );
	while ( T-- ) {
		Point v[4];
		A = read_point(); B = read_point(); C = read_point(); D = read_point();
		flag = 0;
		if ( SegmentProperIntersection(A, B, C, D) ) v[0] = A, v[1] = B, v[2] = C, v[3] = D, flag = 1;
		else if ( SegmentProperIntersection(A, C, B, D) ) v[0] = A, v[1] = C, v[2] = B, v[3] = D, flag = 1;
		else if ( SegmentProperIntersection(A, D, B, C) ) v[0] = A, v[1] = D, v[2] = B, v[3] = C, flag = 1;
		if ( !flag ) ans = 5;
		else {
			is_parallel1 = judge_parallel(v[2]-v[0], v[3]-v[1]);
			is_parallel2 = judge_parallel(v[3]-v[0], v[2]-v[1]);
			if ( !is_parallel1 && !is_parallel2 ) ans = 5;
			else if ( is_parallel1 ^ is_parallel2 ) ans = 4;
			else {
				s.clear ( );
				s.insert ( Length(v[3]-v[0]) ); s.insert ( Length(v[2]-v[0]) );
				sz = s.size();
				//printf ( "sz=%d\n", sz );
				if ( dcmp(Dot(v[3]-v[0], v[2]-v[0])) == 0 ) {
					if ( sz == 1 ) ans = 0;
					else ans = 1;
				}
				else {
					if ( sz == 1 ) ans = 2;
					else ans = 3;
				}
			}
		}
		printf ( "Case %d: %s\n", cases++, shape[ans] );
	}
    return 0;
}
