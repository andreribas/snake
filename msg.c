#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define CICLOS 50000000
#define TAMRABO 200

void abertura(void){
   int a, x, y, cont, c;
   for(a=0;a<2;++a)
      for(x=1;x<=80;++x)
         for(y=1;y<=25;++y)
            for(cont=0;cont<CICLOS/10000;++cont)
               if(cont==0){
                  gotoxy(x,y);
                  printf("#");
               }
   for(x=1;x<=80;++x)
      for(y=1;y<=25;++y)
         for(cont=0;cont<CICLOS/10000;++cont)
            if(cont==0){
               gotoxy(x,y);
               printf(" ");
            }
   clrscr();
   printf("\n\n\n\n\n\n\n\n");
   printf("\t\t  SSSSSSS     NNN     NN   AAAAAA   KK   KK  EEEEEEE\n");
   printf("\t\t SSS    SSS   NNNN    NN  AA    AA  KK  KK   EE     \n");
   printf("\t\t  SSSS        NN NN   NN  AA    AA  KK KK    EE     \n");
   printf("\t\t   SSSSSS     NN  NN  NN  AAAAAAAA  KKKK     EEEEEEE\n");
   printf("\t\t      SSSS    NN   NN NN  AA    AA  KK KK    EE     \n");
   printf("\t\t SSS    SSS   NN    NNNN  AA    AA  KK  KK   EE     \n");
   printf("\t\t  SSSSSSSS    NN     NNN  AA    AA  KK   KK  EEEEEEE\n");
   for(;!kbhit();)
      for(cont=0;cont<CICLOS;++cont){
         if(cont==0){
            gotoxy(1,16);
            printf("\t\t                (PRESSIONE UMA TECLA PARA CONTINUAR)\n");
         }
         if(cont==(CICLOS*2)/3){
            gotoxy(1,16);
            clreol();
            gotoxy(80,25);
         }
      }
   c=getch();
   if(c==27) exit(0);
}


void crash(void){
   int a, x, y, cont,c;
   for(a=0;a<2;++a)
      for(x=1;x<=80;++x)
         for(y=1;y<=25;++y)
            for(cont=0;cont<CICLOS/10000;++cont)
               if(cont==0){
                  gotoxy(x,y);
                  printf("#");
               }
   for(x=1;x<=80;++x)
      for(y=1;y<=25;++y)
         for(cont=0;cont<CICLOS/10000;++cont)
            if(cont==0){
               gotoxy(x,y);
               printf(" ");
            }
   clrscr();
   printf("\n\n\n\n\n\n\n\n");
   printf("\t\t  CCCC   RRRRRR     AAAAAA    SSSSSSS    HH    HH  !!\n");
   printf("\t\t CC  CC  RR   RR   AA    AA  SSS    SSS  HH    HH  !!\n");
   printf("\t\tCC       RR   RR   AA    AA   SSSS       HH    HH  !!\n");
   printf("\t\tCC       RRRRR     AAAAAAAA    SSSSSS    HHHHHHHH  !!\n");
   printf("\t\tCC       RR  RR    AA    AA       SSSS   HH    HH  !!\n");
   printf("\t\t CC  CC  RR   RR   AA    AA  SSS    SSS  HH    HH    \n");
   printf("\t\t  CCCC   RR    RR  AA    AA   SSSSSSSS   HH    HH  !!\n");
   gotoxy(80,26);
   c=getch();
   if(c==27) exit(0);
}

void theend(void){
   int a, x, y, cont,c;
   clrscr();
   gotoxy(1,8);           
   printf("\t\tFFFFFFFFFF  IIIIII  MMMM      MMMM  !!\n");
   printf("\t\tFF            II    MM MM    MM MM  !!\n");
   printf("\t\tFF            II    MM  MM  MM  MM  !!\n");
   printf("\t\tFFFFFF        II    MM   MMMM   MM  !!\n");
   printf("\t\tFF            II    MM    MM    MM  !!\n");
   printf("\t\tFF            II    MM          MM    \n");
   printf("\t\tFF          IIIIII  MM          MM  !!\n");
   gotoxy(80,25);
   c=getch();
   if(c==27) exit(0);
   for(a=0;a<2;++a)
      for(x=1;x<80;++x)
         for(y=1;y<26;++y)
            for(cont=0;cont<CICLOS/10000;++cont)
               if(cont==0){
                  gotoxy(x,y);
                  printf("#");
               }
   for(x=1;x<80;++x)
      for(y=1;y<26;++y)
         for(cont=0;cont<CICLOS/10000;++cont)
            if(cont==0){
               gotoxy(x,y);
               printf(" ");
            }
}
void clvet(int *x, int *y){
   int cont;
   for(cont=0;cont<TAMRABO-1;cont++){
      x[cont]=39;
      y[cont]=13;
   }
   x[0]=40;
}
void help(void){
   clrscr();
   gotoxy(30,3);
   printf("PAUSE");
   gotoxy(10,5);
   printf("Esc - Sair do jogo a qualquer hora.");
   gotoxy(10,6);
   printf("F1 - Esta tela de ajuda");
   gotoxy(10,7);
   printf("F2 - Mostra os melhores pontos");
   gotoxy(10,8);
   printf("Setas - Direcionam a cobra.");
   getch();
}

