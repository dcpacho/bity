#include "cpro.h"
#include <stdio.h>
Cprog( 
        unsigned char in[9];
        unsigned char mid;
        unsigned char out=0;
        unsigned char target;
        if(argc<2){
            printf("enter your 8 intput char and hit enter\n");
            fflush(stdin);
            ForBitBlockPerCharBlock(
                in[bitblockpercharblock]=getchar();
            )
        getchar();
        in[8]='\0';
        printf("enter your target char and hit enter\n");
        fflush(stdin);
        target=getchar();
        getchar();
    }
        else {
            ForBitBlockPerCharBlock(
                in[bitblockpercharblock]=argv[1][bitblockpercharblock];
            )
            in[8]='\0';
            target=argv[2][0];
        }
        DeclareCharBlock(A);        
        DeclareCharBlock(B);        
        DeclareCharBlock(C);        
        while(out!=target){
            SetRandCharBlock(A);        
            SetRandCharBlock(B);        
            SetRandCharBlock(C);        
            mid=CharNode(CharCondenser(in,A),B);
            printc(mid);
            out=CharNode(mid,C);
            printc(out);
        }
        printf("\nthe output at input%s is now %c\nthe truth tables or \"blocks\"\nhit enter to print block A",in,out);
        getchar();
        printblock(A)
        printf("\nhit enter to print block B");
        getchar();
        printblock(B)
        printf("\nhit enter to print block C");
        getchar();
        printblock(C)
    ) 