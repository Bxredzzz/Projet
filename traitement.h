#ifndef TRAITEMENT_H
#define TRAITEMENT_H
#include"lecture_csv.h"
#include "util.h"

char * code_candidat(int code,t_mat_char_star_dyn tabmots);/*return le candidat ayant pour code int code"*/
char * code_candidat_d(int code,t_mat_char_star_dyn tabmots);
void construct_mat_duels_d(t_mat_char_star_dyn tabmots,t_mat_int_dyn *duels_mat,int nbCandidats,bool clean);/* construit une matrice de duels dans duel_mat*/


#endif
