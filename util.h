#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
/*struct pour encapsuler des tableaux dynamiques d'entiers avec la dimension.*/
typedef struct s_tab_dyn{
  int * tab;
  int dim;
} t_tab_int_dyn;

typedef struct s_mat_dyn{
  int ** tab;
  int nbRows;
  int nbCol;
} t_mat_int_dyn;

/*struct idem avec des chaînes de cractères*/
typedef struct s_mat_char_dyn{
  char *** tab;
  int nbRows;
  int nbCol;

} t_mat_char_star_dyn;


void affiche_tab_int(int *tab, int dim, FILE *outfp); /*affiche le tableau(non dynamique sur le fichier outfp) */

void creer_t_tab_int_dyn(t_tab_int_dyn *stTab,int dim);/*creer un tableau dynamique d'entier de longueur dim*/

void creer_t_mat_int_dyn(t_mat_int_dyn *stTab,int nbRows,int nbCol);/*creer une matrice d'entier de nbRows lignes et de nbCol colonnes*/

void creer_t_mat_char_dyn(t_mat_char_star_dyn *s_tabmots,int nbRows,int nbCol);/*creer une matrice dynamique de caractère de nbRows lignes et de nbCol colonnes*/

void affiche_t_tab_int_dyn(t_tab_int_dyn t_tab, FILE *outfp);/*affiche le tableau dynamique d'entier sur le ficher outfp*/

void affiche_t_mat_char_star_dyn(t_mat_char_star_dyn t_tabmots, FILE *outfp);/*affiche la matrice dynamique de caractère sur le ficher outfp*/

void affiche_t_mat_int_dyn(t_mat_int_dyn t_tab, FILE *outfp);/*affiche la matrice dynamique d'entier sur le ficher outfp*/

void affiche_mat_int(int **duels_mat,int nbRows,int nbCol,FILE *outfp);/*affiche la matrice (non dynamique) d'entier sur le ficher outfp*/

int max_tab_indice(int *tab, int dim);/*return l'indice maximale du tableau*/

int min_tab_indice_non_j(int *tab, int dim,int j);/*return l'indice minimale qui est différent de j du tableau*/

void read_voting_file(char * filename,const char *delimiteur,t_mat_char_star_dyn *s_tabmots);/*lis le fichier filename jusqu'au mot délimiteur et mets tout les caractères lu dans t_tabmots*/




#endif
