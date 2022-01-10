#ifndef UNI_H
#define UNI_H
#include "global.h"
#include "util.h"

bool already_vote(t_tab_int_dyn *stTab,int id);

void uni1(t_tab_int_dyn *id_votant,t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean);

void uni2(t_tab_int_dyn *id_votant,t_mat_char_star_dyn tab_mots,FILE* outfp,bool clean,t_mat_int_dyn stTab);

#endif
