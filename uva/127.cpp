#include <iostream>
#include <stack>
#include <list>
#include <string>
using namespace std;
list < stack < string > > :: iterator it, it_3, it_1,it_tmp;
int i, n;
int main ( ) {
	string s;
	while ( 1 ) {
		cin >> s;
		if ( s == "#" ) break;
		list < stack < string > > mylist;
		stack < string > mystack;
		mystack.push ( s );
		mylist.push_back ( mystack );
		for ( i = 1; i < 52; ++i ) {
			cin >> s;
			stack < string > mystack;
			mystack.push ( s );
			mylist.push_back ( mystack );
		}
		//for ( it = mylist.begin ( ); it != mylist.end ( ); ++it ) cout << it->top ( ) << " " << it->size ( ) << endl;
		for ( it = mylist.begin ( ); it != mylist.end ( ) ;  ) {
			it_1 = it_3 = it;
			for ( i = 0; i < 3; ++i ) {
				if ( it_3 == mylist.begin ( ) ) break;
				--it_3;
			}
			if ( i == 3 ) {
				if ( it->top()[0] == it_3->top()[0] || it->top()[1] == it_3->top()[1] ) {
					it_3->push ( it->top() );
					it->pop ( );
					if ( it->empty ( ) ) mylist.erase ( it );
					it = mylist.begin ( );
					continue;
				}
			}
			for ( i = 0; i < 1; ++i ) {
				if ( it_1 == mylist.begin ( ) ) break;
				--it_1;
			}
			if ( i == 1 ) {
				if ( it->top()[0] == it_1->top()[0] || it->top()[1] == it_1->top()[1] ) {
					it_1->push ( it->top ( ) );
					it->pop ( );
					if ( it->empty ( ) ) mylist.erase ( it );
					it = mylist.begin ( );
					continue;
				}
			}
			++it;
			//for ( it_tmp = mylist.begin ( ); it_tmp != mylist.end ( ); ++it_tmp ) cout << it_tmp->top ( ) << " " << it_tmp->size ( ) << "|";cout << "\n";
		}
		//for ( it = mylist.begin ( ); it != mylist.end ( ); ++it ) cout << it->top ( ) << " " << it->size ( ) << endl;
		if ( mylist.size ( ) == 1 ) cout << "1 pile remaining:";
		else cout << mylist.size ( ) << " piles remaining:";
		for ( it = mylist.begin ( ); it != mylist.end ( ); ++it ) cout << " " << it->size ( );
		cout << "\n";
	}
}
