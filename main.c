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
  t_mat_char_star_dyn tab_mots;
  t_mat_int_dyn mat_duel;
  int *clean = 1;

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
        do_balise((char) c,optarg,&g_para,logfp,&clean);
        break;
      case 'd':
        do_balise((char) c,optarg,&g_para,logfp,&clean);
        break;
      case 'o':
        do_balise((char) c,optarg,&g_para,logfp,&clean);
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
        do_balise((char) c,opta,&g_para,logfp,&clean);
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
 if(g_para.b_o==true){
   logfp=fopen(g_para.opt_o,"w+");
 }
 creer_t_mat_char_dyn(&tab_mots,1000,1000);
 if(g_para.b_i==true) read_voting_file(g_para.opt_i,",;",&tab_mots);
 if(g_para.b_d==true) read_voting_file(g_para.opt_d,",;",&tab_mots);
 fprintf(logfp,"Fichier de départ:\n");
 fprintf(logfp,"\n");
 affiche_t_mat_char_star_dyn(tab_mots,logfp);
 fprintf(logfp,"------------------------------------------------------------\n");
 fprintf(logfp,"\n");
 if(g_para.b_i==true){
   creer_t_mat_int_dyn(&mat_duel,tab_mots.nbCol-4,tab_mots.nbCol-4);
   if(clean==1){
     construct_mat_duels_d(tab_mots,&mat_duel,tab_mots.nbCol-4,false);
   }
   else{
     construct_mat_duels_d(tab_mots,&mat_duel,tab_mots.nbCol-4,true);
   }
   for(int i=0;i<tab_mots.nbCol-4;i++){
     fprintf(logfp,"candidat %d : %s\n",i,code_candidat(i,tab_mots));
   }
   fprintf(logfp,"------------------------------------------------------------\n");
   fprintf(logfp,"\n");
   fprintf(logfp,"Matrice de duel:\n");
   fprintf(logfp,"\n");
   affiche_t_mat_int_dyn(mat_duel,logfp);
   fprintf(logfp,"\n");
   fprintf(logfp,"------------------------------------------------------------\n");
   }
 else{
   for(int i=0;i<tab_mots.nbCol;i++){
     fprintf(logfp,"candidat %d : %s\n",i,code_candidat_d(i,tab_mots));
 }
 fprintf(logfp,"------------------------------------------------------------\n");
 fprintf(logfp,"\n");
}

 free(tab_mots.tab);
 free(mat_duel.tab);
 fclose(logfp);
}
