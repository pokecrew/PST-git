#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h
int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran){
  //printf("TEst EVENEMENT\n");
  //printf("%d\n", Map[i][j].type);
  switch(Map[i][j].type){
    case 2: //Hautes herbes
      lancementCombat(ecran);
      return 1;
    break;
    case 3: //rampe vers le bas
        if(direction == BAS){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 4: //rampe vers la droite
        if(direction == DROITE){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 5: //rampe vers la gauche
        if(direction == GAUCHE){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 6: //rampe vers la droite ou le bas
        if(direction == DROITE || direction == BAS){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 7: //rampe vers la gauche ou le bas
        if(direction == GAUCHE || direction == BAS){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 8://bord eau coin supérieur gauche
      if((direction == DROITE || direction == BAS) && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    case 9: //bord eau avec eau à droite
      if(direction == DROITE  && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    case 10: //bord eau coin inférieur gauche
        if((direction == DROITE || direction == HAUT) && surf == TRUE){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 11://bord eau avec eau au dessus
      if(direction == HAUT && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    case 12: //bord eau coin inférieur droit
      if((direction == GAUCHE || direction == HAUT) && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    case 13: //bord eau avec eau à gauche
        if(direction == GAUCHE && surf == TRUE){
          return 1;
        }
        else{
          return 0;
        }
    break;
    case 14://bord eau coin supérieur droit
      if((direction == GAUCHE || direction == BAS) && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    case 15://bord eau avec eau au dessous
      if(direction == BAS && surf == TRUE ){
        //changer skin pour surf
        return 1;
      }
      else{
        return 0;
      }
    break;
    default:
      return 1;
    break;
  }
}
