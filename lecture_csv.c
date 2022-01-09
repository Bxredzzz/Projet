#include "lecture_csv.h"
#include "traitement.h"

void creer_t_mat_char_dyn(t_mat_char_star_dyn *s_tabmots,int nbRows,int nbCol){
  s_tabmots->tab=malloc(nbRows*sizeof(char**));
  if (s_tabmots->tab==NULL){
    printf("problème d'allocation\n");
    exit(EXIT_FAILURE);
  }
  for(int i=0;i<nbRows;i++){
    s_tabmots->tab[i]=malloc(nbCol*sizeof(char*));
    if (s_tabmots->tab[i]==NULL){
      printf("problème d'allocation\n");
      exit(EXIT_FAILURE);
    }
  }
  s_tabmots->nbRows=nbRows;
  s_tabmots->nbCol=nbCol;
}



void affiche_t_mat_char_star_dyn(t_mat_char_star_dyn s_tabmots, FILE *outfp){
  for(int i=0;i<s_tabmots.nbRows;i++){
    for(int j=0;j<s_tabmots.nbCol;j++){
      if(s_tabmots.tab[i][j]!=NULL) fprintf(outfp," %s",s_tabmots.tab[i][j]);;
    }
    fprintf(outfp,"\n");
 }

}

void read_voting_file(char * filename,const char *delimiteur,t_mat_char_star_dyn *s_tabmots){
  FILE *fichier_csv=fopen(filename,"r");
  if(fichier_csv==NULL){
    printf("problème fichier\n");
    exit(EXIT_FAILURE);
  }
  char ligne[1000]={0};
  int nb_ligne=0;
  int col;
  while(fgets(ligne,1000,fichier_csv)!=NULL){
    char * token= strtok(ligne,delimiteur);
    int nb_col=0;
      while(token!=NULL){
        s_tabmots->tab[nb_ligne][nb_col]=strdup(token);
        token=strtok(NULL,delimiteur);
        col=nb_col++;
      }
      nb_ligne++;
  }
  s_tabmots->nbRows=nb_ligne+1;
  s_tabmots->nbCol=col+1;
  s_tabmots->tab=realloc(s_tabmots->tab,s_tabmots->nbRows*sizeof(char**));
  if (s_tabmots->tab==NULL){
    printf("problème d'allocation\n");
    exit(EXIT_FAILURE);
  for(int i=0;i<s_tabmots->nbRows;i++){
    s_tabmots->tab[i]=malloc(s_tabmots->nbCol*sizeof(char*));
    if (s_tabmots->tab[i]==NULL){
      printf("problème d'allocation\n");
      exit(EXIT_FAILURE);
    }
  }
  fclose(fichier_csv);
}
}
