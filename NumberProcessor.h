#ifndef NUMBERPROCESSOR_H_INCLUDED
#define NUMBERPROCESSOR_H_INCLUDED

#include <iostream> 
#include <string> 
#include <math.h>

using namespace std ;

const int decimalList[16] = { 0, 1, 2, 3, 4, 5, 6, 7,
                              8, 9, 10, 11, 12, 13, 14, 15 } ;
const char hexadecimalList[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                               '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' } ;
const string binaryList[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                                "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" } ;
const int bit4List[4] = { 8, 4, 2, 1 } ; 

class NumberProcessor {
	
	private :
		
		int StringToInt( string temp ) ; // string -> int 
		string IntToString( int num ) ; // int -> string 
		string ReverseString( string str ) ;
		string Not( string binaryStr ) ; // 1 -> 0 ; 0 -> 1
		string BitBecome4( string binaryStr ) ; // numbers of bits become the multiple of 4
		string HandlePositiveNegativeHexString( bool positive, string number ) ;
	
	public :
		
		NumberProcessor() ; // constructor 
		
		string DecimalToHexadecimal( string decimal, int charSize ) ; // "Decimal number string" -> "Hexadecimal number string" // 10 -> 16			
		string DecimalToHexadecimal( int decimal, int charSize ) ; // "Decimal number int" -> "Hexadecimal number string" // 10 -> 16			
		string DecimalToHexadecimal( string decimal ) ; // "Decimal number string" -> "Hexadecimal number string" // 10 -> 16			
		string DecimalToHexadecimal( int decimal ) ; // "Decimal number int" -> "Hexadecimal number string" // 10 -> 16			
		
		string HexadecimalToBinary( string hexadecimal ) ; // "Hexadecimal number string" -> "Binary number string" // 16 -> 2  
		string BinaryToHexadecimal( string binary ) ; // "Binary number string" -> "Hexadecimal number string" // 2 -> 16  
		int HexadecimalToDecimal( string hexadecimal ) ; // "Hexadecimal number string" -> "Decimal number int" // 16 -> 10 // only consider " positive -> positive " 
		int HexadecimalToDecimal( bool positive, string hexadecimal ) ; // "Hexadecimal number string" -> "Decimal number int" // 16 -> 10 
		
		string HexadecimalAddition( string hex1, string hex2 ) ; // hex1 + hex2 // only consider " positive + positive " 		
		string HexadecimalSubtraction( string hex1, string hex2 ) ; // hex1 - hex2 // only consider " positive - positive "
		string HexadecimalAddition( bool positive1, string hex1, bool positive2, string hex2 ) ; // hex1 + hex2 // positive1:hex1  positive2:hex2
		string HexadecimalSubtraction( bool positive1, string hex1, bool positive2, string hex2 ) ; // hex1 - hex2 // positive1:hex1  positive2:hex2
		
		string GetHexPart( string hexStr, int charNum, bool positive ) ; // [0,1,...,n] from n to 0 
		string HeadExtendHex( string hexStr, int length, bool positive ) ; // 123 -> 000123 or FFF123
		string TailExtendHex( string hexStr, int length ) ; // 123 -> 123000
		
		~NumberProcessor() ; // destructor 
	
} ; // class NumberProcessor 

NumberProcessor::NumberProcessor() { // constructor 
	
} // NumberProcessor::NumberProcessor()   

string NumberProcessor::DecimalToHexadecimal( string decimal, int charSize ) { // "Decimal number string" -> "Hexadecimal number string" // 10 -> 16	

	return DecimalToHexadecimal( StringToInt( decimal ), charSize ) ;
	
} // NumberProcessor::DecimalToHexadecimal()

string NumberProcessor::DecimalToHexadecimal( int decimal, int charSize ) { // "Decimal number int" -> "Hexadecimal number string" // 10 -> 16			
	
	int quotient = 0, remainder = 0 ;
	string hexStr = "" ;
	bool positive = true ;
	
	if ( decimal < 0 ) {
		positive = false ;
		decimal = decimal * (-1) ;
	} // if 
	else if ( decimal == 0 ) {
		hexStr = hexStr + "0" ;
	} // else if 
	
	while ( decimal != 0 ) {
		remainder = decimal % 16 ;
		hexStr = hexadecimalList[remainder] + hexStr ;
		decimal = decimal / 16 ;
	} // while 
	
	if ( charSize >= 0 ) {
		return ( positive ? HeadExtendHex( hexStr, charSize, true ) :
		                    HeadExtendHex( BinaryToHexadecimal( Not( HexadecimalToBinary( HexadecimalSubtraction( hexStr, "1" ) ) ) ),
										   charSize, false ) ) ;
	} // if 
	else { // charSize < 0
		return HandlePositiveNegativeHexString( positive, hexStr ) ;		
	} // else 
	
} // NumberProcessor::DecimalToHexadecimal()    

string NumberProcessor::DecimalToHexadecimal( string decimal ) { // "Decimal number string" -> "Hexadecimal number string" // 10 -> 16		
	
	return DecimalToHexadecimal( StringToInt( decimal ), -1 ) ;
	
} // NumberProcessor::DecimalToHexadecimal()    
		
string NumberProcessor::DecimalToHexadecimal( int decimal ) { // "Decimal number int" -> "Hexadecimal number string" // 10 -> 16			
	
	return DecimalToHexadecimal( decimal, -1 ) ;
	
} // NumberProcessor::DecimalToHexadecimal()
	
string NumberProcessor::HexadecimalToBinary( string hexadecimal ) { // "Hexadecimal number string" -> "Binary number string" // 16 -> 2  
	
	string binaryStr = "" ;
	
	for ( int i = 0 ; i < hexadecimal.length() ; i++ ) { 
		if ( '0' <= hexadecimal[i] && hexadecimal[i] <= '9' ) {
			binaryStr = binaryStr + binaryList[ hexadecimal[i] - '0' ] ;
		} // if
		else if ( 'A' <= hexadecimal[i] && hexadecimal[i] <= 'F' ) {
			binaryStr = binaryStr + binaryList[ (int)hexadecimal[i] - 55 ] ;
		} // else 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalToBinary() ; \"" << hexadecimal << "\" is not a hexadecimal string ! )" << endl ;
			return "" ;
		} // else 	
	} // for
	
	return binaryStr ;
	
} // NumberProcessor::HexadecimalToBinary() 

string NumberProcessor::BinaryToHexadecimal( string binary ) { // "Binary number string" -> "Hexadecimal number string" // 2 -> 16  
	
	binary = BitBecome4( binary ) ;
	
	string hexadecimalStr = "" ;
	
	for ( int i = 0, j = 0, listIndex = 0 ; i < binary.length() ; j = 0, listIndex = 0 ) {
		for ( ; j < 4 ; i++, j++ ) {
			if ( binary[i] == '1' ) {
				listIndex = listIndex + bit4List[j] ;
			} // if
			else if ( binary[i] == '0' ) {
				listIndex = listIndex + 0 ;
			} // else if 
			else {
				cout << "( ERROR : NumberProcessor::BinaryToHexadecimal() ; \"" << binary << "\" is not a binary string ! )" << endl ;
				return "" ;
			} // else 
		} // for
		hexadecimalStr = hexadecimalStr + hexadecimalList[listIndex] ;
	} // for 
	
	return hexadecimalStr ;
	
} // NumberProcessor::BinaryToHexadecimal()

int NumberProcessor::HexadecimalToDecimal( string hexadecimal ) { // "Hexadecimal number string" -> "Decimal number int" // 16 -> 10  
	
	/* only consider " positive -> positive " */
	
	int i = 0, value = 0 ;

    for ( int mul = hexadecimal.length() - 1 ; i < hexadecimal.length() ; i++, mul-- ) {
    	if ( '0' <= hexadecimal[i] && hexadecimal[i] <= '9' ) {
    		value = value + ( hexadecimal[i] - '0' ) * pow( 16, mul ) ;
		} // if
		else if ( 'A' <= hexadecimal[i] && hexadecimal[i] <= 'F' ) {
			value = value + ( (int)hexadecimal[i] - 55 ) * pow( 16, mul ) ;
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalToDecimal() ; \"" << hexadecimal << "\" is not a hexadecimal string ! )" << endl ;
			return 0 ;
		} // else 
    } // for 
	
	return value ; 	
	
} // NumberProcessor::HexadecimalToDecimal() 

int NumberProcessor::HexadecimalToDecimal( bool positive, string hexadecimal ) { // "Hexadecimal number string" -> "Decimal number int" // 16 -> 10 
	
	if ( positive ) {
		return HexadecimalToDecimal( hexadecimal ) ; 
	} // if
	else {
		return (-1) * HexadecimalToDecimal( HexadecimalAddition( BinaryToHexadecimal( Not( HexadecimalToBinary( hexadecimal ) ) ), "1" ) ) ;
	} // else	
	
} // NumberProcessor::HexadecimalToDecimal()   
	
string NumberProcessor::HexadecimalAddition( string hex1, string hex2 ) { // hex1 + hex2 
	
	/* only consider positive + positive */
	
	if ( hex1.length() > hex2.length() ) {
		hex2 = GetHexPart( hex2, hex1.length(), true ) ; // "0"... + hex2 
	} // if
	else if ( hex1.length() < hex2.length() ) {
		hex1 = GetHexPart( hex1, hex2.length(), true ) ; // "0"... + hex1 
	} // else if 
	
	string result = "" ;
	int carry = 0 ;
	
	for ( int i = hex1.length() - 1, value = 0 ; i >= 0 ; i--, value = carry ) {
		
		if ( '0' <= hex1[i] && hex1[i] <= '9' ) {
			value = value + ( hex1[i] - '0' ) ;  
		} // if
		else if ( 'A' <= hex1[i] && hex1[i] <= 'F' ) {
			value = value + ( (int)hex1[i] - 55 ) ;  
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalAddition() ; \"" << hex1 << "\" is not a hexadecimal string ! )" << endl ;
			return "" ;
		} // else
		
		if ( '0' <= hex2[i] && hex2[i] <= '9' ) {
			value = value + ( hex2[i] - '0' ) ;  
		} // if
		else if ( 'A' <= hex2[i] && hex2[i] <= 'F' ) {
			value = value + ( (int)hex2[i] - 55 ) ;  
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalAddition() ; \"" << hex2 << "\" is not a hexadecimal string ! )" << endl ;
			return "" ;
		} // else
		
		if ( value > 15 ) {
			carry = 1 ;
			result = hexadecimalList[value-16] + result ; 
		} // if
		else {
			carry = 0 ;
			result = hexadecimalList[value] + result ; 
		} // else
		
	} // for  
	
	return ( carry != 1 ? result : "1" + result ) ;
	
} // NumberProcessor::HexadecimalAddition()  

string NumberProcessor::HexadecimalSubtraction( string hex1, string hex2 ) { // hex1 - hex2 
	
	/* only consider positive - positive */
	
	bool positive = true ;
	
	if ( hex1.length() > hex2.length() ) {
		hex2 = GetHexPart( hex2, hex1.length(), true ) ; // "0"... + hex2 
	} // if
	else if ( hex1.length() < hex2.length() ) {
		hex1 = GetHexPart( hex1, hex2.length(), true ) ; // "0"... + hex1 
	} // else if 
	
	for ( int i = 0 ; i < hex1.length() ; i++ ) {
		if ( hex1[i] > hex2[i] ) { // compare char ( ascii : '0'->48, 'A'->65 ) 
			break ;
		} // if 	
		else if ( hex1[i] < hex2[i] ) {
			positive = false ;
			/* swap */
			string temp = hex1 ;
			hex1 = hex2 ;
			hex2 = temp ;
			break ;
		} // else if 
	} // for
	
	string result = "" ;
	int borrow = 0, value = 0 ;
	
	for ( int i = hex1.length() - 1 ; i >= 0 ; i--, value = borrow ) {
		
		if ( '0' <= hex1[i] && hex1[i] <= '9' ) {
			value = value + ( hex1[i] - '0' ) ;  
		} // if
		else if ( 'A' <= hex1[i] && hex1[i] <= 'F' ) {
			value = value + ( (int)hex1[i] - 55 ) ;  
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalSubtraction() ; \"" << hex1 << "\" is not a hexadecimal string ! )" << endl ;
			return "" ;
		} // else
		
		if ( '0' <= hex2[i] && hex2[i] <= '9' ) {
			value = value - ( hex2[i] - '0' ) ;  
		} // if
		else if ( 'A' <= hex2[i] && hex2[i] <= 'F' ) {
			value = value - ( (int)hex2[i] - 55 ) ;  
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::HexadecimalSubtraction() ; \"" << hex2 << "\" is not a hexadecimal string ! )" << endl ;
			return "" ;
		} // else
		
		if ( value < 0) {
			borrow = -1 ;
			result = hexadecimalList[value+16] + result ; 
		} // if
		else {
			borrow = 0 ;
			result = hexadecimalList[value] + result ; 
		} // else
		
	} // for 
	
	return HandlePositiveNegativeHexString( positive, result ) ;
	
} // NumberProcessor::HexadecimalSubtraction()  

string NumberProcessor::HexadecimalAddition( bool positive1, string hex1, bool positive2, string hex2 ) { // hex1 + hex2 // positive1:hex1  positive2:hex2 
	
	if ( positive1 && positive2 ) {
		return HexadecimalAddition( hex1, hex2 ) ;
	} // if
	else {
		
		int maxLength = ( hex1.length() > hex2.length() ? hex1.length() : hex2.length() ) ;
		int dec1 = ( positive1 ? HexadecimalToDecimal( hex1 ) :
								 (-1) * HexadecimalToDecimal( HexadecimalAddition( BinaryToHexadecimal( Not( HexadecimalToBinary( hex1 ) ) ), "1" ) ) ) ;
		int dec2 = ( positive2 ? HexadecimalToDecimal( hex2 ) :
								 (-1) * HexadecimalToDecimal( HexadecimalAddition( BinaryToHexadecimal( Not( HexadecimalToBinary( hex2 ) ) ), "1" ) ) ) ;
		
		return DecimalToHexadecimal( IntToString( dec1 + dec2 ), maxLength + 1 ) ;
		
	} // else 
	
} // NumberProcessor::HexadecimalAddition() 

string NumberProcessor::HexadecimalSubtraction( bool positive1, string hex1, bool positive2, string hex2 ) { // hex1 - hex2 // positive1:hex1  positive2:hex2
	
	if ( positive1 && positive2 ) {
		return HexadecimalSubtraction( hex1, hex2 ) ;
	} // if
	else {
		
		int maxLength = ( hex1.length() > hex2.length() ? hex1.length() : hex2.length() ) ;
		int dec1 = ( positive1 ? HexadecimalToDecimal( hex1 ) :
								 (-1) * HexadecimalToDecimal( HexadecimalAddition( BinaryToHexadecimal( Not( HexadecimalToBinary( hex1 ) ) ), "1" ) ) ) ;
		int dec2 = ( positive2 ? HexadecimalToDecimal( hex2 ) :
								 (-1) * HexadecimalToDecimal( HexadecimalAddition( BinaryToHexadecimal( Not( HexadecimalToBinary( hex2 ) ) ), "1" ) ) ) ;
		
		return DecimalToHexadecimal( IntToString( dec1 - dec2 ), maxLength + 1 ) ;
		
	} // else 
	
} // NumberProcessor::HexadecimalSubtraction()   
	
string NumberProcessor::GetHexPart( string hexStr, int charNum, bool positive ) { // [0,1,...,n] from n to 0 
	
	if ( hexStr.length() > charNum ) {
		
		string part = "" ;
		for ( int i = hexStr.length() - charNum ; i < hexStr.length() ; i++ ) {
			part = part + hexStr[i] ;
		} // for  
		return part ;
		
	} // if
	else if ( hexStr.length() < charNum ) {
		
		string fillIn = ( positive ? "0" : "F" ) ;
		
		for ( int i = charNum - hexStr.length() ; i > 0 ; i-- ) {
			hexStr = fillIn + hexStr ; // put "fillIn" in the empty places 
		} // for  
		return hexStr ;
		
	} // else if
	else {
		return hexStr ;
	} // else 	
	
} // NumberProcessor::GetHexPart()   

string NumberProcessor::HeadExtendHex( string hexStr, int length, bool positive ) { // 123 -> 000123 or FFF123
	
	if ( hexStr.length() >= length ) {
		return hexStr ;
	} // if 
	else {
		string fillIn = ( positive ? "0" : "F" ) ;
		for ( int i = length - hexStr.length() ; i > 0 ; i-- ) {
			hexStr = fillIn + hexStr ; // put "fillIn" in the empty places 
		} // for  
		return hexStr ;
	} // else 	
	
} // NumberProcessor::HeadExtendHex()  

string NumberProcessor::TailExtendHex( string hexStr, int length ) { // 123 -> 123000
	
	if ( hexStr.length() >= length ) {
		return hexStr ;
	} // if 
	else {
		for ( int i = length - hexStr.length() ; i > 0 ; i-- ) {
			hexStr = hexStr + "0" ; // put "fillIn" in the empty places 
		} // for  
		return hexStr ;
	} // else 	
	
} // NumberProcessor::TailExtendHex() 
	
NumberProcessor::~NumberProcessor() { // destructor 
	
} // NumberProcessor::~NumberProcessor()  


/*--------------------*/
/*  private function  */
/*--------------------*/

int NumberProcessor::StringToInt( string temp ) { // string -> int 

	string str = "" ;
	
	for ( int i = 0 ; i < temp.length() ; i++ ) {
		if ( temp[i] != ' ' && temp[i] != '\t' && temp[i] != '\n' ) { // not white 
			str = str + temp[i] ;
		} // if
	} // for

	int i = ( str[0] == '-' ? 1 : 0 ), value = 0 ;

    for ( int mul = str.length() - i - 1 ; i < str.length() ; i++, mul-- ) {
    	if ( '0' <= str[i] && str[i] <= '9' ) {
    		value = value + ( str[i] - '0' ) * pow( 10, mul ) ;
		} // if
		else {
			cout << "( ERROR : NumberProcessor::StringToInt() ; \"" << temp << "\" is not a number string ! )" << endl ;
			return 0 ;
		} // else 
    } // for 

    return ( str[0] == '-' ? value * (-1) : value ) ;

} // NumberProcessor::StringToInt()

string NumberProcessor::IntToString( int num ) { // int -> string 
	
	string temp = "", temp2 = "" ;
	
	if ( num < 0 ) {
		num *= (-1) ;
		temp2 += '-' ;
	} // if	
	
	do {
		temp += (char)( num % 10 + '0' ) ;
		num /= 10 ;
	} while ( num != 0 ) ;
	
	for ( int i = temp.length() - 1 ; i >= 0 ; i-- )
		temp2 += temp[i] ;
	
	return temp2 ;
	
} // NumberProcessor::IntToString()

string NumberProcessor::ReverseString( string str ) {
	
	string result = "" ;
	
	for ( int i = str.length() - 1 ; i >= 0 ; i-- ) {
		result = result + str[i] ;
	} // for 
	
	return result ;
		
} // NumberProcessor::ReverseString()  

string NumberProcessor::Not( string binaryStr ) { // 1 -> 0 ; 0 -> 1
	
	string result = "" ;
	
	for ( int i = 0 ; i < binaryStr.length() ; i++ ) {
		if ( binaryStr[i] == '0' ) {
			result = result + "1" ;
		} // if
		else if ( binaryStr[i] == '1' ) {
			result = result + "0" ;
		} // else if 
		else {
			cout << "( ERROR : NumberProcessor::Not() ; \"" << binaryStr << "\" is not a bianry string ! )" << endl ;
			return "" ;
		} // else 
	} // for 
	
	return result ;
	
} // NumberProcessor::Not()  

string NumberProcessor::BitBecome4( string binaryStr ) { // numbers of bits become the multiple of 4 
	
	int zero = 4 - binaryStr.length() % 4 ;
	
	if ( zero != 4 ) {
		while ( zero-- ) {
			binaryStr = "0" + binaryStr  ;
		} // while 
	} // if 
	
	return binaryStr ;
	
} // NumberProcessor::BitBecome4()   

string NumberProcessor::HandlePositiveNegativeHexString( bool positive, string number ) {
	
	if ( ! positive ) {
		number = BinaryToHexadecimal( Not( HexadecimalToBinary( HexadecimalSubtraction( number, "1" ) ) ) ) ;		
	} // if 
	
	int value = 0 ;
	
	if ( number.length() != 0 ) {
		if ( '0' <= number[0] && number[0] <= '9' ) {
			value = number[0] - '0' ;  
		} // if
		else if ( 'A' <= number[0] && number[0] <= 'F' ) {
			value = (int)number[0] - 55 ;  
		} // else if 
	} // if
	
	return ( positive ? ( 0 <= value && value <= 7 ? number : "0" + number ) :
	                    ( 8 <= value && value <= 15 ? number : "F" + number ) ) ;
	
} // NumberProcessor::HandlePositiveNegativeHexString()    

#endif // NUMBERPROCESSOR_H_INCLUDED










