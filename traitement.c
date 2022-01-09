#include "traitement.h"

void creer_t_mat_int_dyn(t_mat_int_dyn *stTab,int nbRows,int nbCol){
  stTab->tab=malloc(nbRows*sizeof(int*));
  if (stTab->tab==NULL){
    printf("problème d'allocation\n");
    exit(EXIT_FAILURE);
  }
  for(int i=0;i<nbRows;i++){
    stTab->tab[i]=malloc(nbCol*sizeof(int));
    if (stTab->tab[i]==NULL){
      printf("problème d'allocation\n");
      exit(EXIT_FAILURE);
    }
  }
  for(int i=0;i<nbRows;i++){
    for(int j=0;j<nbRows;j++){
      stTab->tab[i][j]=0;
    }
  }
  stTab->nbRows=nbRows;
  stTab->nbCol=nbCol;
}
void construct_mat_duels_d(t_mat_char_star_dyn tabmots,t_mat_int_dyn *duels_mat,int nbCandidats,bool clean){

  for(int i=0;i<nbCandidats;i++){
    for(int j=0;j<nbCandidats;j++){
      if(i!=j){
        if(clean==true){
          for(int k=1;k<tabmots.nbRows-1;k++){
            if(strtol(tabmots.tab[k][i+4],NULL,10)<strtol(tabmots.tab[k][j+4],NULL,10)) duels_mat->tab[i][j]+=1;
            }
          }
        else{
          for(int k=2;k<tabmots.nbRows-1;k++){
            if(strtol(tabmots.tab[k][i+4],NULL,10)<strtol(tabmots.tab[k][j+4],NULL,10)) duels_mat->tab[i][j]+=1;
            }
        }
        }
      }
    }
  }
void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *outfp){
  for(int i=0;i<t_tab.nbRows;i++){
    for(int j=0;j<t_tab.nbCol;j++){
      fprintf(outfp, " %d",t_tab.tab[i][j]);
    }
    fprintf(outfp, "\n" );
  }
}

char * code_candidat(int code,t_mat_char_star_dyn tabmots){
  return tabmots.tab[0][code+4];
}

char* code_candidat_d(int code,t_mat_char_star_dyn tabmots){
  return tabmots.tab[0][code];
}
