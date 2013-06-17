/*************************************************************************
    > File Name: geometry.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月15日 星期六 18时44分49秒
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

const double eps = 1e-10;
const double PI = acos(-1);
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
/*
   涉及到用sort排序，需要用到
   */
bool operator < (const Point& a, const Point& b) {//精度高的版本
  return dcmp(a.x-b.x) < 0 || (dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) < 0);
}
/*
   unique时，需要用到
   */
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

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
double ConvexPolygonArea(Point *p, int n) {
	double area = 0;
	for ( int i = 1; i < n-1; ++i ) area += Cross(p[i]-p[0], p[i+1]-p[0]);
	return area/2;
}
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
/*
   判断一个点是否在一条线段上，不包含端点！！！
   */
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
/*==================================================*/
struct Circle {
  int x, y, r;
  Circle(int x, int y, int r):x(x), y(y), r(r) {}
  Point getPoint(double a) {
    return Point(x+r*cos(a), y+r*sin(a));
  }
};
//具体说明见书中P266
int getTangents(Circle A, Circle B, Point* a, Point* b) {
  int cnt = 0;
  if(A.r < B.r) { swap(A, B); swap(a, b); }
  int d2 = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
  int rdiff = A.r-B.r;
  int rsum = A.r+B.r;
  if(d2 < rdiff*rdiff) return 0;

  double base = atan2(B.y-A.y, B.x-A.x);
  if(d2 == 0 && A.r == B.r) return -1; // 无限多条切线
  if(d2 == rdiff*rdiff) { // 内切，1条切线
    a[cnt] = A.getPoint(base); b[cnt] = B.getPoint(base); cnt++;
    return 1;
  }
  // 有外共切线
  double ang = acos((A.r-B.r) / sqrt(d2));
  a[cnt] = A.getPoint(base+ang); b[cnt] = B.getPoint(base+ang); cnt++;
  a[cnt] = A.getPoint(base-ang); b[cnt] = B.getPoint(base-ang); cnt++;
  if(d2 == rsum*rsum) { // 一条内共切线
    a[cnt] = A.getPoint(base); b[cnt] = B.getPoint(PI+base); cnt++;
  }
  else if(d2 > rsum*rsum) { // 两条内共切线
    double ang = acos((A.r+B.r) / sqrt(d2));
    a[cnt] = A.getPoint(base+ang); b[cnt] = B.getPoint(PI+base+ang); cnt++;
    a[cnt] = A.getPoint(base-ang); b[cnt] = B.getPoint(PI+base-ang); cnt++;
  }
  return cnt;
}

int main()
{
    return 0;
}
