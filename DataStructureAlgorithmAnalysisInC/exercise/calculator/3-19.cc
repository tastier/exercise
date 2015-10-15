#include "stackar.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define STACKSIZE 10
using namespace std;

int main( ) 
{ 
	string str;
	int num1 = 0, num2 = 0, num3 = 0;
	Stack S;

	cout << "input a formula: ";
	cin >> str;

	S = CreateStack( STACKSIZE );

	for( int i = 0; i < str.size( ); ++i) { 
		if( str[i] != '+' && str[i] != '-' 
			&& str[i] != '*' && str[i] != '/' ){ 
//			num = num * 10 + str[i] - 48;
			Push( str[i] - 48, S);
		}
		else { 
			num1 = TopAndPop( S );
			num2 = TopAndPop( S );

			switch ( str[i] ) { 
				case '+':
					num3 = num1 + num2;
					break;
				case '-':
					num3 = num2 - num1;
					break;
				case '*':
					num3 = num1 * num2;
					break;
				case '/':
					num3 = num2 / num1;
					break;
			}
			Push( num3, S );
		}
	}
	cout << "result is : " << Top( S ) << endl;

	DisposeStack( S );

	return 0;
}
