#include "NumberProcessor.h"

NumberProcessor numProc ;

int main() {
	
	cout << "---DecimalToHexadecimal--" << endl ;
	
	cout << numProc.DecimalToHexadecimal( "0", 6 ) << endl ; // 00 0000
	cout << numProc.DecimalToHexadecimal( 0, 6 ) << endl ; // 00 0000
	cout << numProc.DecimalToHexadecimal( "0" ) << endl ; // 0
	cout << numProc.DecimalToHexadecimal( 0 ) << endl ; // 0
	cout << numProc.DecimalToHexadecimal( "984321", 9 ) << endl ; // 0 000F 0501
	cout << numProc.DecimalToHexadecimal( 984321, 9 ) << endl ; // 0 000F 0501
	cout << numProc.DecimalToHexadecimal( "984321" ) << endl ; // 0F 0501
	cout << numProc.DecimalToHexadecimal( 984321 ) << endl ; // 0F 0501
	cout << numProc.DecimalToHexadecimal( "", 3 ) << endl ; // 000
	cout << numProc.DecimalToHexadecimal( "" ) << endl ; // 0
	cout << numProc.DecimalToHexadecimal( "-98760", 10 ) << endl ; // FF FFFE 7E38
	cout << numProc.DecimalToHexadecimal( -98760, 10 ) << endl ; // FF FFFE 7E38
	cout << numProc.DecimalToHexadecimal( "-98760" ) << endl ; // E 7E38
	cout << numProc.DecimalToHexadecimal( -98760 ) << endl ; // E 7E38
	cout << numProc.DecimalToHexadecimal( "-256" ) << endl ; // F00
	cout << numProc.DecimalToHexadecimal( -256 ) << endl ; // F00
	
	cout << "---HexadecimalToBinary--" << endl ;
	
	cout << numProc.HexadecimalToBinary( "A43" ) << endl ; // 1010 0100 0011 
	cout << numProc.HexadecimalToBinary( "EF09B" ) << endl ; // 1110 1111 0000 1001 1011
	cout << numProc.HexadecimalToBinary( "" ) << endl ; //
	
	cout << "---BinaryToHexadecimal--" << endl ;
	
	cout << numProc.BinaryToHexadecimal( "1010" ) << endl ; // A 
	cout << numProc.BinaryToHexadecimal( "00110" ) << endl ; // 06
	cout << numProc.BinaryToHexadecimal( "101011" ) << endl ; // 2B
	cout << numProc.BinaryToHexadecimal( "1111111" ) << endl ; // 7F
	cout << numProc.BinaryToHexadecimal( "00000000" ) << endl ; // 00
	cout << numProc.BinaryToHexadecimal( "" ) << endl ; //
	
	cout << "---HexadecimalAddition--" << endl ;
	
	cout << numProc.HexadecimalAddition( "12AC", "D438" ) << endl ; // E6E4 
	cout << numProc.HexadecimalAddition( "CDF", "ABCEE" ) << endl ; // A C9CD 
	cout << numProc.HexadecimalAddition( "ABCDEF", "537" ) << endl ; // AB D326 
	cout << numProc.HexadecimalAddition( "FFFFFF", "FFFFFF" ) << endl ; // 1FF FFFE 
	cout << numProc.HexadecimalAddition( "FFFFFF", "FFFFF" ) << endl ; // 10F FFFE 
	cout << numProc.HexadecimalAddition( "FFF", "FFFF00" ) << endl ; // 100 0EFF 
	cout << numProc.HexadecimalAddition( "123", "" ) << endl ; // 123
	cout << numProc.HexadecimalAddition( "", "123" ) << endl ; // 123 
	cout << numProc.HexadecimalAddition( "", "" ) << endl ; //
	
	cout << "---HexadecimalSubtraction--" << endl ;
	
	cout << numProc.HexadecimalSubtraction( "12AC", "D438" ) << endl ; // F 3E74 
	cout << numProc.HexadecimalSubtraction( "CDF", "ABCEE" ) << endl ; // F5 4FF1
	cout << numProc.HexadecimalSubtraction( "ABCDEF", "537" ) << endl ; // 0AB C8B8 
	cout << numProc.HexadecimalSubtraction( "FFFFFF", "FFFFFF" ) << endl ; // 00 0000 
	cout << numProc.HexadecimalSubtraction( "FFFFFF", "FFFFF" ) << endl ; // 0F0 0000 
	cout << numProc.HexadecimalSubtraction( "FFF", "FFFF00" ) << endl ; // F00 10FF
	cout << numProc.HexadecimalSubtraction( "123", "" ) << endl ; // 123 
	cout << numProc.HexadecimalSubtraction( "", "123" ) << endl ; // EDD 
	cout << numProc.HexadecimalSubtraction( "", "" ) << endl ; //
	
	cout << "---GetHexPart--" << endl ;
	
	cout << numProc.GetHexPart( "987654321", 0, true ) << endl ;    //
	cout << numProc.GetHexPart( "987654321", 7, true ) << endl ;    // 7654321
	cout << numProc.GetHexPart( "987654321", 3, true ) << endl ;    // 321
	cout << numProc.GetHexPart( "987654321", 5, true ) << endl ;    // 54321
	cout << numProc.GetHexPart( "987654321", 9, true ) << endl ;    // 987654321
	cout << numProc.GetHexPart( "987654321", 15, true ) << endl ;   // 000000987654321
	cout << numProc.GetHexPart( "987654321", 15, false ) << endl ;  // FFFFFF987654321
	cout << numProc.GetHexPart( "", 10, true ) << endl ;            // 0000000000
	cout << numProc.GetHexPart( "", 10, false ) << endl ;           // FFFFFFFFFF
	
	cout << "---HexadecimalToDecimal--" << endl ;
	
	cout << numProc.HexadecimalToDecimal( "" ) << endl ; // 0
	cout << numProc.HexadecimalToDecimal( "0" ) << endl ; // 0
	cout << numProc.HexadecimalToDecimal( "1" ) << endl ; // 1
	cout << numProc.HexadecimalToDecimal( "10" ) << endl ; // 16
	cout << numProc.HexadecimalToDecimal( "100" ) << endl ; // 256
	cout << numProc.HexadecimalToDecimal( "FFFF" ) << endl ; // 6 5535
	cout << numProc.HexadecimalToDecimal( "FDBCA" ) << endl ; // 103 9306
	cout << numProc.HexadecimalToDecimal( "FDEBCA" ) << endl ; // 1664 0970
	
	cout << "---HexadecimalToDecimal--" << endl ;
	
	cout << numProc.HexadecimalToDecimal( false, "FFFF" ) << endl ; // -1
	cout << numProc.HexadecimalToDecimal( false, "EBCA" ) << endl ; // -5174
	cout << numProc.HexadecimalToDecimal( false, "9EBF" ) << endl ; // -24897
	
	cout << "---HexadecimalAddition--" << endl ;
	
	cout << numProc.HexadecimalAddition( true, "FFFFFF", true, "FFFFFF" ) << endl ; // 1FF FFFE 
	cout << numProc.HexadecimalAddition( false, "F", true, "1" ) << endl ; // "-1"d + "1"d = "0"d ("00"h) 
	cout << numProc.HexadecimalAddition( true, "FF", false, "FFA4" ) << endl ; // "255"d + "-92"d = "000A3"h
	cout << numProc.HexadecimalAddition( false, "FF", false, "FFA4" ) << endl ; // "-1"d + "-92"d = "FFFA3"h
	
	cout << "---HexadecimalSubtraction--" << endl ;
	
	cout << numProc.HexadecimalSubtraction( true, "ABCDEF", true, "537" ) << endl ; // 0AB C8B8 
	cout << numProc.HexadecimalSubtraction( false, "F", true, "1" ) << endl ; // "-1"d - "1"d = "-2"d ("FE"h) 
	cout << numProc.HexadecimalSubtraction( true, "FF", false, "FFA4" ) << endl ; // "255"d - "-92"d = "0015B"h
	cout << numProc.HexadecimalSubtraction( false, "FF", false, "FFA4" ) << endl ; // "-1"d - "-92"d = "0005B"h
	cout << numProc.HexadecimalSubtraction( false, "FFA4", false, "FF" ) << endl ; // "-92"d - "-1"d = "FFFA5"h
	
	cout << "---HeadExtendHex--" << endl ;
	
	cout << numProc.HeadExtendHex( "ABCDE", 10, true ) << endl ; // 00000ABCDE
	cout << numProc.HeadExtendHex( "ABCDE", 10, false ) << endl ; // FFFFFABCDE
	cout << numProc.HeadExtendHex( "ABCDE", 3, true ) << endl ; // ABCDE
	cout << numProc.HeadExtendHex( "ABCDE", 0, true ) << endl ; // ABCDE
	
	cout << "---TailExtendHex--" << endl ;
	
	cout << numProc.TailExtendHex( "ABCDE", 10 ) << endl ; // ABCDE00000
	cout << numProc.TailExtendHex( "ABCDE", 7 ) << endl ; // ABCDE00
	cout << numProc.TailExtendHex( "ABCDE", 3 ) << endl ; // ABCDE
	cout << numProc.TailExtendHex( "ABCDE", 0 ) << endl ; // ABCDE
	
} // main()























