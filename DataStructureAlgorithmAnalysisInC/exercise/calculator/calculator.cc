#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool
is_operator( const string &str )
{ 
	if( str	== "+" || str == "-" 
			|| str == "*" || str == "/"
			|| str == "(" || str == ")" )
		return true;
	return false;
}

// str1 > str2, return 1
// str1 < str2, return -1
// str1 == str2, return 0
int
priority( const string &str1, const string &str2)
{ 
	int num1, num2;
	
	if( str1 == "+" || str1 == "-" )
		num1 = 1;
	else if( str1 == "*" || str1 == "/" )
		num1 = 2;
	else
		num1 = 3;
	
	if( str2 == "+" || str2 == "-")
		num2 = 1;
	else if( str2 == "*" || str2 == "/")
		num2 = 2;
	else 
		num2 = 3;

	if( num1 == num2 )
		return 0;
	else if( num1 > num2)
		return 1;
	else
		return -1;
}

vector<string>
infix2postfix( const vector<string> &vec )
{ 
	stack<string> s;
	vector<string> ret;
	
	for( size_t i = 0; i < vec.size( ); ++i ) { 
		if( is_operator( vec[i] ) ) {
			if( vec[i] == "(" )
				s.push( vec[i] );
			else if( vec[i] == ")" ) { 
				while( s.top( ) != "(" ) { 
					ret.push_back( s.top( ) );
					s.pop( );
				}
				s.pop( ); // pop "("
			}
			else {
				if( s.empty( )) { 
					s.push( vec[i] ) ;
					continue;
				}
				if( s.top( ) == "(" )
					s.push( vec[i] );
				else { 
					while( !s.empty( ) && s.top( ) != "("
							&& priority( s.top( ), vec[i] ) >= 0 ) { 
						ret.push_back( s.top( ) );
						s.pop( ) ;
					}
					s.push( vec[i] );
				}
			}
		} 
		else { 
			ret.push_back( vec[i] );
		}
	}
	while( !s.empty( ) ) { 
		ret.push_back( s.top( ) );
		s.pop( ) ;
	}
	return ret;
}

int
calculate( const vector<string> vec )
{ 
	int num1 = 0, num2 = 0, num3 = 0;
	stack<int> s;

	for( int i = 0; i < vec.size( ); ++i) { 
		if( !is_operator( vec[i] ) ){ 
			s.push( atoi( vec[i].c_str( ) ) );
		}
		else { 
			num1 = s.top( );
			s.pop( ) ;
			num2 = s.top( ) ;
			s.pop( ) ;

			if( vec[i] == "+" )
				num3 = num1 + num2;
			if( vec[i] == "-" )		
				num3 = num2 - num1;
			if( vec[i] == "*" )		
				num3 = num1 * num2;
			if( vec[i] == "/" )	
				num3 = num2 / num1;
			
			s.push( num3 );
		}
	}
	return s.top( ) ;
}

int main( ) 
{ 
	vector<string> vec;
	vector<string> ret;
	string str;
	string element;

	while( 1 ) {
	vec.clear( ) ;
	ret.clear( ) ;
	str.clear( ) ;
	element.clear( ) ;

	cout << "input a formula: ";
	cin >> str;
	if( str == "q")
		break;

	for( int i = 0; i < str.size( ) ; ++i ) { 
		if( str[i] == '+' || str[i] == '-' 
			|| str[i] == '*' || str[i] == '/'
			|| str[i] == '(' || str[i] == ')' ) { 
			if( !element.empty( ) ) { 
				vec.push_back( element ) ;
				element.clear( ) ;
			}
			vec.push_back( string( &str[i], 1) ) ; // 调用string的构造函数实现char到string的转换，见primer，P321
		}
		else { 
			element += str[i];
			if( i == str.size( ) -1 )
				vec.push_back( element );
		}
	}
		

	ret = infix2postfix( vec );

	cout << "result is : " << calculate( ret ) << endl;
	} 
/*	for( auto &s : ret)
		cout << s;
	cout << endl;
*/
	return 0;
}
