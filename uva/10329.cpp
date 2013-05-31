/*************************************************************************
    > File Name: 10329.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月30日 星期四 20时52分16秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
const int maxn = 200;
struct bign{
  int len, s[maxn];
  bign() {
    memset(s, 0, sizeof(s));
    len = 1;
  }

  bign(int num) {
    *this = num;
  }

  bign(const char* num) {
    *this = num;
  }

  bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }

  bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
  }

  string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }

  void clean() {
    while(len > 1 && !s[len-1]) len--;
  }

  bign operator * (const bign& b) {
    bign c; c.len = len + b.len;
    for(int i = 0; i < len; i++)
      for(int j = 0; j < b.len; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }
};

istream& operator >> (istream &in, bign& x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator << (ostream &out, const bign& x) {
  out << x.str();
  return out;
}
typedef pair<int,int> II;
typedef vector<int> IV;
typedef vector<II> IIV;
typedef vector<bool> BV;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 5000; //sqrt(2^31)
const int SQRP = 71; //sqrt(MAX)
int _c[(MAXP>>6)+1];
IV primes;
void prime_sieve() {
	for ( int i = 3; i <= SQRP; i += 2 )
		if ( !IsComp(i) ) for ( int j = i*i; j <= MAXP; j+=i+i ) SetComp(j);
	primes.push_back ( 2 );
	for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp(i) ) primes.push_back ( i );
}
int get_powers ( int n, int p ) {
	int res = 0; for ( int power = p; power <= n; power *= p ) res += n/power; return res;
}
bign pow_mod ( int a, int cnt ) {
	if ( cnt == 0 ) return 1;
	bign x = pow_mod ( a, cnt/2 );
	bign ans = x*x;
	if ( cnt&1 ) ans=ans*a;
	return ans;
}
/*
   被坑的地方，调试好久才发现 - - 判断-1和判断0的顺序问题～不能随便break
*/
int main()
{
	//cout << sqrt ( 5000 ) << endl;
	prime_sieve ( );
	//For ( IV, it, primes ) printf ( "%d ", *it ); printf ( "\n" );
	//cout << primes.size() << endl;//669
	int n, m, N, R;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		map < int, int > mymap;
		while ( n-- ) {
			scanf ( "%d%d", &N, &R );
			For ( IV, it, primes ) mymap[*it] += get_powers(N,*it) - get_powers(N-R,*it) - get_powers(R,*it);
		}
		while ( m-- ) {
			scanf ( "%d%d", &N, &R );
			For ( IV, it, primes ) mymap[*it] -= get_powers(N,*it) - get_powers(N-R,*it) - get_powers(R,*it);
		}
		/*
		bign ans = 1;
		int ok = 1;
		For ( IV, it, primes ) 
			if ( mymap[*it] < 0 ) {
				ok = 0;
				break;
			}
			else {
				int a = *it, cnt = mymap[*it];
				//ans = ans*pow_mod ( a, cnt );
				for ( int i = 0; i < cnt; ++i ) {
					ans = ans * a;
					if ( ans.len >= 101 ) {
						ok = -1;
						break;
					}
				}
				//if ( ok == -1 ) break;//这个条件不能加，可能更后面还有<0的。
			}
		if ( ok == 0 ) printf ( "0\n" );
		else if ( ok == -1 ) printf ( "-1\n" );
		else cout << ans << "\n";
		*/
		bign ans = 1;
		int ok = 1;
		For ( IV, it, primes ) if ( mymap[*it] < 0 ) {
			ok = 0;
			break;
		}
		if ( ok == 0 ) printf ( "0\n" );
		else {
			For ( IV, it, primes ) {
				ans = ans * pow_mod ( *it, mymap[*it] );
				if ( ans.len >= 101 ) {
					ok = -1;
					break;
				}
			}
			if ( ok == -1 ) printf ( "-1\n" );
			else cout << ans << "\n";
		}
	}
    return 0;
}
