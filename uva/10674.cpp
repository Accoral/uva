/*************************************************************************
    > File Name: 10674.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月17日 星期一 14时01分13秒
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
const double PI = acos(-1);
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
bool operator < (const Point& a, const Point& b) {
  //return a.x < b.x || (a.x == b.x && a.y < b.y);
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
struct Circle {
  int x, y, r;
  Circle(int x, int y, int r):x(x), y(y), r(r) {}
  Point getPoint(double a) {
    return Point(x+r*cos(a), y+r*sin(a));
  }
};

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
	int x1, y1, r1, x2, y2, r2, i, j;
	vector < pair<Point, Point> > v;
	while ( scanf ( "%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2 ) != EOF ) {
		if ( !x1 && !y1 && !r1 && !x2 && !y2 && !r2 ) break;
		Point a[4], b[4];
		int cnt = getTangents(Circle(x1, y1, r1), Circle(x2, y2, r2), a, b);
		v.clear ( );
		for ( i = 0; i < cnt; ++i ) v.push_back ( make_pair(a[i], b[i]) );
		sort ( v.begin(), v.end() );
		printf ( "%d\n", cnt );
		for ( i = 0; i < cnt; ++i ) printf ( "%.5lf %.5lf %.5lf %.5lf %.5lf\n", v[i].first.x, v[i].first.y, v[i].second.x, v[i].second.y, Length(v[i].first-v[i].second) );
	}
    return 0;
}
