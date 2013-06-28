/*************************************************************************
    > File Name: 10652.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月28日 星期五 12时59分41秒
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
const double eps = 1E-10;
const double PI = acos(-1);
/****************************************************/
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
typedef Point Vector;
Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }

int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
bool operator < (const Point& a, const Point& b) {
  return dcmp(a.x-b.x) < 0 || (dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) < 0);
}
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }

Vector Rotate(const Vector& A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
double torad(double deg) { return deg/180 * PI; }

//点集凸包
//如果不希望在凸包的边上有输入点，把两个 <= 改成 <
//如果不介意点集被修改，可以改成传递引用
vector<Point> ConvexHull(vector<Point> p) {
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());//预处理，删除重复点
	int n = p.size();
	int m = 0;
	vector<Point> ch(n+1);
	for ( int i = 0; i < n; ++i ) {
		while ( m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0 ) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for ( int i = n-2; i >= 0; --i ) {
		while ( m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0 ) m--;
		ch[m++] = p[i];
	}
	if ( n > 1 ) m--;
	ch.resize(m);
	return ch;
}
double PolygonArea(vector<Point> p) {
	double area = 0;
	int n = p.size();
	for ( int i = 1; i < n-1; ++i ) area += Cross(p[i]-p[0], p[i+1]-p[0]);
	return area/2;
}
int main()
{
	int T, n, i;
	double x, y, w, h, j, area;
	vector<Point> p, q;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		p.clear();
		area = 0;
		for ( i = 0; i < n; ++i ) {
			scanf ( "%lf%lf%lf%lf%lf", &x, &y, &w, &h, &j );
			Point M(x,y);
			double ang = -torad(j);
			p.push_back(M+Rotate(Vector(-w/2, -h/2), ang));
			p.push_back(M+Rotate(Vector( w/2, -h/2), ang));
			p.push_back(M+Rotate(Vector( w/2,  h/2), ang));
			p.push_back(M+Rotate(Vector(-w/2,  h/2), ang));
			area += w*h;
		}
		q = ConvexHull(p);
		printf ( "%.1lf %%\n", 100*area/PolygonArea(q) );
	}
	return 0;
}
