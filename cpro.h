#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define BitPerChar 8
#define BitPerByte BitPerChar
#define CharPerBlock  32
#define BytePerBlock CharPerBlock
#define BitPerBlock  256 
/*A singe binary output interpreting 8 binary inputs must be a binary fuction defined for
the set of all 256 possible input states. hence the blocksize. For ever combination of the
8 bits in an ascii chariture or 1 byte that we could encounterneed, we need 256 idividual
 bit-definitions or of equivalent size 32 ascii letters*/
#define ForBitPerChar(func)     for(bitperchar=0;bitperchar<BitPerChar;bitperchar++){func}
#define ForBitPerByte(func)     for(bitperbyte=0;bitperbyte<BitPerByte;bitperbyte++){func}   
#define ForCharPerBlock(func)     for(charperblock=0;charperblock<CharPerBlock;charperblock++){func}
#define ForCharPerBlock(func)     for(byteperblock=0;byteperblock<BytePerBlock;byteperblock++){func}
#define ForBitPerBlock(func)     for(bitperblock=0;bitperblock<BitPerBlock;bitperblock++){func}
//#define ForBitPerChar(func, byte, tion) funk byte[0] tion funk byte[1] tion
#define CharBlock(var)   unsigned char var[BitPerChar][CharPerBlock]
#define BitBlock(var)   unsigned char var[CharPerBlock]
#define Byte  unsigned char var[BitPerChar]
#define SetRandBlock(block)   for (j = 0; j < BitPerChar; j++){forC(block[j][i]=rand()%BitPerBlock;)} 
#define ByteToChar(bit)     byte[0]+ 2*byte[1]+ 4*byte[2]+ 8*byte[3]+ 16*byte[4]+ 32*byte[5]+ 64*byte[6]+ 64*byte[7]
#define BitsToChar(bitA,bitB,bitC,bitD,bitE,bitF,bitG,bitH)     bitA+ 2*bitB+ 4*bitC+ 8*bitD+ 16*bitE+ 32*bitF+ 64*bitG+ 64*bitH
#define BitsToByte(bitA,bitB,bitC,bitD,bitE,bitF,bitG,bitH)     {bitA , bitB, bitC,bitD,bitE,bitF,bitG,bitH}
#define CharToBit(chr,bit) (true &((chr>>(bit%BitPerChar)))? true : false)
#define CharToByte(chr,bit) {(true &((chr>>(0%BitPerChar)))? true : false),(true &((chr>>(1%BitPerChar)))? true : false),(true &((chr>>(2%BitPerChar)))? true : false),(true &((chr>>(3%BitPerChar)))? true : false),(true &((chr>>(4%BitPerChar)))? true : false),(true &((chr>>(5%BitPerChar)))? true : false),(true &((chr>>(6%BitPerChar)))? true : false),(true &((chr>>(7%BitPerChar)))? true : false)}
#define BitNode(in,block)     (true &((block[in/BitPerChar]>>(in%BitPerChar)))? true : false)
#define CharNode(in,block)     BitsToChar(BitNode(block[0],in),BitNode(block[1],in),BitNode(block[2],in),BitNode(block[3],in),BitNode(block[4],in),BitNode(block[5],in),BitNode(block[6],in),BitNode(block[7],in))
#define CharCondenser(chrA,chrB,chrC,chrD,chrE,chrF,chrG,chrH,block)     BitsToChar(BitNode(block[0],chrA),BitNode(block[1],chrB),BitNode(block[2],chrC),BitNode(block[3],chrD),BitNode(block[4],chrE),BitNode(block[5],chrF),BitNode(block[6],chrG),BitNode(block[7],chrH))
#define Cprog(prog)int main(unsigned int argc , char*argv[]){unsigned char bitperchar,bitperbyte,bitperblock,charperblock,byteperblock;srand(time(NULL)); prog return 0;}
#define printi(x)    printf("%d\n",x)
#define printc(x)    printf("%c\n",x)
#define prints(x)    printf("%s\n",x)
#define printd(x)    printf("%lf\n",x)

