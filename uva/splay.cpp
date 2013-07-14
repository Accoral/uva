/*************************************************************************
    > File Name: splay.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月21日 星期五 06时48分17秒
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
struct Node *null;
int cnt;//序列元素个数
struct Node {
	Node *ch[2];
	int s;//结点总数
	int flip;
	i64 v;
	int mi;
	int ma;
	i64 lazy;
	i64 sum;
	int cmp(int k) const {
		int d = k - ch[0]->s;
		if ( d == 1 ) return -1;
		return d <= 0 ? 0 : 1;
	}
	void maintain() {
		s = ch[0]->s + ch[1]->s + 1;
		mi = v;
		if ( ch[0] != null ) mi = min(mi, ch[0]->mi);
		if ( ch[1] != null ) mi = min(mi, ch[1]->mi);
		ma = v;
		if ( ch[0] != null ) ma = max(ma, ch[0]->ma);
		if ( ch[1] != null ) ma = max(ma, ch[1]->ma);
		sum = v;
		if ( ch[0] != null ) sum += ch[0]->sum;
		if ( ch[1] != null ) sum += ch[1]->sum;
	}
	void pushdown() {
		if(flip) {
			flip = 0;
			swap(ch[0], ch[1]);
			ch[0]->flip ^= 1; ch[1]->flip ^= 1;//ch[0]->flip = !ch[0]->flip;ch[1]->flip = !ch[1]->flip;
		}
		if(lazy) {
			ch[0]->v += lazy;
			ch[0]->mi += lazy;
			ch[0]->ma += lazy;
			ch[0]->sum += lazy*ch[0]->s;
			ch[0]->lazy += lazy;
			ch[1]->v += lazy;
			ch[1]->mi += lazy;
			ch[1]->ma += lazy;
			ch[1]->sum += lazy*ch[1]->s;
			ch[1]->lazy += lazy;
		}
		lazy = 0;
	}
};
void rotate(Node* &o, int d) {//旋转
  Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
  o->maintain(); k->maintain(); o = k; 
}

void splay(Node* &o, int k) {//找到序列的左数第k个元素并伸展到根
  o->pushdown();
  int d = o->cmp(k);
  if(d == 1) k -= o->ch[0]->s + 1;
  if(d != -1) {
    Node* p = o->ch[d];
    p->pushdown();
    int d2 = p->cmp(k);
    int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
    if(d2 != -1) {
      splay(p->ch[d2], k2);
      if(d == d2) rotate(o, d^1); else rotate(o->ch[d], d);
    }
    rotate(o, d^1);
  }
}

// 合并left和right。假定left的所有元素比right小。注意right可以是null，但left不可以
Node* merge(Node* left, Node* right) {
  splay(left, left->s);
  left->ch[1] = right;
  left->maintain();
  return left;
}

// 把o的前k小结点放在left里，其他的放在right里。1<=k<=o->s。当k=o->s时，right=null
void split(Node* o, int k, Node* &left, Node* &right) {
  splay(o, k);
  left = o;
  right = o->ch[1];
  o->ch[1] = null;
  left->maintain();
}
const int maxn = 100000 + 10;
int A[maxn];
struct SplaySequence {
	int n;
	Node seq[maxn];
	Node *root;

	Node* build(int sz) {
		if(!sz) return null;
		Node* L = build(sz/2);
		Node* o = &seq[++n];
		o->v = A[n-1];//结点编号;A[0]是虚拟结点
		o->ch[0] = L;
		o->ch[1] = build(sz - sz/2 - 1);
		o->flip = o->s = o->lazy = 0;
		o->ma = o->mi = o->sum = o->v;
		o->maintain();
		return o;
	}
	void init(int sz) {
		n = 0;
		null = new Node();
		null->s = null->v = null->sum = null->flip = null->lazy = 0;
		null->mi = INF;
		null->ma = -INF;
		root = build(sz);
	}
};
vector<int> ans;
void print(Node* o) {
  if(o != null) {
    o->pushdown();
    print(o->ch[0]);
    ans.push_back(o->v);
    print(o->ch[1]);
  }
}
void debug(Node* o) {
  if(o != null) {
    o->pushdown();
    debug(o->ch[0]);
    printf ( "%d ", o->v );
		//printf ( "  v=%d,s=%d,flip=%d,lazy=%d,mi=%d", o->v,o->s,o->flip,o->lazy2,o->mi);
		//printf ( "%d, left=%d,s=%d,mi=%d,*right=%d,s=%d,mi=%d\n", o->v, o->ch[0]->v,o->ch[0]->s,o->ch[0]->mi, o->ch[1]->v,o->ch[1]->s,o->ch[1]->mi );
    debug(o->ch[1]);
  }
}
SplaySequence ss;
/********************* 无序序列 ***************************/
void flip(int a, int b) {
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, b-a+1, mid, right);
	mid->flip ^= 1;
	ss.root = merge(merge(left, mid), right);
}
void query_min(int a, int b) {
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, b-a+1, mid, right);
	printf ( "%d\n", mid->mi );
	ss.root = merge(merge(left, mid), right);
}
void query_max(int a, int b) {
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, b-a+1, mid, right);
	printf ( "%d\n", mid->ma );
	ss.root = merge(merge(left, mid), right);
}
void update(int a, int b) {//单点更新 - -！
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, 1, mid, right);
	mid->v = b;
	mid->ma = b;
	mid->lazy = b;
	ss.root = merge(merge(left, mid), right);
}
void revolve(int a, int b, int t) {
	if(a>b) swap(a, b);
	int len = b - a + 1;
	int idx = t%len;
	if(idx) {
		Node *left, *mid, *right, *o;
		split(ss.root, a, left, o);
		split(o, b-a+1, mid, right);
		Node *l, *r;
		split(mid, len-idx, l, r);
		mid = merge(r, l);
		ss.root = merge(merge(left, mid), right);
	}
}
void insert_at_pos(int a, int c) {
	Node *left, *right, *o;
	split(ss.root, a+1, left, right);
	Node *mid = new Node();
	mid->ch[0] = mid->ch[1] = null;
	mid->s = 1;
	mid->v = mid->mi = c;
	mid->flip = mid->lazy = 0;
	ss.root = merge(merge(left, mid), right);
}
void del(int a) {
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, 1, mid, right);
	ss.root = merge(left, right);
}
void add(int a, int b, int c) {
	if(a > b) swap(a, b);
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, b-a+1, mid, right);
	mid->v += c;
	mid->mi += c;
	mid->sum += (i64)c*mid->s;
	mid->lazy += c;
	ss.root = merge(merge(left, mid), right);
}
void query_sum(int a, int b) {
	Node *left, *mid, *right, *o;
	split(ss.root, a, left, o);
	split(o, b-a+1, mid, right);
	printf ( "%lld\n", mid->sum );
	ss.root = merge(merge(left, mid), right);
}
/********************* 有序序列 ***************************/
int find_low(int x) {//小于x的最大值,虚拟结点的v=-INF;
	Node *p = ss.root, *ret = null;
	while ( p != null ) {
		if ( p->v <= x ) ret = p, p = p->ch[1];
		else p = p-> ch[0];
	}
	return ret->v;
}
int find_up(int x) {//大于x的最小值,null->v = INF;
	Node *p = ss.root, *ret = null;
	while ( p != null ) {
		if ( p->v >= x ) ret = p, p = p->ch[0];
		else p = p-> ch[1];
	}
	//if ( ret->v <= x ) return INF;
	return ret->v;
}
void add(int x) {//从小到大插入x, 虚拟结点的v=-INF;
	cnt++;
	Node *p = ss.root;
	int k = 0;
	while ( p != null ) {
		p->pushdown();
		if(p->v > x) p = p->ch[0];
		else {
			k += p->ch[0]->s + 1;
			p = p->ch[1];
		}
	}
	Node *left, *right;
	split(ss.root, k, left, right);
	Node *mid = new Node();
	mid->ch[0] = mid->ch[1] = null;
	mid->s = 1;//很关键
	mid->v = x; mid->lazy = 0;

	ss.root = merge(merge(left, mid), right);
}
void del(int x) {//删除比x小的数
	int k = 0;//k表示比x小的数的个数
	Node *p = ss.root;
	while ( p != null ) {
		p->pushdown();
		if(p->v >= x) p = p->ch[0];
		else {
			k += p->ch[0]->s + 1;
			p = p->ch[1];
		}
	}
	if(k == 1) return;
	Node *left, *mid, *right, *o;
	split(ss.root, 1, left, o);
	split(o, k-1, mid, right);
	ss.root = merge(left, right);

	cnt -= k-1;
	leave += k-1;
}
void del(int x) {//删除x,前提是x一定存在
	int k = 0;//k表示所有比x小的数的个数
	Node *p = ss.root;
	while ( p != null ) {
		//p->pushdown();
		if(p->v >= x) p = p->ch[0];
		else {
			k += p->ch[0]->s + 1;
			p = p->ch[1];
		}
	}
	//printf ( "k=%d\n", k );
	//if(k == 1) return;
	Node *left, *mid, *right, *o;
	split(ss.root, k, left, o);
	split(o, 1, mid, right);
	ss.root = merge(left, right);
	cnt--;
}
void updata(int c) {
	Node *left, *right;
	split(ss.root, 1, left, right);
	right->v += c;
	right->lazy += c;
	ss.root = merge(left, right);
}
int query(int k) {//询问第k大的数, cnt为序列元素个数
	if(cnt-1 < k) return -1;
	Node *left, *mid, *right, *o;
	k = cnt-k+1; //printf ( "k=%d\n", k );
	split(ss.root, k, left, right); //printf("left:");debug(left);puts("");
	ss.root = merge(left, right);
	return left->v;
}
/********************* 有序序列END ***************************/
int main()
{
  int n, m, a, b, c;
  scanf ( "%d", &n );
  A[0] = 1;
  for ( int i = 1; i <= n; ++i ) scanf ( "%d", A+i );
  scanf ( "%d", &m );
  ss.init(n+1); // 最前面有一个虚拟结点
  //puts("start:"); debug(ss.root); puts("");

  char s[15];
  while (m--) {
	scanf ( "%s", s );
	if ( strcmp(s,"ADD") == 0 ) {
		scanf ( "%d%d%d", &a, &b, &c );
		add(a,b,c);
		//debug(ss.root); puts("");
	}
	else if ( strcmp(s,"REVERSE") == 0 ) {
		scanf ( "%d%d", &a, &b );
		flip(a,b);
	}
	else if ( strcmp(s,"REVOLVE") == 0 ) {
		scanf ( "%d%d%d", &a, &b, &c );
		revolve(a,b,c);
		//debug(ss.root); puts("");
	}
	else if ( strcmp(s,"INSERT") == 0 ) {
		scanf ( "%d%d", &a, &b );
		insert_at_pos(a,b);
		//debug(ss.root); puts("");
	}
	else if ( strcmp(s,"DELETE") == 0 ) {
		scanf ( "%d", &a );
		del(a);
		//debug(ss.root); puts("");
	}
	else if ( strcmp(s,"MIN") == 0 ) {
		scanf ( "%d%d", &a, &b );
		//debug(ss.root); puts("");
		query_min(a,b);
	}
  }
  return 0;
}
