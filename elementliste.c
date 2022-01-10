/// \file elementliste.c
/// \brief liste statique : module de définition des éléments de la liste
/// \author Vincent Dugat

#include <stdio.h>
#include <stdbool.h>
#include "global.h"
#include "elementliste.h"
#include "util.h"

void afficher_element(Elementliste e,FILE *fp){
  fprintf(fp,"(%d, %d, %d)\n", e.orig,e.dest,e.poids);
}

void saisie_element(Elementliste *e, int orig, int dest,int poids){
    e->orig=orig;
    e->dest=dest;
    e->poids=poids;
}

void copie_element(Elementliste *cible, Elementliste source){
/// \param[out] *cible (référence) reçoit l"élémént
/// \param[in] source élément à copier
    cible->orig=source.orig;
    cible->dest=source.dest;
    cible->poids=source.poids;
}

bool cmp_elements(Elementliste e1,Elementliste e2){
/// \param[in] e1 et e2
/// \return true si e1 ==e2, false sinon
    return (e1.orig==e2.orig)&&(e1.dest==e2.dest)&&(e1.poids==e2.poids);
}

void create_liste(liste* list){
  list->liste=malloc(1);
  list->taille=0;
}

void add_liste(liste* list,Elementliste e){
  list->taille+=1;
  list->liste=realloc(list->liste,list->taille*sizeof(Elementliste));
  copie_element(&list->liste[list->taille-1],e);
}

void generer_list_elem(liste* list,t_mat_int_dyn stTab){
  int origin;
  int destination;
  Elementliste e;
  for(int i=0;i<stTab.nbRows;i++){
    for(int j=0;j<stTab.nbCol;j++){
      if(stTab.tab[i][j]-stTab.tab[j][i]!=0){
        if(stTab.tab[i][j]>stTab.tab[j][i]){
          origin=i;
          destination=j;
        }
        else{
          origin=j;
          destination=i;
        }
        if(stTab.tab[i][j]-stTab.tab[j][i]<0){
          saisie_element(&e,origin,destination,(stTab.tab[i][j]-stTab.tab[j][i])*-1);
        }
        else{
          saisie_element(&e,origin,destination,stTab.tab[i][j]-stTab.tab[j][i]);
        }
        add_liste(list,e);
      }
    }
  }
}

void generer_list_elem_d(liste* list,t_mat_char_star_dyn tab_mots){
  int origin;
  int destination;
  Elementliste e;
  for(int i=0;i<tab_mots.nbCol;i++){
    for(int j=0;j<tab_mots.nbCol;j++){
      if(atoi(tab_mots.tab[i][j])-atoi(tab_mots.tab[j][i])!=0){
        if(atoi(tab_mots.tab[i][j])<atoi(tab_mots.tab[j][i])){
          origin=j;
          destination=i;
        }
        else{
          origin=i;
          destination=j;
        }

        if(atoi(tab_mots.tab[i][j])-atoi(tab_mots.tab[j][i])<0){
          saisie_element(&e,origin,destination,atoi(tab_mots.tab[j][i])-atoi(tab_mots.tab[i][j]));
        }
        else{
          saisie_element(&e,origin,destination,atoi(tab_mots.tab[i][j])-atoi(tab_mots.tab[j][i]));
        }
        add_liste(list,e);
      }
    }
  }
}
