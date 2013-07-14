/*************************************************************************
    > File Name: splay_array.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月27日 星期四 16时07分29秒
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
const int maxn = 200005;
int num[maxn];
struct SplayTree {
	void Rotate(int x, int f) {//旋转
		int y = pre[x], z = pre[y];
		push_down(x);
		push_down(y);
		ch[y][f^1] = ch[x][f]; pre[ch[x][f]] = y;
		ch[x][f] = y; pre[y] = x;
		pre[x] = z;
		if ( pre[x] ) ch[z][ch[z][1] == y] = x;
		push_up(y);
	}
	void Splay(int x, int goal) {//提根
		push_down(x);
		while ( pre[x] != goal ) {
			if ( pre[pre[x]] == goal ) Rotate(x, ch[pre[x]][0] == x);
			else {
				int y = pre[x], z = pre[y];
				int f = (ch[z][0] == y);
				if ( ch[y][f] == x ) Rotate(x, f^1), Rotate(x, f);
				else Rotate(y, f), Rotate(x, f);
			}
		}
		push_up(x);
		if ( goal == 0 ) root = x;
	}
	void RotateTo(int k, int goal) {//把第k位的数转到goal的下面
		int x = root;
		push_down(x);
		while ( sz[ch[x][0]] != k ) {
			if ( k < sz[ch[x][0]] ) x = ch[x][0];
			else {
				k -= (sz[ch[x][0]] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x, goal);
	}
/*********************/
	void clear() {
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
		root = n = 0;
		//
		val[0] = mi[0] = INF;
		lazy1[0] = lazy2[0] = 0;

		NewNode(root, INF);
		NewNode(ch[root][1], INF);
		pre[n] = root;
		sz[root] = 2;
	}
	void NewNode(int &x, int c) {
		x = ++n;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
		//
		val[x] = mi[x] = c;
		lazy1[x] = lazy2[x] = 0;
	}
	void push_up(int x) {
		sz[x] = 1 + sz[ch[x][0]] + sz[ch[x][1]];
		mi[x] = min(mi[ch[x][0]], mi[ch[x][1]]);
		mi[x] = min(mi[x], val[x]);
	}
	void push_down(int x){
		if ( lazy1[x] ) {
			lazy1[ch[x][0]] ^= 1; lazy1[ch[x][1]] ^= 1;
			swap(ch[x][0], ch[x][1]);
			lazy1[x] = 0;
		}
		if ( lazy2[x] ) {
			if ( ch[x][0] ) {
				val[ch[x][0]] += lazy2[x];
				mi[ch[x][0]] += lazy2[x];
				lazy2[ch[x][0]] += lazy2[x];
			}
			if ( ch[x][1] ) {
				val[ch[x][1]] += lazy2[x];
				mi[ch[x][1]] += lazy2[x];
				lazy2[ch[x][1]] += lazy2[x];
			}
			lazy2[x] = 0;
		}
	}
	void init(int pos, int tot) {
		clear(); cnt = tot;
		RotateTo(pos, 0);
		RotateTo(pos+1, root);
		build(ch[ch[root][1]][0], 1, tot, ch[root][1]);
		push_up(ch[root][1]);
		push_up(root);
	}
	void build(int &x, int l, int r, int f) {
		if ( l > r ) return;
		int mid = (l+r)>>1;
		NewNode(x, num[mid]);
		build(ch[x][0], l, mid-1, x);
		build(ch[x][1], mid+1, r, x);
		pre[x] = f;
		push_up(x);
	}
/********************* 无序序列 ***************************/
	void add(int l, int r, int c) {
		if ( l > r ) swap(l, r);
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		int key = ch[ch[root][1]][0];
		val[key] += c;
		mi[key] += c;
		lazy2[key] += c;
		push_up(ch[root][1]);
		push_up(root);
	}
	void flip(int l, int r) {
		if ( l > r ) swap(l ,r);
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		int key = ch[ch[root][1]][0];
		lazy1[key] ^= 1;
		push_up(ch[root][1]);
		push_up(root);
	}
	void insert_at_pos(int pos, int c) {
		RotateTo(pos, 0);
		RotateTo(pos+1, root);
		int key;
		NewNode(key, c);
		ch[ch[root][1]][0] = key;
		pre[key] = ch[root][1];
		push_up(ch[root][1]);
		push_up(root);
	}
	void del(int pos) {
		RotateTo(pos-1, 0);
		RotateTo(pos+1, root);
		ch[ch[root][1]][0] = 0;
		push_up(ch[root][1]);
		push_up(root);
	}
	int quary_min(int l, int r) {
		RotateTo(l-1, 0);
		RotateTo(r+1, root);
		int key = ch[ch[root][1]][0];
		return mi[key];
	}
	void revolve(int l, int r, int t) {
		if ( l > r ) swap(l, r);
		int len = r-l+1;
		int idx = t%len;
		if ( idx ) {
			RotateTo(r-idx, 0);
			RotateTo(r+1, root);
			int key = ch[ch[root][1]][0];
			ch[ch[root][1]][0] = 0;
			push_up(ch[root][1]);
			push_up(root);

			RotateTo(l-1, 0);
			RotateTo(l, root);
			ch[ch[root][1]][0] = key;
			pre[key] = ch[root][1];
			push_up(ch[root][1]);
			push_up(root);
		}
	}


/********************* debug ***************************/
	void debug(int x) {
		if ( x ) {
			push_down(x);
			debug(ch[x][0]);
			printf ( "%d ", val[x] );
			debug(ch[x][1]);
		}
	}
	void Debug(){
		debug(root);
		puts("");
	}
/********************* 有序序列 ***************************/
	void add(int x) {
		++cnt;
		int k = 0, p = root;
		while ( p ) {
			push_down(p);
			if ( val[p] > x ) p = ch[p][0];
			else {
				k += sz[ch[p][0]] + 1;
				p = ch[p][1];
			}
		}
		RotateTo(k-1, 0);
		RotateTo(k, root);
		int key;
		NewNode(key, x);
		ch[ch[root][1]][0] = key;
		pre[key] = ch[root][1];
		push_up(ch[root][1]);
		push_up(root);
	}
	void del(int x) {
		int k = 0, p = root;
		while ( p ) {
			push_down(p);
			if ( val[p] >= x ) p = ch[p][0];
			else {
				k += sz[ch[p][0]] + 1;
				p = ch[p][1];
			}
		}
		RotateTo(0, 0);
		RotateTo(k, root);
		int key = ch[ch[root][1]][0];
		ch[ch[root][1]][0] = 0;
		push_up(root);
		cnt -= sz[key];
		leave += sz[key];
	}
	void updata(int c) {
		RotateTo(0, 0);
		RotateTo(cnt+1, root);
		int key = ch[ch[root][1]][0];
		val[key] += c;
		lazy[key] += c;
		push_up(root);
	}
	int query(int k) {//询问第k大的数
		if ( k > cnt ) return -1;
		k = cnt - k + 1;
		RotateTo(k-1, 0);
		RotateTo(k+1, root);
		int key = ch[ch[root][1]][0];
		return val[key];
	}

/********************* 有序序列END ***************************/
	int root, n, cnt;
	int ch[maxn][2];
	int pre[maxn];
	int sz[maxn];
	int val[maxn], mi[maxn];
	int lazy1[maxn], lazy2[maxn];

}spt;

int n, m;
int main()
{
	int a, b, c;
	char op[20];
	scanf ( "%d", &n );
	for ( int i = 1; i <= n; ++i ) scanf ( "%d", num+i );
	spt.init(0, n);
	//spt.Debug();
	scanf ( "%d", &m );
	while ( m-- ) {
		scanf ( "%s", op );
		if ( op[0] == 'A' ) {
			scanf ( "%d%d%d", &a, &b, &c );
			spt.add(a, b, c);
			//spt.Debug();
		}
		else if ( op[0] == 'R' && op[3] == 'E' ) {
			scanf ( "%d%d", &a, &b );
			spt.flip(a, b);
		}
		else if ( op[0] == 'R' && op[3] == 'O' ) {
			scanf ( "%d%d%d", &a, &b, &c );
			spt.revolve(a, b, c);
		}
		else if ( op[0] == 'I' ) {
			scanf ( "%d%d", &a, &b );
			spt.insert_at_pos(a, b);
		}
		else if ( op[0] == 'D' ) {
			scanf ( "%d", &a );
			spt.del(a);
		}
		else {
			scanf ( "%d%d", &a, &b );
			//spt.Debug();
			printf ( "%d\n", spt.quary_min(a, b) );
		}
		//spt.Debug();
	}

  return 0;
}
