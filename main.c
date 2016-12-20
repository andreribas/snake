#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "msg.h"
#include "mov.h"

#define CICLOS 50000000
#define TAMRABO 200

void main(void){
// ínicio das declarações de variaveis.
   long unsigned int score=0;
   int liv, lev, stat, cont, x[TAMRABO], y[TAMRABO], sw, xm, ym, qua;
   char ch, name[50];
   time_t t;
   FILE *fp;
// Fim das declarações de variaveis.
   srand(time(&t));
   for(liv=2, lev=10, stat=0, sw=0, qua=5;;liv=2, lev=10, stat=0, sw=0, score=0, qua=5){
      abertura();
      clvet(x, y);
      for(;liv>=0;){
      if(qua==199) qua=5;
         maca(x, y, &xm, &ym, &stat, &score, &qua);
         rabo(qua, x, y);
         mudamov(&sw, &x, &y, &stat, &liv);
         chlevel(&lev, &score);
         mov(x, y, &sw, &liv, &score, &lev, &xm, &ym, &stat, qua);
      }
      clrscr();
      if((fp = fopen("scores.bst","a+"))==NULL){
         system("attrib -h -s -r scores.bst");
         fp = fopen("scores.bst","a+");
      }
      gotoxy(7,12);
      if(score>0) printf("Parab‚ns, vocˆ marcou %u pontos, insira seu nome:\n", score);
      else printf("Insira seu nome.");
      gotoxy(7,13);
      gets(name);
      fprintf(fp,"%u pts - %s\n", score, name);
      flushall();
      system("attrib +h +s +r scores.bst");
      fclose(fp);
      theend();
   }
}

