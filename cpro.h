#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

// A singe binary output interpreting 8 binary inputs must be a binary fuction defined for
// the set of all 256 possible input states. hence the blocksize. For ever combination of the
// 8 bits in an ascii chariture or 1 byte that we could encounterneed, we need 256 idividual
// bit-definitions or of equivalent size 32 ascii letters

// block is assumed to be bit block unless stated otherwise

#define BitPerChar 8
#define BitPerByte BitPerChar
#define BitBlockPerCharBlock BitPerChar
#define CharPerBlock  32
#define BytePerBlock CharPerBlock
#define BitPerBlock  256 
#define CharPerCharBlock BitPerBitBlock
#define BytePerCharBlock BitPerBitBlock
#define BitPerCharBlock  2048
#define DeclareCharBlock(var)   unsigned char var[ BitPerChar ][ CharPerBlock ]
#define DeclareBitBlock(var)   unsigned char var[ CharPerBlock ]
#define Byte(var)  unsigned char var[ BitPerChar ]

#define ByteToChar( byte )\
    byte[ 0 ]+ 2*byte[ 1 ] + 4*byte[ 2 ] + 8*byte[ 3 ] + 16*byte[ 4 ] + 32*byte[ 5 ] + 64*byte[ 6 ] + 64*byte[ 7 ]

#define BitsToChar(bitA , bitB , bitC , bitD , bitE , bitF , bitG , bitH )\
    bitA + 2*bitB + 4*bitC + 8*bitD + 16*bitE + 32*bitF + 64*bitG + 64*bitH

#define BitsToByte( bitA , bitB , bitC , bitD , bitE , bitF , bitG , bitH )\
    {\
        bitA , bitB, bitC,bitD,bitE,bitF,bitG,bitH\
    }

#define CharToBit(chr,bit)\
    (\
        true &((chr>>(bit%BitPerChar)))? true : false\
    )

#define CharToByte( chr , bit )\
    {\
        ( true & (chr >> (0%BitPerChar) ) ? true : false),\
        ( true & (chr >> (1%BitPerChar) ) ? true : false),\
        ( true & (chr >> (2%BitPerChar) ) ? true : false),\
        ( true & (chr >> (3%BitPerChar) ) ? true : false),\
        ( true & (chr >> (4%BitPerChar) ) ? true : false),\
        ( true & (chr >> (5%BitPerChar) ) ? true : false),\
        ( true & (chr >> (6%BitPerChar) ) ? true : false),\
        ( true & (chr >> (7%BitPerChar) ) ? true : false)\
    }

#define BitNode( charIn , bitblock )\
    (\
        true & ( bitblock[ charIn / BitPerChar ] >> ( charIn%BitPerChar ) ) ? true : false\
    )

#define CharNode( in , charblock )\
    BitsToChar(\
        BitNode( in , charblock[ 0 ] ),\
        BitNode( in , charblock[ 1 ] ),\
        BitNode( in , charblock[ 2 ] ),\
        BitNode( in , charblock[ 3 ] ),\
        BitNode( in , charblock[ 4 ] ),\
        BitNode( in , charblock[ 5 ] ),\
        BitNode( in , charblock[ 6 ] ),\
        BitNode( in , charblock[ 7 ] )\
    )

#define CharCondenser( string , block )\
     BitsToChar(\
        BitNode( string[0] , block[0] ),\
        BitNode( string[1] , block[1] ),\
        BitNode( string[2] , block[2] ),\
        BitNode( string[3] , block[3] ),\
        BitNode( string[4] , block[4] ),\
        BitNode( string[5] , block[5] ),\
        BitNode( string[6] , block[6] ),\
        BitNode( string[7] , block[7] )\
    )

// optional convince funcs
//feel free to omit this part

#define ForBitPerChar( func )\
    for( bitperchar = 0; bitperchar < BitPerChar; bitperchar++ ){\
        func\
    }

#define ForBitBlockPerCharBlock( func )\
    for( bitblockpercharblock = 0; bitblockpercharblock < BitBlockPerCharBlock; bitblockpercharblock++ ){\
        func\
    }

#define ForBitPerByte( func )\
    for( bitperbyte = 0; bitperbyte < BitPerByte; bitperbyte++ ){\
        func\
    }

#define ForCharPerBlock( func )\
    for( charperblock = 0; charperblock < CharPerBlock; charperblock++ ){\
        func\
    }

#define ForBytePerBlock( func )\
    for( byteperblock =0; byteperblock < BytePerBlock; byteperblock++ ){\
        func\
    }

#define ForBitPerBlock( func )\
    for( bitperblock = 0; bitperblock < BitPerBlock; bitperblock++ ){\
        func\
    }

#define SetRandCharBlock( charblock )\
    ForBitPerChar(\
        ForCharPerBlock(\
            charblock[ bitperchar ][ charperblock ] = rand()%BitPerBlock;\
        )\
    ) 


#define printi(x)    printf( "%d" , x )
#define printc(x)    printf( "%c" , x )
#define prints(x)    printf( "%s" , x )
#define printd(x)    printf( "%lf" , x )

#define printblock( charblock )\
        ForBitBlockPerCharBlock(\
            ForCharPerBlock(\
                ForBitPerChar(\
                    printi(\
                        CharToBit(\
                            charblock[ bitblockpercharblock ][ charperblock ] , bitperchar\
                        )\
                    );\
                )\
            )\
            printf( "\n" );\
        )

#define Cprog( prog )\
    int main( int argc , char*argv[] ){\
        unsigned char bitperchar , bitperblock , bitperbyte , bitblockpercharblock , charperblock , byteperblock ;\
        srand( time( NULL ) );\
            prog\
    return 0; }
