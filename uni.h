#ifndef UNI_H
#define UNI_H
#include "main.h"
#include "util.h"

bool already_vote(int colonne,int ligne,t_mat_char_star_dyn tab_mots);

void uni1(t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean);

void uni2(t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean,t_mat_int_dyn stTab);

#endif
