#include "uni.h"

void creer_t_tab_int_dyn(t_tab_int_dyn *stTab,int dim){
  stTab->tab=malloc(dim*sizeof(int));
  if (stTab->tab==NULL){
    printf("problème d'allocation\n");
    exit(EXIT_FAILURE);
  }
  stTab->dim=dim;
}


void uni1(t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean){
  int vote_courant=0;
  int max_vote=0;
  int candidat_courant=0;
  int candidat_tete =0;
  int vote_invalide=0;
  int totale_vote=0;
  for(int j=0;j<tab_mots.nbCol-4;j++){
    vote_courant=0;
    if (clean == true){
      for(int k=1;k<tab_mots.nbRows-1;k++){
        if(atoi(tab_mots.tab[k][j+4])==1){
            totale_vote++;
            vote_courant+=1;
            }
        }
      if (vote_courant>=max_vote){
        max_vote= vote_courant;
        candidat_tete=candidat_courant;
      }
      candidat_courant++;
      }
    else{
      for(int k=2;k<tab_mots.nbRows-1;k++){
        if(atoi(tab_mots.tab[k][j+4])==1){
            totale_vote;
            vote_courant+=1;
            }
        }
      if (vote_courant>=max_vote){
        max_vote= vote_courant;
        candidat_tete=candidat_courant;
      }
      candidat_courant++;
      }
      }
  fprintf(outfp,"Mode de scrutin : uninominal à un tour, %d candidats, %d votants, vainqueur= %s,score = %d%c\n\n",tab_mots.nbCol-4,tab_mots.nbRows-2,code_candidat(candidat_tete,tab_mots),((max_vote)*100)/totale_vote,'%');
}


void uni2(t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean,t_mat_int_dyn stTab){
  int totale_vote=0;
  t_tab_int_dyn id_candidat;
  creer_t_tab_int_dyn(&id_candidat,1);
  int x=0;
  int i=0;
  int vainc=-1;
  bool victoire = false;
  while(i<2){
    int vote_courant=0;
    int max_vote=0;
    int candidat_courant=0;
    int candidat_tete =0;
    int vote_invalide=0;
    for(int j=0;j<tab_mots.nbCol-4;j++){
      vote_courant=0;
      if (clean == true){
        if (j==vainc && vainc<tab_mots.nbCol-4){
          j++;
          candidat_courant++;
        }
        for(int k=1;k<tab_mots.nbRows-1;k++){
          if(atoi(tab_mots.tab[k][j+4])==1){
              totale_vote++;
              vote_courant+=1;
              }
          }
        if (vote_courant>=max_vote){
          max_vote= vote_courant;
          candidat_tete=candidat_courant;
        }
        candidat_courant++;
        }

      else{
        if (j==vainc && vainc<tab_mots.nbCol-4){
        j++;
      }
      for(int k=2;k<tab_mots.nbRows-1;k++){
        if(atoi(tab_mots.tab[k][j+4])==1){
            totale_vote++;
            vote_courant+=1;
            }
        }
      if (vote_courant>=max_vote){
        max_vote= vote_courant;
        candidat_tete=candidat_courant;
      }
      candidat_courant++;
      }
    }



    fprintf(outfp,"Mode de scrutin : uninominal à deux tour, tour 1, %d candidats, %d votants, vainqueur= %s,score = %d%c\n\n",tab_mots.nbCol-4,tab_mots.nbRows-2,code_candidat(candidat_tete,tab_mots),(max_vote*100)/totale_vote,'%');
    vainc =candidat_tete;
    id_candidat.tab[x]=vainc;
    i++;
    x++;
    if((max_vote*100)/(tab_mots.nbRows-2)>= 50){
      victoire=true;
      i=2;
    }
  }
    if(victoire==false){
      if(stTab.tab[id_candidat.tab[0]][id_candidat.tab[1]]>stTab.tab[id_candidat.tab[1]][id_candidat.tab[0]]){
        fprintf(outfp,"Mode de scrutin : uninominal à deux tour, tour 2, 2 candidats, %d votants, vainqueur= %s,score = %d%c\n\n",tab_mots.nbRows-2,code_candidat(id_candidat.tab[0],tab_mots),(stTab.tab[id_candidat.tab[0]][id_candidat.tab[1]])*100/(tab_mots.nbRows-2),'%');
      }
      if(stTab.tab[id_candidat.tab[1]][id_candidat.tab[0]]>stTab.tab[id_candidat.tab[0]][id_candidat.tab[1]]){
        fprintf(outfp,"Mode de scrutin : uninominal à deux tour, tour 2, 2 candidats, %d votants, vainqueur= %s,score = %d%c\n\n",tab_mots.nbRows-2,code_candidat(id_candidat.tab[1],tab_mots),(stTab.tab[id_candidat.tab[1]][id_candidat.tab[0]])*100/(tab_mots.nbRows-2),'%');
      }
      if(stTab.tab[id_candidat.tab[1]][id_candidat.tab[0]]==stTab.tab[id_candidat.tab[0]][id_candidat.tab[1]]){
        fprintf(outfp,"Mode de scrutin : uninominal à deux tour, tour 2, 2 candidats, %d votants, vainqueurs(égalité)= %s et %s ,score = %d%c \n\n",tab_mots.nbRows-2,code_candidat(id_candidat.tab[1],tab_mots),code_candidat(id_candidat.tab[0],tab_mots),(stTab.tab[id_candidat.tab[1]][id_candidat.tab[0]])*100/(tab_mots.nbRows-2),'%');
      }
    }

    free(id_candidat.tab);
  }
