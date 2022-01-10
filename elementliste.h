/* liste statique */
/* Vincent Dugat 2018 */

/* Pour éviter les inclusions multiples */

#ifndef ELEMENTLISTE_H
#define ELEMENTLISTE_H

#include "global.h" // définit le type t_arc_p
#include "util.h"

typedef t_arc_p Elementliste;

typedef struct list_st_arc{
  Elementliste* liste;
  int taille;
}liste;

void saisie_element(Elementliste *e, int orig, int dest,int poids);
void copie_element(Elementliste *cible, Elementliste source);
void afficher_element(Elementliste e,FILE *fp);
void create_liste(liste* list);
void add_liste(liste* list,Elementliste e);
void generer_list_elem(liste* list,t_mat_int_dyn stTab);
void generer_list_elem_d(liste* list,t_mat_char_star_dyn tab_mots);
bool cmp_elements(Elementliste e1,Elementliste e2);

#endif
