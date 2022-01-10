#ifndef CONCORDET_H
#define CONCORDET_H
#include "util.h"
#include "main.h"


int condorcet(t_mat_int_dyn mat_duel);/*réalise la méthode de condorcet et retourne le vainqueur de condorcet)*/
int condorcet_d(t_mat_char_star_dyn tab_mot);
int minimax(liste larcs, int nbSommets,t_mat_int_dyn duel_mat);/*réalise la méthode minmax pour résoudre le paradox de concordet*/
int schulze(t_mat_int_dyn duels_mat,FILE *outfp);/*réalise la méthode schulze pour résoudre le paradox de concordet*/
#endif
