#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
stack < char > op;
stack < int > num;
map < char, int > mymap;
map < char, int > :: iterator it;
string expression, str;
int len_expression, i, tmp, value, count;
void fun ( ) {
	if ( num.size ( ) == 2 ) {
		count = 1;
		int b = num.top ( );
		num.pop ( );
		int a = num.top ( );
		num.pop ( );
		char c = op.top ( );
		if ( c == '-' ) value = a - b;
		else value = a + b;
		num.push ( value );
		//cout << "a = " << a << '\t' << "b = " << b <<  "\t***value" << " = " << value << "\n";
	}
}
int main ( ) {
	while ( getline ( cin, expression ) ) {
		while ( !num.empty ( ) ) num.pop ( );
		while ( !op.empty ( ) ) op.pop ( );
		for ( mymap.clear ( ), str.clear ( ), len_expression = expression.length ( ), count = i = 0; i < len_expression; ++i )
			if ( expression[i] == ' ' ) continue;
			else str += expression[i];
		//cout << str << "\n";
		cout << "Expression: " << expression << "\n";
		if ( len_expression == 0 ) {
			cout << "    value" << " = 0\n";
			continue;
		}
		for ( len_expression = str.length ( ), i = 0;i < len_expression;  ) {
			//cout << "i=" << i <<'\t'<<str[i]<< endl;
			if ( (i+1<len_expression&&isalpha(str[i+1])) ||
					(i+2<len_expression&&!isalpha(str[i])&& str[i+1]==str[i+2]) ) {//+
				op.push ( str[i] );
				++i;
				continue;
			}
			if ( i+1<len_expression&&i+2<len_expression && str[i] == str[i+1] ) {//++x
				mymap[str[i+2]] = str[i+2] - 'a' + 1;
				if ( str[i] == '-' ) {
					num.push ( --mymap[str[i+2]] );
				}
				else {
					num.push ( ++mymap[str[i+2]] );
				}
				fun ( );
				i += 3;
				continue;
			}
			if ( i+1<len_expression&&i+2<len_expression&&str[i+1]==str[i+2] ) {//x++;
				mymap[str[i]] = str[i] - 'a' + 1;
				if ( str[i+1] == '-' ) {
					num.push ( mymap[str[i]]-- );
				}
				else {
					num.push ( mymap[str[i]]++ );
				}
				fun ( );
				i += 3;
				continue;
			}
			mymap[str[i]] = str[i] - 'a' + 1;
			num.push ( mymap[str[i]] );
			fun ( );
			++i;
		}
		if ( count == 0 ) value = num.top ( );
		cout << "    value" << " = " << value << "\n";
		for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
			cout << "    " << it->first << " = " << it->second << "\n";
	}
}
