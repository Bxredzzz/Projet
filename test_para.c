#include "paramètre.h"

int main(){
  bool test;
  printf("Test is_methode: ");
  assert(test=is_methode("all","all")==true);
  assert(test=is_methode("cs","all")==false);
  assert(test=is_methode("uni1","uni2")==false);
  assert(test=is_methode("cm","cm")==true);
  printf("OK\n");
  printf("Test is_specified_fichier: ");
  assert(test=is_specified_fichier("txt","txt")==true);
  assert(test=is_specified_fichier("txt",".txt")==false);
  assert(test=is_specified_fichier("csv","txt")==false);
  assert(test=is_specified_fichier("csv","csv")==true);
  printf("OK\n");
  printf("Test exist: ");
  assert(test=exist("paramètre.h")==true);
  assert(test=exist("index.txt")==false);
  assert(test=exist("gusig.csv")==false);
  assert(test=exist("main.c")==true);
  printf("OK\n");
  printf("Test access_lecture: ");
  assert(test=access_lecture("paramètre.h")==true);
  assert(test=access_lecture("index.txt")==false);
  assert(test=access_lecture("gusig.csv")==false);
  assert(test=access_lecture("main.c")==true);
  printf("OK\n");
  printf("Test access_write: ");
  assert(test=access_write("paramètre.h")==true);
  assert(test=access_write("index.txt")==false);
  assert(test=access_write("gusig.csv")==false);
  assert(test=access_write("main.c")==true);
  printf("OK\n");
  printf("Test access_exec: ");
  assert(test=access_exec("test.txt")==true);
  assert(test=access_exec("index.txt")==false);
  assert(test=access_exec("gusig.csv")==false);
  assert(test=access_exec("main.c")==false);
  printf("OK\n");
  printf("                    FIN DES TESTS DE PARAMETRE.C\n");
}
