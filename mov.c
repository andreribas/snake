#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "msg.h"

#define CICLOS 50000000

void mov(int *x, int *y, int *sw, int *liv, long unsigned int *score, int *lev, int *xm, int *ym, int *stat, int qua){
   int iCont, li, z, quan=qua;
   for(iCont=0;iCont<(CICLOS / *lev);++iCont)
      if(iCont==0){
         clrscr();
         gotoxy(1,25);
         printf("SCORE: %d", *score);
         gotoxy(35,25);
         printf("LEVEL: %d", *lev/10);
         for( li = 0 , z = 79 ; li <= *liv ; ++li, --z){
            gotoxy(z,25);
            printf("%c", 3);
         }
         gotoxy(*xm,*ym);
         printf("O");
         if(*x!=81 && *x!=0 && *y!=0 && *y!=25){
            for(;qua>0;--qua){
               gotoxy(x[qua],y[qua]);
               printf("o");
            }
            gotoxy(x[0],y[0]);
            printf("@");
            for(qua=4;qua<quan;++qua)
               if(x[0]==x[qua] && y[0]==y[qua]){
                     crash();
                     clvet(x,y);
                     --*liv;
                     *sw=0;
                     *stat=0;
                  }
         }
         if(x[0]==81 || x[0]==0 || y[0]==0 || y[0]==25){
            crash();
            clvet(x,y);
            --*liv;
            *sw=0;
            *stat=0;
         }
         switch(*sw){
            case 0:
               ++x[0];
               break;
            case 1:
               --x[0];
               break;
            case 2:
               --y[0];
               break;
            case 3:
               ++y[0];
               break;
         }
      }
}

void mudamov(int *sw, int *x, int *y, int *stat, int *liv){
   int a, b;
   if(kbhit()){
      a = getch();
      if (a)
         switch(a){
            case 27: // Esc
               exit(0);
               break;
         }
      else
         b = getch();
      if(b)
         switch(b){
            case 75: // seta esquerda
               if(*sw==0){
                  crash();
                  clvet(x,y);
                  --*liv;
                  *sw=0;
                  *stat=0;
               }
               else
                   *sw=1;
               break;
            case 80: // seta baixo
               if(*sw==2){
                  crash();
                  clvet(x,y);
                  --*liv;
                  *sw=0;
                  *stat=0;
               }
               else
                   *sw=3;
               break;
            case 77: // seta direita
               if(*sw==1){
                  crash();
                  clvet(x,y);
                  --*liv;
                  *sw=0;
                  *stat=0;
               }
               else
                   *sw=0;
               break;
            case 72: // seta cima
               if(*sw==3){
                  crash();
                  clvet(x,y);
                  --*liv;
                  *sw=0;
                  *stat=0;
               }
               else
                   *sw=2;
               break;
            case 59: // F1
               help();
               break;
         }
   }
}
void maca(int *x, int *y, int *xm, int *ym, int *stat, int *score, int *qua){
   switch(*stat){
      case 0:
         *xm = (rand() % 80) +1;
         *ym = (rand() % 24) +1;
         if (*xm == x[0] && *ym == y[0]) *ym = (rand() % 24) +1;
         *stat=1;
         break;
      case 1:
         if(x[0] == *xm && y[0] == *ym){
            *score+=10;
            *qua+=1;
            *stat=0;
         }
         break;
   }
}
void chlevel(int *lev, int *score){
   switch(*score){
      case 100:
         *lev=20;
         break;
      case 200:
         *lev=30;
         break;
      case 400:
         *lev=40;
         break;
      case 800:
         *lev=50;
         break;
      case 1600:
         *lev=60;
         break;
      case 3200:
         *lev=70;
         break;
      case 6400:
         *lev=80;
         break;
      case 12800:
         *lev=90;
         break;
      case 25600:
         *lev=100;
         break;
   }
}
void rabo(int qua, int *x, int *y){
   for(  ; qua > 0 ; --qua)
      if( qua > 0 ){
         x[qua] = x[qua - 1];
         y[qua] = y[qua - 1];
      }
}
