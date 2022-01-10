#ifndef PARAMETRE_H
#define PARAMETRE_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

typedef struct s_balise_option{
  bool b_i,b_d,b_o,b_m;
  char* opt_i;
  char* opt_d;
  char* opt_o;
  char* opt_m;
}b_o;

void do_balise(char balise, char* next_chaine, b_o *g_para,FILE *logfp);
bool is_specified_fichier(char* chaine,char* extension);
bool exist(char* chaine);
bool access_lecture(char* chaine);
bool access_write(char* chaine);
bool access_exec(char* chaine);
bool is_methode(char* chaine,char* methode);
#endif
