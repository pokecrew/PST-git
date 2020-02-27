#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h
int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran){
  //printf("TEst EVENEMENT\n");
  //printf("%d\n", Map[i][j].type);
  SDL_Rect position;
  SDL_Event event;
  int continuer =1;
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
    case 16://heal centre pokemon
      //printf(GREEN"[lancerEvenement]:"RESET"lancement évènement hill possible\n");
      while (continuer) {
        SDL_WaitEvent(&event);
            switch(event.type){
                case SDL_QUIT:
                    SDL_Quit();
                break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                      case SDLK_ESCAPE: // arrêter le jeu
                      continuer =0;
                      break;
                      case SDLK_UP: // Flèche haut
                      //faire regarder vers le haut
                      break;
                      case SDLK_SPACE: //
                          printf(GREEN"[lancerEvenement]:"RESET"Debut phrase heall (boite de dialogue)\n");
                          position.x = Map[0][0].position.x+4*TAILLE_SPRITE;
                          position.y = Map[0][0].position.y+2*TAILLE_SPRITE;
                          //remplissage du chariot en fonction du nombre de pokéball
                          for(int i=0; i<nbPokeJoueur; i++){
                            SDL_BlitSurface(Map_Sprites[(2057+i)], NULL, ecran, &position);
                            SDL_Flip(ecran);
                            SDL_Delay(500);
                          }
                          //clignotement
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          //2ème clignotement
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          //3ème clignotement
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2069+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2063+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(120);
                          SDL_BlitSurface(Map_Sprites[(2057+nbPokeJoueur-1)], NULL, ecran, &position);
                          SDL_Flip(ecran);
                          SDL_Delay(500);
                          printf(GREEN"[lancerEvenement]:"RESET"Fin hill\n");
                          continuer = 0;
                      break;
                      default:
                       continuer = 0;
                      break;
                    }
                }
        }
        return 0;
    break;
    default:
      return 1;
    break;
  }
}
