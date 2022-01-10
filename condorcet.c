#include "condorcet.h"

int condorcet(t_mat_int_dyn mat_duel){
  for(int i=0;i<mat_duel.nbCol;i++){
    bool win =true;
    for(int j=0;j<mat_duel.nbCol;j++){
      if(i!=j){
        if(mat_duel.tab[i][j]<mat_duel.tab[j][i])win =false;
      }
    }
    if (win==true){
      return i;
    }
  }
  return -1;
}

int condorcet_d(t_mat_char_star_dyn tab_mot){
  for(int i=1;i<tab_mot.nbCol;i++){
    bool win =true;
    for(int j=0;j<tab_mot.nbCol;j++){
      if(i!=j){
        if(strtol(tab_mot.tab[i][j],NULL,10)<strtol(tab_mot.tab[j][i],NULL,10))win =false;
      }
    }
    if (win==true){
      return i;
    }
  }
  return -1;
}

int minimax(liste larcs, int nbSommets,t_mat_int_dyn duel_mat){
  if(condorcet(duel_mat)!=-1) return -1;
  int candidat=0;
  int w_score=-1;
  for(int i=0;i<nbSommets;i++){
    for(int j=0;i<larcs.taille;j++){
      if(larcs.liste[j].dest==i && larcs.liste[j].poids > w_score){
        w_score=larcs.liste[j].poids;
        candidat=i;
      }
    }
  }
  return candidat;
}
