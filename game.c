#include"include.h" //inclusion des .h nécessaires regroupés dans le fichier include.h

int lancerEvenement(Case **Map,int i, int j, Direction direction, Perso perso, SDL_Surface *ecran)
{
  //printf("TEst EVENEMENT\n");
  //printf("%d\n", Map[i][j].type);
  SDL_Rect position;
  SDL_Event event;
  int continuer =1;
  switch(Map[i][j].type)
  {
    case 2: //Hautes herbes
      lancementCombat(ecran);
      return 1;
      break;

    case 3: //rampe vers le bas
      if(direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 4: //rampe vers la droite
      if(direction == DROITE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 5: //rampe vers la gauche
      if(direction == GAUCHE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 6: //rampe vers la droite ou le bas
      if(direction == DROITE || direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 7: //rampe vers la gauche ou le bas
      if(direction == GAUCHE || direction == BAS)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 8://bord eau coin supérieur gauche
      if((direction == DROITE || direction == BAS) && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 9: //bord eau avec eau à droite
      if(direction == DROITE  && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 10: //bord eau coin inférieur gauche
      if((direction == DROITE || direction == HAUT) && surf == TRUE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 11://bord eau avec eau au dessus
      if(direction == HAUT && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 12: //bord eau coin inférieur droit
      if((direction == GAUCHE || direction == HAUT) && surf == TRUE )
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 13: //bord eau avec eau à gauche
      if(direction == GAUCHE && surf == TRUE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 14://bord eau coin supérieur droit
      if((direction == GAUCHE || direction == BAS) && surf == TRUE)
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 15://bord eau avec eau au dessous
      if(direction == BAS && surf == TRUE)
      {
        //changer skin pour surf
        return 1;
      }
      else
      {
        return 0;
      }
      break;

    case 16://heal centre pokemon
      //printf(GREEN"[lancerEvenement]:"RESET"lancement évènement hill possible\n");
      while (continuer)
      {
        SDL_WaitEvent(&event);
          switch(event.type)
          {
            case SDL_QUIT:
              SDL_Quit();
              break;

            case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                case SDLK_ESCAPE: // arrêter le jeu
                  continuer =0;
                  break;

                case SDLK_SPACE: //
                  printf(GREEN"[lancerEvenement]:"RESET"Debut phrase heall (boite de dialogue)\n");
                  position.x = Map[0][0].position.x+4*TAILLE_SPRITE;
                  position.y = Map[0][0].position.y+2*TAILLE_SPRITE;
                  Mix_PauseMusic(); //on arrête la musique
                  //remplissage du chariot en fonction du nombre de pokéball
                  for(int i=0; i<nbPokeJoueur; i++)
                  {
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
                  Mix_ResumeMusic();//on remet de la musique
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

    case 17:
      if(direction == HAUT)
      {
        printf(GREEN"[lancerEvenement]:"RESET"Panneau/Boite aux lettres\n");
      }
      return 0;
      break;

    case 18: //PNJ
      return 2;
      break;

    default:
      return 1;
      break;
  }
}

int charger_att(Att att[4], int id_att[4]){
  FILE *fic = NULL;
  fic = fopen("Ressources/Attaques","r");
  char TAB[120];
  char type_temp[10]= {' '};
  fgets(TAB, 119, fic);
  int attaques_chargees = 0;
  int attaques_a_charger = 4;
  //Calcul du nombre d'attaques à charger
  for(int i=0; i<4; i++){
    //printf("%d \n",id_att[i]);
    if(id_att[i] == 0){
      attaques_a_charger--;
    }
  }
//  printf(GREEN"[charger_att]:"RESET" attaques_a_charger = %d \n",attaques_a_charger);
  int id_f = 0;
  while(attaques_chargees != attaques_a_charger){
    //recupère l'id en cours
    fgets(TAB, 119, fic);
    id_f =	(TAB[0]-'0')*100 + (TAB[1]-'0')*10 + TAB[2]-'0';
    for(int i = 0; i<4; i++){
      if(id_att[i] == id_f){
          //chargement id Attaque
          att[i].id = id_f;
          //printf(GREEN"[charger_att]:"RESET"att[%d].id : %d\n",i, id_f);

          //chargement nom Attaque
          for(int j=0; j<17; j++){ //pour chaque caractère
            if(TAB[4+j] == ' '){//Si il s'agit d'un espace, on affecte 17 à j, ce qui sort de la boucle;
              att[i].nom[j]='\0';
              j=17;
            }
            else if(TAB[4+j] == '_'){ //si c'est un underscore on affiche espace
              att[i].nom[j] = ' ';
            }
            else{
              att[i].nom[j] = TAB[4+j]; //sinon on charge le caractère correspondant
            }
          }
          //printf(GREEN"[charger_att]:"RESET"att[%d].nom : %s\n",i, att[i].nom);

          //chargement type Attaque
          for(int k=0; k<8; k++){
            type_temp[k]=TAB[21+k];
          }
          if(strstr(type_temp, "combat") != NULL){
            att[i].type = COMBAT;
          }
          else if(strstr(type_temp, "eau") != NULL){
            att[i].type = EAU;
          }
          else if(strstr(type_temp, "electrik") != NULL){
            att[i].type = ELEC;
          }
          else if(strstr(type_temp, "feu") != NULL){
            att[i].type = FEU;
          }
          else if(strstr(type_temp, "glace") != NULL){
            att[i].type = GLACE;
          }
          else if(strstr(type_temp, "insecte") != NULL){
            att[i].type = INSECTE;
          }
          else if(strstr(type_temp, "plante") != NULL){
            att[i].type = PLANTE;
          }
          else if(strstr(type_temp, "poison") != NULL){
            att[i].type = POISON;
          }
          else if(strstr(type_temp, "psy") != NULL){
            att[i].type = PSY;
          }
          else if(strstr(type_temp, "roche") != NULL){
            att[i].type = ROCHE;
          }
          else if(strstr(type_temp, "sol") != NULL){
            att[i].type = GROUND;
          }
          else if(strstr(type_temp, "spectre") != NULL){
            att[i].type = SPECTRE;
          }
          else if(strstr(type_temp, "vol") != NULL){
            att[i].type = VOL;
          }
          else{
            att[i].type = NORMAL;
          }
        //  printf(GREEN"[charger_att]:"RESET"att[%d].type : %s\n",i, type_temp);

          //chargement classe Attaque
          att[i].classe = (TAB[30] == 'P')? 0 : 1;

          //chargement puissance attaque
          att[i].puissance =	(TAB[42]-'0')*100 + (TAB[43]-'0')*10 + TAB[44]-'0';

          //chargement précision attaque
          att[i].precision =	(TAB[48]-'0')*100 + (TAB[49]-'0')*10 + TAB[50]-'0';

          //chargement pp_max attaque
          att[i].pp_max =	(TAB[54]-'0')*10 + TAB[55]-'0';
          attaques_chargees++;//on augmente le compteur d'attaques chargées
      }
    }
  }
}
