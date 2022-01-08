#include "paramètre.h"


bool is_methode(char* chaine,char* methode){
  for(int i=0;i<(int)strlen(methode);i++){
    if(chaine[i]!=methode[i]) return false;
  }
  return true;
}

void do_balise(char balise, char* next_chaine, b_o *g_para,FILE *logfp){
    if (balise == 'i'){
      if (g_para -> b_i == true || g_para -> b_d == true){
        printf("erreur il y a soit une balise en double soit 2 balise incompatible\n");
        exit(EXIT_FAILURE);
      }
      g_para -> b_i =true;
      if (is_specified_fichier(next_chaine,"csv") && exist(next_chaine) && access_lecture(next_chaine)){
        g_para -> opt_i = next_chaine;
        }
        else{
          printf("erreur argument invalide -i\n");
          exit(EXIT_FAILURE);
        }
        }


    if (balise == 'd'){
      if (g_para -> b_i == true || g_para -> b_d == true){
        printf("erreur il y a soit une balise en double soit 2 balise incompatible\n");
        exit(EXIT_FAILURE);
      }
      g_para -> b_d =true;
      if (is_specified_fichier(next_chaine,"csv") && exist(next_chaine) && access_lecture(next_chaine)){
        g_para -> opt_d = next_chaine;
      }
      else{
        printf("erreur argument invalide -d\n");
        exit(EXIT_FAILURE);
      }
      }

    if (balise == 'o'){
    if (g_para -> b_o == true){
      printf("erreur il y a dejà une balise -o\n");
      exit(EXIT_FAILURE);
    }
    g_para -> b_o =true;
    if (is_specified_fichier(next_chaine,"txt") && exist(next_chaine) && access_lecture(next_chaine) && access_write(next_chaine) && access_exec(next_chaine)){
        g_para -> opt_o = next_chaine;

    }
    else{
      printf("erreur argument invalide -o\n");
      exit(EXIT_FAILURE);
    }
    }

    if (balise == 'm'){
    if (g_para -> b_m == true){
      printf("erreur il y a dejà une balise -m\n");
      exit(EXIT_FAILURE);
    }
    g_para -> b_m =true;

      if ( g_para -> b_d == true && (next_chaine == "uni1"|| next_chaine == "uni2" ) ){
        printf("la balise -d est présente donc la méthode ne peut pas être uni1 ou uni2\n");
        exit(EXIT_FAILURE);
      }
        g_para -> opt_m = next_chaine;
  }
}


bool is_specified_fichier(char* chaine,char* extension){
  int len_chaine=strlen(chaine), len_extension = strlen(extension),index_depart=len_chaine - len_extension;
  int j=0;
  for (int i = index_depart;i<index_depart+len_extension;i++){
    if (chaine[i]!=extension[j]) return false;
    j++;
  }
  return true;
}

bool exist(char* chaine){
  if (access(chaine,F_OK)==0) return true;
  return false;
}

bool access_lecture(char* chaine){
  if (access(chaine,R_OK)==0) return true;
  return false;
}

bool access_write(char* chaine){
  if (access(chaine,W_OK)==0) return true;
  return false;
}

bool access_exec(char* chaine){
  if (access(chaine,X_OK)==0) return true;
  return false;
}
