#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector < string > v;
int main ( ) {
	string s, tmp;
	int n, first = 0, i, j, k, sum, flag, leni, lenj, lenk, len;
	while ( cin >> n ) {
		getline ( cin, s );//'\n'
		getline ( cin, s );
		while ( n-- ) {
			if ( first ) cout << "\n";
			else first = 1;
			v.clear ( );
			i = 0, sum = 0;
			while ( 1 ) {
				getline ( cin, s );
				//cout << "s=" << s << endl;
				if ( s == "" ) break;
				v.push_back ( s );
				sum += s.length ( );
				++i;
			}
			len = sum / (i / 2);
			for ( flag = 1, i = 0; flag && i < v.size ( ); ++i ) {
				leni = v[i].length ( );
				for ( j = i + 1; flag && j < v.size ( ); ++j ) {
					lenj = v[j].length ( );
					if ( leni + lenj == len ) {
						tmp = v[i] + v[j];
						for ( k = 0; k < v.size ( ); ++k ) {
							//cout << '*' << k ;
							lenk = v[k].length ( );
							//cout << "this"<<tmp << ' '<<v[k]<< endl;
							//cout << tmp.compare ( 0, lenk, v[k] ) <<' '<< tmp.compare ( len-lenk, lenk,v[k] )<<endl;
							if ( tmp.compare ( 0, lenk, v[k] ) !=0&&
									tmp.compare ( len-lenk, lenk,v[k] )!=0 ) {
								break;
							}
						}
						//cout << "k=" << k << endl;
						if ( k == v.size ( ) ) {
							cout << tmp << "\n";
							flag = 0;
						}
					}
				}
			}
			//cout << len << endl;
		}
	}
}
