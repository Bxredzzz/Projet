#include "global.h"



int main(int argc,char **argv){
  FILE *logfp;
  logfp=stdout;
  b_o g_para;
  g_para.b_i=false;
  g_para.b_d=false;
  g_para.b_o=false;
  g_para.b_m=false;
  int c;
  char* opta=NULL;
  if (argc == 1){
    printf("aucun paramètre n'est présent\n");
    exit(EXIT_FAILURE);
  }
  else if (argc%2==0){
    printf("il manque un paramètre\n");
    exit(EXIT_FAILURE);
  }
  while ((c=getopt(argc,argv,"i:d:o:m:"))!=EOF){
    switch(c){
      case 'i':
        do_balise((char) c,optarg,&g_para,logfp);
        break;
      case 'd':
        do_balise((char) c,optarg,&g_para,logfp);
        break;
      case 'o':
        do_balise((char) c,optarg,&g_para,logfp);
        break;
      case 'm':
        if(is_methode(optarg,"uni1")) opta="uni1";
        else if(is_methode(optarg,"uni2")) opta="uni2";
        else if(is_methode(optarg,"cm")) opta="cm";
        else if(is_methode(optarg,"cs")) opta="cs";
        else if(is_methode(optarg,"all")) opta="all";
        else{
          printf("erreur argument invalide -m\n");
          exit(EXIT_FAILURE);
        }
        do_balise((char) c,opta,&g_para,logfp);
        break;
      case '?':
        exit(EXIT_FAILURE);
        break;
  }
 }
 if(g_para.b_i==false && g_para.b_d==false){
   printf("il faut avoir la balise i ou d!\n");
   exit(EXIT_FAILURE);
 }
}
